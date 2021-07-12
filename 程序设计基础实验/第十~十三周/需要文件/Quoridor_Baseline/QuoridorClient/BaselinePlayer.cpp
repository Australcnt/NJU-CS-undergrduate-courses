#include "BaselinePlayer.h"
#include <iostream>
#include <unordered_set>

namespace QuoridorUtils {

// �������ݽṹά������, �����ʼ������. 
void BaselinePlayer::chessboardInit() {
    for (int i = 1; i <= QuoridorUtils::SIZE; i++) {
        for (int j = 1; j <= QuoridorUtils::SIZE; j++) {
            this->chessboard[Location(i, j)] = Doors();
            if (i == 1) {
                this->chessboard[Location(i, j)].left = false;
            } else if (i == 9) {
                this->chessboard[Location(i, j)].right = false;
            }
            if (j == 1) {
                this->chessboard[Location(i, j)].down = false;
            } else if (j == 9) {
                this->chessboard[Location(i, j)].up = false;
            }
        }
    }
}

// �������ݽṹά������, ������Ӻ�ɾ������. 
void BaselinePlayer::addOrDelBlock(const BlockBar& block, const bool isDel) {
    if (block.isNan()) {
        return;
    }
    if (block.isH() && block.start.y > 0 && block.start.y < SIZE) {
        // eg: ((0,1), (2,1)) will block (1,1) u, (2,1) u (1,2) d, (2,2) d
        auto stopLoc = block.start.x > block.stop.x ? block.start : block.stop;
        this->chessboard[stopLoc].up = isDel;
        stopLoc.x--;
        this->chessboard[stopLoc].up = isDel;
        stopLoc = block.start.x > block.stop.x ? block.start : block.stop;
        stopLoc.y++;
        this->chessboard[stopLoc].down = isDel;
        stopLoc.x--;
        this->chessboard[stopLoc].down = isDel;
    } else if (block.isV() && block.start.x > 0 && block.start.x < SIZE) {
        // eg: ((2,1), (2,3)) will block (2,2) r, (2,3) r (3,2) l, (3,3) l
        auto stopLoc = block.start.y > block.stop.y ? block.start : block.stop;
        this->chessboard[stopLoc].right = isDel;
        stopLoc.y--;
        this->chessboard[stopLoc].right = isDel;
        stopLoc = block.start.x > block.stop.x ? block.start : block.stop;
        stopLoc.x++;
        this->chessboard[stopLoc].left = isDel;
        stopLoc.y--;
        this->chessboard[stopLoc].left = isDel;
    }
}

// ע��: ����� enemyLoc ����ʵ�ֿ��ǶԷ��������������·��, ��δ��ʵ��.
// �ú���Ϊ���㷨���� BFS, ���Լ��㴫��� myLoc �ڵ�ǰ�����µ��� myTargetY ����̾�������·��.
// ���·��ͨ������ path ����, �ö�����ÿ��Ԫ��Ϊ <����, ������ myLoc ����̾���>.
// path �д洢��·������������, ���ܱ�ʾ����·��, ��ע����. 
int BaselinePlayer::minDistancePath(const Location& myLoc, const Location& enemyLoc, 
                                    const int myTargetY, std::queue<std::pair<Location, int>>& path) {
    while (!path.empty()) {
        path.pop();
    }
    if (myLoc.y == myTargetY) {
        return 0;
    }
    // BFS Ѱ�����·�� 
    std::vector<std::vector<int>> minDistanceMatrix(SIZE, std::vector<int>(SIZE, -1));
    minDistanceMatrix[myLoc.x - 1][myLoc.y - 1] = 0;
    //minDistanceMatrix[enemyLoc.x][enemyLoc.y] = -2;
    auto returnMinDistance = INT32_MAX;
    std::queue<std::pair<Location, int>> nextLocations;
    nextLocations.emplace(myLoc, 0);  // �տ�ʼ����е�0�� 
    std::queue<std::pair<Location, int>> tmpPath;
    while(!nextLocations.empty()) {
        const auto tmp = nextLocations.front();
        nextLocations.pop();
        if (tmp.first.y == myTargetY && (returnMinDistance == INT32_MAX || returnMinDistance == tmp.second)) {
            returnMinDistance = tmp.second;
            tmpPath.emplace(tmp);
            path.emplace(tmp);
            continue;
        } else if (returnMinDistance == INT32_MAX) {
            if (this->chessboard[tmp.first].up && minDistanceMatrix[tmp.first.x - 1][tmp.first.y] == -1) {     // ���������� 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y] = tmp.second + 1;
                nextLocations.emplace(Location(tmp.first.x, tmp.first.y + 1), tmp.second + 1);
            }
            if (this->chessboard[tmp.first].down && minDistanceMatrix[tmp.first.x - 1][tmp.first.y - 2] == -1) {   // ���������� 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y - 2] = tmp.second + 1;
                nextLocations.emplace(Location(tmp.first.x, tmp.first.y - 1), tmp.second + 1);
            }
            if (this->chessboard[tmp.first].right && minDistanceMatrix[tmp.first.x][tmp.first.y - 1] == -1) {  // ���������� 
                minDistanceMatrix[tmp.first.x][tmp.first.y - 1] = tmp.second + 1;
                nextLocations.emplace(Location(tmp.first.x + 1, tmp.first.y), tmp.second + 1);
            }
            if (this->chessboard[tmp.first].left && minDistanceMatrix[tmp.first.x - 2][tmp.first.y - 1] == -1) {   // ���������� 
                minDistanceMatrix[tmp.first.x - 2][tmp.first.y - 1] = tmp.second + 1;
                nextLocations.emplace(Location(tmp.first.x - 1, tmp.first.y), tmp.second + 1);
            }
        }
    }
    if (returnMinDistance != INT32_MAX) {  // �ɴ�������� 
        while (!tmpPath.empty()) {
            const auto tmp = tmpPath.front();
            tmpPath.pop();
            if (tmp.second == 1) {
                continue;
            }
            if (this->chessboard[tmp.first].up &&
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y] == tmp.second - 1) {  // �������ϻ��� 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y] = -1;                 // ��ֹ������� 
                path.emplace(Location(tmp.first.x, tmp.first.y + 1), tmp.second - 1);
                tmpPath.emplace(path.back());
            }
            if (this->chessboard[tmp.first].down && 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y - 2] == tmp.second - 1) {  // �������»��� 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y - 2] = -1;
                path.emplace(Location(tmp.first.x, tmp.first.y - 1), tmp.second - 1);
                tmpPath.emplace(path.back());
            }
            if (this->chessboard[tmp.first].right && 
                minDistanceMatrix[tmp.first.x][tmp.first.y - 1] == tmp.second - 1) {  // �������һ��� 
                minDistanceMatrix[tmp.first.x][tmp.first.y - 1] = -1;
                path.emplace(Location(tmp.first.x + 1, tmp.first.y), tmp.second - 1);
                tmpPath.emplace(path.back());
            }
            if (this->chessboard[tmp.first].left && 
                minDistanceMatrix[tmp.first.x - 2][tmp.first.y - 1] == tmp.second - 1) {  // ����������� 
                minDistanceMatrix[tmp.first.x - 2][tmp.first.y - 1] = -1;
                path.emplace(Location(tmp.first.x - 1, tmp.first.y), tmp.second - 1);
                tmpPath.emplace(path.back());
            }
        }
    }
    return returnMinDistance;
}

// ��ǰ��õķŰ巽��, ���� INT32_MIN ��ʾ�Ű廹���粻��. 
BlockBar BaselinePlayer::bestBlockBar(const Location& myLoc, const Location& enemyLoc, 
                                      std::queue<std::pair<Location, int>>& myPath,
                                      std::queue<std::pair<Location, int>>& enemyPath) {
    // �ҷ�·������ -1, �з�·������ +2, �����Լ�, ��������  
    std::vector<std::vector<int>> profitMatrix(SIZE, std::vector<int>(SIZE, -1));
    profitMatrix[myLoc.x - 1][myLoc.y - 1] -= 1;
    profitMatrix[enemyLoc.x - 1][enemyLoc.y - 1] += 2;
    while (!myPath.empty()) {
        const auto tmp = myPath.front();
        myPath.pop();
        profitMatrix[tmp.first.x - 1][tmp.first.y - 1] -= 1;
    }
    while (!enemyPath.empty()) {
        const auto tmp = enemyPath.front();
        enemyPath.pop();
        profitMatrix[tmp.first.x - 1][tmp.first.y - 1] += 2;
    }
    std::unordered_set<BlockBar, BlockBarHash> candidateBlocks;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (profitMatrix[i][j] >= 0) {
                candidateBlocks.insert(BlockBar(i, j - 1, i, j + 1));
                candidateBlocks.insert(BlockBar(i, j, i, j + 2));
                candidateBlocks.insert(BlockBar(i + 1, j - 1, i + 1, j + 1));
                candidateBlocks.insert(BlockBar(i + 1, j, i + 1, j + 2));
                candidateBlocks.insert(BlockBar(i - 1, j, i + 1, j));
                candidateBlocks.insert(BlockBar(i, j, i + 2, j));
                candidateBlocks.insert(BlockBar(i - 1, j + 1, i + 1, j + 1));
                candidateBlocks.insert(BlockBar(i, j + 1, i + 2, j + 1));
            }
        }
    }
    int maxDistanceDiff = INT32_MIN;
    BlockBar bestBlock;
    for (const auto block : candidateBlocks) {
        const int tmpDistanceDiff = simulateBlockBar(myLoc, enemyLoc, block);
        if (tmpDistanceDiff != INT32_MIN) {
            if (tmpDistanceDiff > maxDistanceDiff) {
                maxDistanceDiff = tmpDistanceDiff;
                bestBlock = block;
            }
        }
    }
    return bestBlock;
}

// ģ���һ������, ����Ű�֮��˫����·������֮��. ���� INT32_MIN ��ʾ�Ű�Υ��. 
int BaselinePlayer::simulateBlockBar(const Location& myLoc, const Location& enemyLoc,
                                     const BlockBar& fakeBlock) {
    if (fakeBlock.isNan()) {
        return INT32_MIN;
    }
    if (fakeBlock.isH() && fakeBlock.start.y > 0 && fakeBlock.start.y < SIZE) {  // y��ͬ 
        // eg. ((0,1), (2,1)) will block (1,1) u, (2,1) u (1,2) d, (2,2) d
        const auto stopLoc = fakeBlock.start.x > fakeBlock.stop.x ? fakeBlock.start : fakeBlock.stop;
        if (!(this->chessboard[stopLoc].up && this->chessboard[Location(stopLoc.x - 1, stopLoc.y)].up && 
              this->chessboard[Location(stopLoc.x, stopLoc.y + 1)].down && 
              this->chessboard[Location(stopLoc.x - 1, stopLoc.y + 1)].down)) {
            return INT32_MIN;
        }// else if (!this->chessboard[stopLoc].left && !this->chessboard[Location(stopLoc.x - 1, stopLoc.y)].right && 
        //           !this->chessboard[Location(stopLoc.x, stopLoc.y + 1)].left && 
        //           !this->chessboard[Location(stopLoc.x - 1, stopLoc.y + 1)].right) {  // ���ܽ��� 
        //    return INT32_MIN;
        //}
    } else if (fakeBlock.isV() && fakeBlock.start.x > 0 && fakeBlock.start.x < SIZE) {  // x��ͬ 
        // eg. ((2,1), (2,3)) will block (2,2) r, (2,3) r (3,2) l, (3,3) l
        const auto stopLoc = fakeBlock.start.y > fakeBlock.stop.y ? fakeBlock.start : fakeBlock.stop;
        if (!(this->chessboard[stopLoc].right && this->chessboard[Location(stopLoc.x, stopLoc.y - 1)].right &&
              this->chessboard[Location(stopLoc.x + 1, stopLoc.y)].left &&
              this->chessboard[Location(stopLoc.x + 1, stopLoc.y - 1)].left)) {
            return INT32_MIN;
        }// else if (!this->chessboard[stopLoc].down && !this->chessboard[Location(stopLoc.x, stopLoc.y - 1)].up &&
        //           !this->chessboard[Location(stopLoc.x + 1, stopLoc.y)].down &&
        //           !this->chessboard[Location(stopLoc.x + 1, stopLoc.y - 1)].up) {
        //    return INT32_MIN;
        //}
    } else {
        return INT32_MIN;
    }
    std::queue<std::pair<Location, int>> uselessPath;
    addOrDelBlock(fakeBlock);
    const auto beforeMyDistance = minDistancePath(myLoc, enemyLoc, SIZE - this->myInitLoc.y + 1, uselessPath);
    const auto beforeEnemyDistance = minDistancePath(enemyLoc, myLoc, this->myInitLoc.y, uselessPath);
    addOrDelBlock(fakeBlock, true);
    if (beforeMyDistance == INT32_MAX || beforeEnemyDistance == INT32_MAX) {
        return INT32_MIN;
    }
    return beforeEnemyDistance - beforeMyDistance;
}

// ������õ������ƶ�λ��, �����·�� myPath ��ȡ��,
// �ڻ���Υ�����������¿��ܷ��� (-1, -1), ��ʾ�ƶ������粻��.  
Location BaselinePlayer::bestMove(const Location& myLoc, const Location& enemyLoc, std::queue<std::pair<Location, int>>& myPath) {
    Location bestNextLoc;
    if (myLoc.distance(enemyLoc) == 1) {  // ������Ծ 
        std::vector<std::pair<Location, int>> tmpPath;  // �洢�ҷ����·����2���ɴ�λ�� 
        bool blocked = true;
        while (!myPath.empty()) {
            const auto tmp = myPath.front();
            myPath.pop();
            if (tmp.second >= 3) {
                continue;
            }
            if (tmp.first == enemyLoc && tmp.second == 1) {  // ����֮���޵���, �����·����1�������Է����� 
                blocked = false;
            }
            tmpPath.emplace_back(tmp);
        }
        if (blocked) {  // ����֮���е���, �ض�������, ��ʱstep����һ���ض����� 
            for (const auto tmp : tmpPath) {
                if (tmp.second == 1) {
                    bestNextLoc = tmp.first;
                    break;
                }
            }
        } else {  // ����֮���޵���, �����·�������Է����� 
            Location jump;
            if (myLoc.x == enemyLoc.x) {  // ������ 
                jump.x = myLoc.x;
                jump.y = enemyLoc.y + (enemyLoc.y - myLoc.y);
            } else if (myLoc.y == enemyLoc.y) {  // ������ 
                jump.x = enemyLoc.x + (enemyLoc.x - myLoc.x);
                jump.y = myLoc.y;
            }
            for (const auto tmp : tmpPath) {
                if (tmp.second == 2 && tmp.first == jump) {  // ����λ�������·����, ���� 
                    bestNextLoc = jump;
                    break;
                }
            }
            if (!(bestNextLoc == jump)) { // ����������Ҫѡ����������·����ֹ���� 
                for (const auto tmp : tmpPath) {
                    if (tmp.second == 1 && !(tmp.first == enemyLoc)) {
                        bestNextLoc = tmp.first;
                        break;
                    }
                }
                if (!(bestNextLoc == jump)) {  // ���·��ֻ�����о������Ҳ����� 
                    if (remainChance > 1) {    // ����, Υ��һ�� 
                        remainChance--;
                    } else {                   // ������һ�� 
                        if (this->chessboard[myLoc].up && myLoc.y + 1 != enemyLoc.y) { // ���������� 
                            bestNextLoc = Location(myLoc.x, myLoc.y + 1);
                        } else if (this->chessboard[myLoc].down && myLoc.y - 1 != enemyLoc.y) {  // ���������� 
                            bestNextLoc = Location(myLoc.x, myLoc.y - 1);
                        } else if (this->chessboard[myLoc].right && myLoc.x + 1 != enemyLoc.x) {  // ���������� 
                            bestNextLoc = Location(myLoc.x + 1, myLoc.y);
                        } else if (this->chessboard[myLoc].left && myLoc.y - 1 != enemyLoc.y) {  // ���������� 
                            bestNextLoc = Location(myLoc.x - 1, myLoc.y);
                        } else {  // ������ִ��, ��ұ����� 
                            remainChance--;
                        }
                    }
                }
            }
        }
    } else {  // ���Ӳ�����, ���·������һ���ض����� 
        bestNextLoc = myPath.back().first;
    }
    return bestNextLoc;
}

Step BaselinePlayer::nextStep(const ChessboardChange& newChange) {
    if (this->myInitLoc.x <= 0 || this->myInitLoc.y <= 0) {
        this->myInitLoc = newChange.myLoc;
    }
    if (!newChange.newEnemyBlockBar.isNan()) {
        addOrDelBlock(newChange.newEnemyBlockBar);
    }
    std::queue<std::pair<Location, int>> myPath;
    std::queue<std::pair<Location, int>> enemyPath;
    const auto myDistance = minDistancePath(newChange.myLoc, newChange.enemyLoc, SIZE - this->myInitLoc.y + 1, myPath);
    const auto enemyDistance = minDistancePath(newChange.enemyLoc, newChange.myLoc, this->myInitLoc.y, enemyPath);
    Step step;
    if (myDistance <= enemyDistance || remainBlocks <= 0) {  // �ߵÿ쵱Ȼ���ƶ����� 
        step.myNewLoc = bestMove(newChange.myLoc, newChange.enemyLoc, myPath);
    } else { // �ߵ����͵÷��õ��� 
        auto myPathCopy(myPath);
        step.myNewBlockBar = bestBlockBar(newChange.myLoc, newChange.enemyLoc, 
                                          myPath, enemyPath);
        if (step.isNan()) {  // ������õİ���ǲ��Ű�, �ǻ����߰� 
            step.myNewLoc = bestMove(newChange.myLoc, newChange.enemyLoc, myPath);
        } else {
            remainBlocks--;
            addOrDelBlock(step.myNewBlockBar);
        }
    }
    std::cout << newChange << "  ->  " << step << std::endl;
    return step;
}

// ��Ҫ�����̽ṹ, �Լ���ʼ����, ʣ���Υ�����, ʣ��ĵ�����Ŀ��ʼ�� 
void BaselinePlayer::restart() {
    chessboardInit();
    myInitLoc.x = -1;
    myInitLoc.y = -1;
    remainBlocks = BLOCK_SUM;
    remainChance = 3;
}
}

/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * �����Ĳ�νṹ���£�
 *  _______________________________________________________________________
 * |                               nextStep                                |
 * |_______________________________________________________________________|
 * |          | |                 |  |   bestBlockBar   |  |               |
 * |          | |                 |  |__________________|  |               |
 * | bestMove | |                 |  | simulateBlockBar |  |               |
 * |          | |                 |  |__________________|  |               |
 * |          | | minDistancePath  \_________    _________/  addOrDelBlock |
 * |          | |                            |  |                          |
 * |__________| |____________________________|  |__________________________|
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 *  _______________________________________________________________________
 * |                               restart                                 |
 * |_______________________________________________________________________|
 * |                            chessboardInit                             |
 * |_______________________________________________________________________|
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 */