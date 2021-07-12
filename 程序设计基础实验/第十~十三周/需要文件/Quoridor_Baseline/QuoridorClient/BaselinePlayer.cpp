#include "BaselinePlayer.h"
#include <iostream>
#include <unordered_set>

namespace QuoridorUtils {

// 棋盘数据结构维护函数, 负责初始化棋盘. 
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

// 棋盘数据结构维护函数, 负责添加和删除挡板. 
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

// 注意: 传入的 enemyLoc 用于实现考虑对方棋子坐标求最短路径, 暂未做实现.
// 该函数为此算法核心 BFS, 可以计算传入的 myLoc 在当前棋盘下到达 myTargetY 的最短距离和最短路径.
// 最短路径通过引用 path 返回, 该队列中每个元素为 <坐标, 坐标与 myLoc 的最短距离>.
// path 中存储的路径按距离排序, 可能表示多条路径, 请注意辨别. 
int BaselinePlayer::minDistancePath(const Location& myLoc, const Location& enemyLoc, 
                                    const int myTargetY, std::queue<std::pair<Location, int>>& path) {
    while (!path.empty()) {
        path.pop();
    }
    if (myLoc.y == myTargetY) {
        return 0;
    }
    // BFS 寻找最短路径 
    std::vector<std::vector<int>> minDistanceMatrix(SIZE, std::vector<int>(SIZE, -1));
    minDistanceMatrix[myLoc.x - 1][myLoc.y - 1] = 0;
    //minDistanceMatrix[enemyLoc.x][enemyLoc.y] = -2;
    auto returnMinDistance = INT32_MAX;
    std::queue<std::pair<Location, int>> nextLocations;
    nextLocations.emplace(myLoc, 0);  // 刚开始入队列第0步 
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
            if (this->chessboard[tmp.first].up && minDistanceMatrix[tmp.first.x - 1][tmp.first.y] == -1) {     // 可以向上走 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y] = tmp.second + 1;
                nextLocations.emplace(Location(tmp.first.x, tmp.first.y + 1), tmp.second + 1);
            }
            if (this->chessboard[tmp.first].down && minDistanceMatrix[tmp.first.x - 1][tmp.first.y - 2] == -1) {   // 可以向下走 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y - 2] = tmp.second + 1;
                nextLocations.emplace(Location(tmp.first.x, tmp.first.y - 1), tmp.second + 1);
            }
            if (this->chessboard[tmp.first].right && minDistanceMatrix[tmp.first.x][tmp.first.y - 1] == -1) {  // 可以向右走 
                minDistanceMatrix[tmp.first.x][tmp.first.y - 1] = tmp.second + 1;
                nextLocations.emplace(Location(tmp.first.x + 1, tmp.first.y), tmp.second + 1);
            }
            if (this->chessboard[tmp.first].left && minDistanceMatrix[tmp.first.x - 2][tmp.first.y - 1] == -1) {   // 可以向左走 
                minDistanceMatrix[tmp.first.x - 2][tmp.first.y - 1] = tmp.second + 1;
                nextLocations.emplace(Location(tmp.first.x - 1, tmp.first.y), tmp.second + 1);
            }
        }
    }
    if (returnMinDistance != INT32_MAX) {  // 可达就往回找 
        while (!tmpPath.empty()) {
            const auto tmp = tmpPath.front();
            tmpPath.pop();
            if (tmp.second == 1) {
                continue;
            }
            if (this->chessboard[tmp.first].up &&
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y] == tmp.second - 1) {  // 可以向上回溯 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y] = -1;                 // 防止重新入队 
                path.emplace(Location(tmp.first.x, tmp.first.y + 1), tmp.second - 1);
                tmpPath.emplace(path.back());
            }
            if (this->chessboard[tmp.first].down && 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y - 2] == tmp.second - 1) {  // 可以向下回溯 
                minDistanceMatrix[tmp.first.x - 1][tmp.first.y - 2] = -1;
                path.emplace(Location(tmp.first.x, tmp.first.y - 1), tmp.second - 1);
                tmpPath.emplace(path.back());
            }
            if (this->chessboard[tmp.first].right && 
                minDistanceMatrix[tmp.first.x][tmp.first.y - 1] == tmp.second - 1) {  // 可以向右回溯 
                minDistanceMatrix[tmp.first.x][tmp.first.y - 1] = -1;
                path.emplace(Location(tmp.first.x + 1, tmp.first.y), tmp.second - 1);
                tmpPath.emplace(path.back());
            }
            if (this->chessboard[tmp.first].left && 
                minDistanceMatrix[tmp.first.x - 2][tmp.first.y - 1] == tmp.second - 1) {  // 可以向左回溯 
                minDistanceMatrix[tmp.first.x - 2][tmp.first.y - 1] = -1;
                path.emplace(Location(tmp.first.x - 1, tmp.first.y), tmp.second - 1);
                tmpPath.emplace(path.back());
            }
        }
    }
    return returnMinDistance;
}

// 求当前最好的放板方案, 返回 INT32_MIN 表示放板还不如不放. 
BlockBar BaselinePlayer::bestBlockBar(const Location& myLoc, const Location& enemyLoc, 
                                      std::queue<std::pair<Location, int>>& myPath,
                                      std::queue<std::pair<Location, int>>& enemyPath) {
    // 我方路径收益 -1, 敌方路径收益 +2, 宁毁自己, 不容他人  
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

// 模拟放一个挡板, 计算放板之后双方的路径长度之差. 返回 INT32_MIN 表示放板违规. 
int BaselinePlayer::simulateBlockBar(const Location& myLoc, const Location& enemyLoc,
                                     const BlockBar& fakeBlock) {
    if (fakeBlock.isNan()) {
        return INT32_MIN;
    }
    if (fakeBlock.isH() && fakeBlock.start.y > 0 && fakeBlock.start.y < SIZE) {  // y相同 
        // eg. ((0,1), (2,1)) will block (1,1) u, (2,1) u (1,2) d, (2,2) d
        const auto stopLoc = fakeBlock.start.x > fakeBlock.stop.x ? fakeBlock.start : fakeBlock.stop;
        if (!(this->chessboard[stopLoc].up && this->chessboard[Location(stopLoc.x - 1, stopLoc.y)].up && 
              this->chessboard[Location(stopLoc.x, stopLoc.y + 1)].down && 
              this->chessboard[Location(stopLoc.x - 1, stopLoc.y + 1)].down)) {
            return INT32_MIN;
        }// else if (!this->chessboard[stopLoc].left && !this->chessboard[Location(stopLoc.x - 1, stopLoc.y)].right && 
        //           !this->chessboard[Location(stopLoc.x, stopLoc.y + 1)].left && 
        //           !this->chessboard[Location(stopLoc.x - 1, stopLoc.y + 1)].right) {  // 不能交叉 
        //    return INT32_MIN;
        //}
    } else if (fakeBlock.isV() && fakeBlock.start.x > 0 && fakeBlock.start.x < SIZE) {  // x相同 
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

// 当下最好的棋子移动位置, 从最短路径 myPath 中取得,
// 在还有违规次数的情况下可能返回 (-1, -1), 表示移动还不如不动.  
Location BaselinePlayer::bestMove(const Location& myLoc, const Location& enemyLoc, std::queue<std::pair<Location, int>>& myPath) {
    Location bestNextLoc;
    if (myLoc.distance(enemyLoc) == 1) {  // 优先跳跃 
        std::vector<std::pair<Location, int>> tmpPath;  // 存储我方最短路径中2步可达位置 
        bool blocked = true;
        while (!myPath.empty()) {
            const auto tmp = myPath.front();
            myPath.pop();
            if (tmp.second >= 3) {
                continue;
            }
            if (tmp.first == enemyLoc && tmp.second == 1) {  // 敌我之间无挡板, 且最短路径第1步经过对方棋子 
                blocked = false;
            }
            tmpPath.emplace_back(tmp);
        }
        if (blocked) {  // 敌我之间有挡板, 必定不能跳, 此时step中下一步必定可行 
            for (const auto tmp : tmpPath) {
                if (tmp.second == 1) {
                    bestNextLoc = tmp.first;
                    break;
                }
            }
        } else {  // 敌我之间无挡板, 且最短路径经过对方棋子 
            Location jump;
            if (myLoc.x == enemyLoc.x) {  // 竖着跳 
                jump.x = myLoc.x;
                jump.y = enemyLoc.y + (enemyLoc.y - myLoc.y);
            } else if (myLoc.y == enemyLoc.y) {  // 横着跳 
                jump.x = enemyLoc.x + (enemyLoc.x - myLoc.x);
                jump.y = myLoc.y;
            }
            for (const auto tmp : tmpPath) {
                if (tmp.second == 2 && tmp.first == jump) {  // 将跳位置在最短路径内, 可跳 
                    bestNextLoc = jump;
                    break;
                }
            }
            if (!(bestNextLoc == jump)) { // 不可跳则需要选择另外的最短路径或静止不动 
                for (const auto tmp : tmpPath) {
                    if (tmp.second == 1 && !(tmp.first == enemyLoc)) {
                        bestNextLoc = tmp.first;
                        break;
                    }
                }
                if (!(bestNextLoc == jump)) {  // 最短路径只经过敌军棋子且不可跳 
                    if (remainChance > 1) {    // 不动, 违规一次 
                        remainChance--;
                    } else {                   // 必须走一步 
                        if (this->chessboard[myLoc].up && myLoc.y + 1 != enemyLoc.y) { // 可以向上走 
                            bestNextLoc = Location(myLoc.x, myLoc.y + 1);
                        } else if (this->chessboard[myLoc].down && myLoc.y - 1 != enemyLoc.y) {  // 可以向下走 
                            bestNextLoc = Location(myLoc.x, myLoc.y - 1);
                        } else if (this->chessboard[myLoc].right && myLoc.x + 1 != enemyLoc.x) {  // 可以向右走 
                            bestNextLoc = Location(myLoc.x + 1, myLoc.y);
                        } else if (this->chessboard[myLoc].left && myLoc.y - 1 != enemyLoc.y) {  // 可以向左走 
                            bestNextLoc = Location(myLoc.x - 1, myLoc.y);
                        } else {  // 不可能执行, 玩家被堵死 
                            remainChance--;
                        }
                    }
                }
            }
        }
    } else {  // 棋子不相邻, 最短路径的下一步必定可行 
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
    if (myDistance <= enemyDistance || remainBlocks <= 0) {  // 走得快当然得移动棋子 
        step.myNewLoc = bestMove(newChange.myLoc, newChange.enemyLoc, myPath);
    } else { // 走得慢就得放置挡板 
        auto myPathCopy(myPath);
        step.myNewBlockBar = bestBlockBar(newChange.myLoc, newChange.enemyLoc, 
                                          myPath, enemyPath);
        if (step.isNan()) {  // 倘若最好的板就是不放板, 那还得走啊 
            step.myNewLoc = bestMove(newChange.myLoc, newChange.enemyLoc, myPath);
        } else {
            remainBlocks--;
            addOrDelBlock(step.myNewBlockBar);
        }
    }
    std::cout << newChange << "  ->  " << step << std::endl;
    return step;
}

// 需要将棋盘结构, 自己初始坐标, 剩余的违规机会, 剩余的挡板数目初始化 
void BaselinePlayer::restart() {
    chessboardInit();
    myInitLoc.x = -1;
    myInitLoc.y = -1;
    remainBlocks = BLOCK_SUM;
    remainChance = 3;
}
}

/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * 函数的层次结构如下：
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