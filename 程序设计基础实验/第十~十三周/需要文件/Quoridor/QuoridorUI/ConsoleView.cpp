#include "ConsoleView.h"
#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif

std::string trim(const std::string& s) {
    size_t startPos = 0;
    auto stopPos = s.length();
    for (auto c : s) {
        if (std::isspace(c)) {
            startPos++;
        } else {
            break;
        }
    }
    for (int i = s.length(); i > 0; i--) {
        if (std::isspace(s[i - 1])) {
            stopPos--;
        } else {
            break;
        }
    }
    if (stopPos > startPos) {
        return s.substr(startPos, stopPos - startPos);
    } else {
        return "";
    }
}

#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
inline void consoleGoto(const std::pair<short, short> loc) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ loc.first, loc.second});
}

inline void consoleGoto(const short x, const short y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{x, y});
}

inline void consoleClear() {
    system("cls");
}
#elif defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
inline void consoleGoto(const std::pair<short, short> loc) {
    printf("\033[%d;%dH", loc.second + 1, loc.first);
}

inline void consoleGoto(const short x, const short y) {
    printf("\033[%d;%dH", y + 1, x);
}

inline void consoleClear() {
    system("clear");
}
#endif

namespace QuoridorUtils {

bool ConsoleView::readMapFromFile(const std::string& mapFilename) {
    std::ifstream mapFile(mapFilename);
    if (!mapFile.is_open()) {
        return false;
    }
    std::vector<std::string> buffer;
    unsigned int maxLen = 0;
    while (!mapFile.eof()) {
        std::string line;
        std::getline(mapFile, line);
        line = trim(line);
        if (!line.empty()) {
            buffer.push_back(line);
            if (line.length() > maxLen) {
                maxLen = line.length();
            }
        }
    }
    mapFile.close();
    this->map = new char* [buffer.size()];
    if (this->map) {
        for (unsigned int i = 0; i < buffer.size(); i++) {
            this->map[i] = new char[maxLen];
            assert(maxLen >= buffer[i].length());
            std::memcpy(this->map[i], buffer[i].data(), buffer[i].length());
        }
    }
    this->w = maxLen;
    this->h = buffer.size();
    return true;
}

ConsoleView::ConsoleView(const std::string& mapFilename) {
    if (!readMapFromFile(mapFilename)) {
        std::cout << "Can't find panel file: " << mapFilename << std::endl;
        exit(-1);
    }
    generateMapTable();
    consoleClear();
    refreshView();
}

ConsoleView::ConsoleView(const nlohmann::json& displayConfig) {
    this->me = displayConfig.value("me", "A").at(0);
    this->enemy = displayConfig.value("enemy", "Y").at(0);
    this->chessmanPlaceholder = displayConfig.value("chessmanPlaceholder", "!").at(0);
    this->intersection = displayConfig.value("intersection", "*").at(0);
    this->gapH = displayConfig.value("gapH", " ").at(0);
    this->gapV = displayConfig.value("gapV", " ").at(0);
    this->blockH = displayConfig.value("blockH", "-").at(0);
    this->blockV = displayConfig.value("blockV", "|").at(0);
    const auto myColorCode = displayConfig.value("myColorCode", 31);
    const auto enemyColorCode = displayConfig.value("enemyColorCode", 34);
    myColor.clear();
    myColor.append("\x1B[");
    myColor.append(std::to_string(myColorCode));
    myColor.append("m");
    enemyColor.clear();
    enemyColor.append("\x1B[");
    enemyColor.append(std::to_string(enemyColorCode));
    enemyColor.append("m");
    if (!readMapFromFile(displayConfig.value("panelFile", "panel.txt"))) {
        std::cout << "Can't find panel file: " << displayConfig.value("panelFile", "panel") << std::endl;
        exit(-1);
    }
    generateMapTable();
    consoleClear();
    refreshView();
}

void ConsoleView::generateMapTable() {
    int chessmanX = 1;
    auto chessmanY = QuoridorUtils::SIZE;
    int intersectionX = 0;
    auto intersectionY = QuoridorUtils::SIZE;
    for (unsigned short i = 0; i < this->h; i++) {
        for (unsigned short j = 0; j < this->w; j++) {
            if (this->map[i][j] == this->intersection) {
                this->intersectionLocal[Location(intersectionX, intersectionY)] =
                    std::pair<short, short>(i, j);
                intersectionX++;
                if (intersectionX > QuoridorUtils::SIZE) {
                    intersectionY--;
                    intersectionX = 0;
                }
            } else if (this->map[i][j] == this->chessmanPlaceholder) {
                this->map[i][j] = ' ';
                this->chessmanLocal[Location(chessmanX, chessmanY)] = 
                    std::pair<short, short>(i, j);
                chessmanX++;
                if (chessmanX > QuoridorUtils::SIZE) {
                    chessmanY--;
                    chessmanX = 1;
                }
            }
        }
    }
}

char** ConsoleView::copyMap(char** src) const {
    if (src == nullptr) {
        src = this->map;
    }
    char** des = new char* [this->h];
    if (des) {
        for (unsigned int i = 0; i < this->h; i++) {
            des[i] = new char[this->w];
            if (des[i]) {
                std::memcpy(des[i], src[i], this->w);
            } else {
                std::cout << "Memory error!" << std::endl;
                exit(-1);
            }
        }
    } else {
        std::cout << "Memory error!" << std::endl;
        exit(-1);
    }
    return des;
}

void ConsoleView::refreshView(char** map) {
    if (map == nullptr && this->stepMaps.empty() && this->stepChessman.empty()) {
        const auto initialMap = copyMap();
        initialMap[this->chessmanLocal[PLAYER0_LOC].first][this->chessmanLocal[PLAYER0_LOC].second] = this->me;
        initialMap[this->chessmanLocal[PLAYER1_LOC].first][this->chessmanLocal[PLAYER1_LOC].second] = this->enemy;
        this->stepMaps.push_back(initialMap);
        this->stepChessman.emplace_back(PLAYER0_LOC, PLAYER1_LOC);
        map = this->stepMaps.back();
    } else if (map == nullptr) {
        return;
    }
    consoleGoto(0, 0);
    for (unsigned int i = 0; i < this->h; i++) {
        std::string tmp;
        //tmp.append(map[i], w);
        for (unsigned int j = 0; j < this->w; j++) {
            if (map[i][j] == this->me) {
                tmp.append(this->myColor);
                tmp.append(1, this->me);
                tmp.append(this->colorStop);
            } else if (map[i][j] == this->enemy) {
                tmp.append(this->enemyColor);
                tmp.append(1, this->enemy);
                tmp.append(this->colorStop);
            } else if (map[i][j] == this->myBlockH) {
                tmp.append(this->myColor);
                tmp.append(1, this->blockH);
                tmp.append(this->colorStop);
            } else if (map[i][j] == this->myBlockV) {
                tmp.append(this->myColor);
                tmp.append(1, this->blockV);
                tmp.append(this->colorStop);
            } else if (map[i][j] == this->enemyBlockH) {
                tmp.append(this->enemyColor);
                tmp.append(1, this->blockH);
                tmp.append(this->colorStop);
            } else if (map[i][j] == this->enemyBlockV) {
                tmp.append(this->enemyColor);
                tmp.append(1, this->blockV);
                tmp.append(this->colorStop);
            } else {
                tmp.append(1, map[i][j]);
            }
        }
        std::cout << tmp << std::endl;
    }
    refreshInfo();
}

void ConsoleView::refreshInfo() const {
    consoleGoto(0, short(this->h));
    if (this->stepHistories.empty() || this->currentMapIndex <= 0) {
        std::cout << "\33[2K" << "start game!" << std::endl
                  << "\33[2K" << this->myColor << this->playerName[0] << this->colorStop << ": " << PLAYER0_LOC << "; "
                  << this->enemyColor << this->playerName[1] << this->colorStop << ": " << PLAYER1_LOC << std::endl;
    } else if (this->currentMapIndex > 0) {
        auto playerColor = this->myColor;
        if (std::get<0>(this->stepHistories[this->currentMapIndex - 1]) == this->playerName[1]) {
            playerColor = this->enemyColor;
        }
        std::cout << "\33[2K" << "step: " << this->currentMapIndex << '/' << this->stepHistories.size() << ", "
                  << "player: " << playerColor
                                << std::get<0>(this->stepHistories[this->currentMapIndex - 1])
                                << this->colorStop << ", " << std::endl
                  << "\33[2K" << std::get<1>(this->stepHistories[this->currentMapIndex - 1]) << ", "
                  << "status: " << std::get<2>(this->stepHistories[this->currentMapIndex - 1]) << std::endl;
    }
}

void ConsoleView::playerRegister(const std::string& firstPlayer, const std::string& secondPlayer) {
    this->playerName[0] = firstPlayer;
    this->playerName[1] = secondPlayer;
    refreshInfo();
}

bool ConsoleView::putStep(const std::string& playerName, const QuoridorUtils::Step& nextStep, 
                          const QuoridorUtils::GameStatus& status) {
    char blockTempH = 0;
    char blockTempV = 0;
    if (playerName == this->playerName[0]) {
        blockTempH = this->myBlockH;
        blockTempV = this->myBlockV;
    } else if (playerName == this->playerName[1]) {
        blockTempH = this->enemyBlockH;
        blockTempV = this->enemyBlockV;
    } else {
        return false;
    }
    char** newMap = copyMap(this->stepMaps.back());
    bool refreshMap = false;
    switch (status) {
    case GameStatus::Ok: 
    case GameStatus::Win: 
    case GameStatus::Lost: 
    case GameStatus::EnemyClosed: 
    case GameStatus::None: 
        refreshMap = true;
        break;
    case GameStatus::RulesBreaker: 
    case GameStatus::InsufficientBlock: 
    case GameStatus::InvalidStep: 
    case GameStatus::Timeout: 
        refreshMap = false;
        break;
    }
    if (refreshMap) {
        // 改变棋子位置 
        const auto oldChessLoc = this->stepChessman.back();
        if (nextStep.isMove()) {
            std::pair<Location, Location> newChessLoc;
            newMap[this->chessmanLocal[oldChessLoc.first].first][this->chessmanLocal[oldChessLoc.first].second] = ' ';
            newMap[this->chessmanLocal[oldChessLoc.second].first][this->chessmanLocal[oldChessLoc.second].second] = ' ';
            if (playerName == this->playerName[0]) {
                newChessLoc.first = nextStep.myNewLoc;
                newChessLoc.second = oldChessLoc.second;
                newMap[this->chessmanLocal[newChessLoc.second].first][this->chessmanLocal[newChessLoc.second].second] = this->enemy;
                newMap[this->chessmanLocal[newChessLoc.first].first][this->chessmanLocal[newChessLoc.first].second] = this->me;
            } else if (playerName == this->playerName[1]) {
                newChessLoc.first = oldChessLoc.first;
                newChessLoc.second = nextStep.myNewLoc;
                newMap[this->chessmanLocal[newChessLoc.first].first][this->chessmanLocal[newChessLoc.first].second] = this->me;
                newMap[this->chessmanLocal[newChessLoc.second].first][this->chessmanLocal[newChessLoc.second].second] = this->enemy;
            }
            this->stepChessman.push_back(newChessLoc);
        } else {
            this->stepChessman.push_back(oldChessLoc);
        }
        // 添加挡板 
        if (!nextStep.myNewBlockBar.isNan() && !nextStep.isMove()) {  // 必须是没有移动且挡板数据不为空 
            // 注意, 游戏坐标与其图形坐标x,y颠倒 
            auto startPoint = this->intersectionLocal[nextStep.myNewBlockBar.start];
            auto stopPoint = this->intersectionLocal[nextStep.myNewBlockBar.stop];
            if (nextStep.myNewBlockBar.isH()) {  // 水平 
                const short x = startPoint.first;
                const short yMin = startPoint.second < stopPoint.second ? startPoint.second : stopPoint.second;
                const short yMax = startPoint.second > stopPoint.second ? startPoint.second : stopPoint.second;
                for (short i = yMin; i < yMax; i++) {
                    if (newMap[x][i] == this->gapH) {
                        //newMap[x][i] = this->blockH;
                        newMap[x][i] = blockTempH;
                    }
                }
            } else if (nextStep.myNewBlockBar.isV()) {  // 水平 
                const short y = startPoint.second;
                const short xMin = startPoint.first < stopPoint.first ? startPoint.first : stopPoint.first;
                const short xMax = startPoint.first > stopPoint.first ? startPoint.first : stopPoint.first;
                for (short i = xMin; i < xMax; i++) {
                    if (newMap[i][y] == this->gapV) {
                        //newMap[i][y] = this->blockV;
                        newMap[i][y] = blockTempV;
                    }
                }
            }
        }
    } else {
        if (this->stepChessman.empty()) {
            this->stepChessman.emplace_back(PLAYER0_LOC, PLAYER1_LOC);
        } else {
            this->stepChessman.emplace_back(this->stepChessman.back());
        }
    }
    this->stepMaps.push_back(newMap);
    this->stepHistories.emplace_back(playerName, nextStep, status);
    return true;
}

bool ConsoleView::showPrevStep() {
    if (this->currentMapIndex == 0) {  // don't have enough map
        if (!this->stepMaps.empty()) {
            refreshView(this->stepMaps[0]);
        }
        return false;
    } else {
        this->currentMapIndex--;
        refreshView(this->stepMaps[this->currentMapIndex]);
        return true;
    }
}

bool ConsoleView::showNextStep() {
    if (this->currentMapIndex >= this->stepMaps.size() - 1) {  // don't have enough map
        return false;
    } else {
        this->currentMapIndex++;
        refreshView(this->stepMaps[this->currentMapIndex]);
        return true;
    }
}

ConsoleView::~ConsoleView() {
    if (this->map) {
        std::free(this->map);
    }
    for (auto p : this->stepMaps) {
        for (unsigned int i = 0; i < this->h; i++) {
            std::free(p[i]);
        }
        std::free(p);
    }
}
}
