#pragma once
#include <ostream>
#include <cstdlib>
#include <functional>

namespace QuoridorUtils {

extern const int SIZE;        // 棋盘大小 
extern const int BLOCK_SUM;   // 玩家拥有的挡板总数 
extern const int BLOCK_LEN;   // 挡板长度

enum class GameStatus {
    Ok = 0,                   // 正常 
    Win = 1,                  // 胜利, 不经玩家处理 v 
    Lost = 2,                 // 失败, 不经玩家处理 d 
    Timeout = 3,              // 超时 
    EnemyClosed = 4,          // 对手故障 v 
    RulesBreaker = 5,         // 违规多次判负 d 
    InsufficientBlock = 6,    // 挡板已用完 
    InvalidStep = 7,          // 棋子不可达或挡板坐标错误 
    None = 2000,              // 未定义状态, 请勿使用 
};

struct Location {
    int x;
    int y;
    Location(const int x = -1, const int y = -1) {
        this->x = x;
        this->y = y;
    };
    bool operator==(const Location& rLoc) const {
        return this->x == rLoc.x && this->y == rLoc.y;
    }
    int distance(const Location& rLoc) const {  // 街区距离
        return (abs(this->x - rLoc.x) + abs(this->y - rLoc.y));
    }
};

extern const Location PLAYER0_LOC;  // 玩家0的初始位置 
extern const Location PLAYER1_LOC;  // 玩家1的初始位置 

struct BlockBar {
    Location start;  // 挡板开始坐标
    Location stop;   // 挡板结束坐标
    BlockBar(const int startX = -1, const int startY = -1, 
             const int stopX = -1, const int stopY = -1) {
        this->start.x = startX;
        this->start.y = startY;
        this->stop.x = stopX;
        this->stop.y = stopY;
    };
    BlockBar(const Location start, const Location stop = Location(-1, -1)) {
        this->start = start;
        this->stop = stop;
    };
    bool operator==(const BlockBar& rLoc) const {
        return this->start == rLoc.start && this->stop == rLoc.stop;
    }
    bool isNan() const {  // 判断是否有挡板, 返回true表示数据不合法表示没有挡板 
        return this->start.x < 0 || this->start.x > SIZE ||  // 数据不合法 
               this->start.y < 0 || this->start.y > SIZE || 
               this->stop.x < 0 || this->stop.x > SIZE ||
               this->stop.y < 0 || this->stop.y > SIZE || 
               !(isH() || isV()) ||                          // 挡板倾斜 
               (start.distance(stop) != BLOCK_LEN);      // 挡板长度不对 
    };
    bool isH() const { // 判断挡板方向是否为横向 
        return this->start.y == this->stop.y && this->start.x != this->stop.x;
    };
    bool isV() const { // 判断挡板方向是否为纵向 
        return this->start.x == this->stop.x && this->start.y != this->stop.y;
    };
    void normalization() {  // 标准化为 start < stop, 只会交换 start 和 stop, 不会修改数据
        if (this->start.x >= this->stop.x && this->start.y >= this->stop.y) {
            const Location tmp = this->start;
            this->start = this->stop;
            this->stop = tmp;
        }
    }
};

struct ChessboardChange {
    GameStatus status = GameStatus::Ok;
    Location myLoc;
    Location enemyLoc;
    BlockBar newEnemyBlockBar;  // 若敌方在放置了隔板则该项为隔板的起始终结点，
                                // 未放置则默认为(-1, -1, -1, -1) 
    bool isFinish() const {     // 判断游戏是否结束 
        return isWin() || isLost();
    }

    bool isWin() const {        // 判断是否胜利 
        switch (this->status) {
        case GameStatus::EnemyClosed:
        case GameStatus::Win:
            return true;
        default:
            return false;
        }
    }

    bool isLost() const {       // 判断是否失败 
        switch (this->status) {
        case GameStatus::Lost:
        case GameStatus::RulesBreaker:
            return true;
        default:
            return false;
        }
    }
};

struct Step {
    Location myNewLoc;         // 自己移动的目的坐标, 不移动则默认为(-1, -1)
    BlockBar myNewBlockBar;    // 若自己在放置了隔板则该项为隔板的起始点和终结点，
                               // 未放置则默认为(-1, -1, -1, -1) 
    Step(const Location loc = Location(), const BlockBar block = BlockBar()) {
        this->myNewLoc = loc;
        this->myNewBlockBar = block;
    }
    Step(const ChessboardChange chessboard) {
        this->myNewLoc = chessboard.enemyLoc;
        this->myNewBlockBar = chessboard.newEnemyBlockBar;
    }
    bool isMove() const {
        return this->myNewLoc.x >= 1 && this->myNewLoc.x <= SIZE &&
               this->myNewLoc.y >= 1 && this->myNewLoc.y <= SIZE;
    }
    bool isNan() const {
        return !this->isMove() && this->myNewBlockBar.isNan();
    }
};

extern std::ostream& operator<<(std::ostream& os, const QuoridorUtils::GameStatus status);
extern std::ostream& operator<<(std::ostream& os, const QuoridorUtils::Location loc);
extern std::ostream& operator<<(std::ostream& os, const QuoridorUtils::BlockBar block);
extern std::ostream& operator<<(std::ostream& os, const QuoridorUtils::ChessboardChange change);
extern std::ostream& operator<<(std::ostream& os, const QuoridorUtils::Step step);

// 若使用 Location 或 BlockBar 作为 unordered_map/unordered_set 的 key, 请使用此哈希, 用法如下: 
// std::unordered_map<QuoridorUtils::Location, valClass, QuoridorUtils::LocationHash> obj;
// std::unordered_set<QuoridorUtils::BlockBar, QuoridorUtils::BlockBarHash> obj;
struct LocationHash {  
    size_t operator()(const Location& loc) const {
        return std::hash<int>{}(loc.x) + std::hash<int>{}(loc.y);
    }
};
struct BlockBarHash {
    size_t operator()(const BlockBar& block) const {
        return std::hash<int>{}(block.start.x) + std::hash<int>{}(block.start.y) + 
            std::hash<int>{}(block.stop.x) + std::hash<int>{}(block.stop.y);
    }
};

extern Step changeEndian(const Step& step, int intChangeEndian(int));  // 通信数据大小端处理, 学生请勿调用此函数 
extern ChessboardChange changeEndian(const ChessboardChange& chessboardChange, int intChangeEndian(int));  // 通信数据大小端处理, 学生请勿调用此函数
}


/*
 *
 * 棋子坐标如下:                          挡板坐标结构如下：
 * ┌-┬-┬-┬-┬-┬-┬-┬-┬-┐          ┌-┬-┬-┬-┬-┬-┬-┬-┬-┐9
 * ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖9       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤8
 * ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖8       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤7
 * ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖7       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤6
 * ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖6       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤5
 * ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖5       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤4
 * ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖4       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤3
 * ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖3       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤2
 * ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖2       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤1
 * └-┴-┴-┴-┴-┴-┴-┴-┴-┘↖1 y     └-┴-┴-┴-┴-┴-┴-┴-┴-┘0 y
 *x  1  2  3  4  5  6  7  8  9          x  0  1  2  3  4  5  6  7  8  9
 *
 *
 */