#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include "nlohmann/json.hpp"
#include "GameView.h"

namespace QuoridorUtils {

class ConsoleView final : public QuoridorUtils::GameView {
private:
    char me = 'A';
    char enemy = 'V';
    std::string myColor = "\x1B[31m";
    std::string enemyColor = "\x1B[34m";
    const std::string colorStop = "\033[0m";
    const char myBlockH = '\x21';
    const char myBlockV = '\x22';
    const char enemyBlockH = '\x23';
    const char enemyBlockV = '\x24';
    char chessmanPlaceholder = '!';
    char intersection = '*';
    char gapH = ' ';
    char gapV = ' ';
    char blockH = '-';
    char blockV = '|';
    char** map = nullptr;
    unsigned short w = 0;
    unsigned short h = 0;
    std::vector<char**> stepMaps;
    std::vector<std::tuple<std::string, QuoridorUtils::Step, QuoridorUtils::GameStatus>> stepHistories;
    std::vector<std::pair<Location, Location>> stepChessman;
    std::string playerName[2];
    unsigned int currentMapIndex = 0;
    std::unordered_map<Location, std::pair<short, short>, LocationHash> chessmanLocal;      // 棋盘棋子坐标转map坐标 
    std::unordered_map<Location, std::pair<short, short>, LocationHash> intersectionLocal;  // 棋盘角点坐标转map坐标
    char** copyMap(char** src = nullptr) const;
    bool readMapFromFile(const std::string& mapFilename);
    void refreshView(char** map = nullptr);
    void refreshInfo() const;
    void generateMapTable();

public:
    ConsoleView(const std::string& mapFilename);
    ConsoleView(const nlohmann::json& displayConfig);
    ~ConsoleView();
    void playerRegister(const std::string& firstPlayer, const std::string& secondPlayer) override;
    bool putStep(const std::string& playerName, const QuoridorUtils::Step& nextStep, 
                 const QuoridorUtils::GameStatus& status) override;
    bool showPrevStep() override;
    bool showNextStep() override;
};
}
