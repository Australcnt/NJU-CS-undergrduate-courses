#pragma once
#include <unordered_map>
#include <queue>
#include "Player.h"

namespace QuoridorUtils {
// 每个格子都可能上下左右走, 模拟一个格子四个门, 关门就不能走. 
struct Doors {
    bool up = true;
    bool down = true;
    bool left = true;
    bool right = true;
};

class BaselinePlayer final : public Player {
private:
    Location myInitLoc;
    int remainBlocks = BLOCK_SUM;
    int remainChance = 3;
    std::unordered_map<Location, Doors, LocationHash> chessboard;
    void chessboardInit();
    // 转换挡板到 chessboard, isDel 控制添加或删除, 默认为添加挡板  
    void addOrDelBlock(const BlockBar& block, const bool isDel = false);
    // 给定两个坐标和目标y值, 计算 myLoc 到达指定 y 值的最小距离与可达路径, 不可达则返回 INT32_MAX 
    // 注意: 暂时未使用 enemyLoc 
    // 其中 path 将先被清空, 再按照与 myLoc 距离非升序填充位置与距离 pair, 最小距离为1 
    int minDistancePath(const Location& myLoc, const Location& enemyLoc,
                        const int myTargetY, std::queue<std::pair<Location, int>>& path);
    // 给定两条路径, 计算最优挡板位置 
    BlockBar bestBlockBar(const Location& myLoc, const Location& enemyLoc, 
                          std::queue<std::pair<Location, int>>& myPath,
                          std::queue<std::pair<Location, int>>& enemyPath);
    // 模拟放置挡板, 计算路径敌我最短路径之差, 若加入挡板后对方比我胜利路径长则为正数, 返回 INT32_MIN 表示违规 
    int simulateBlockBar(const Location& myLoc, const Location& enemyLoc,
                         const BlockBar& fakeBlock);
    // 给定 minDistancePath 取得最优下一步移动位置
    Location bestMove(const Location& myLoc, const Location& enemyLoc, std::queue<std::pair<Location, int>>& myPath);

public:
    BaselinePlayer(const std::string& key) : Player("193304X") { };
    QuoridorUtils::Step nextStep(const QuoridorUtils::ChessboardChange& newChange) override;
    void restart() override;
};
}
