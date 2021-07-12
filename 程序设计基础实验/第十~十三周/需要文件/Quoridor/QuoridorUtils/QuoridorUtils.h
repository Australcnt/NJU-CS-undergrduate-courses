#pragma once
#include <ostream>
#include <cstdlib>
#include <functional>

namespace QuoridorUtils {

extern const int SIZE;        // ���̴�С 
extern const int BLOCK_SUM;   // ���ӵ�еĵ������� 
extern const int BLOCK_LEN;   // ���峤��

enum class GameStatus {
    Ok = 0,                   // ���� 
    Win = 1,                  // ʤ��, ������Ҵ��� v 
    Lost = 2,                 // ʧ��, ������Ҵ��� d 
    Timeout = 3,              // ��ʱ 
    EnemyClosed = 4,          // ���ֹ��� v 
    RulesBreaker = 5,         // Υ�����и� d 
    InsufficientBlock = 6,    // ���������� 
    InvalidStep = 7,          // ���Ӳ��ɴ�򵲰�������� 
    None = 2000,              // δ����״̬, ����ʹ�� 
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
    int distance(const Location& rLoc) const {  // ��������
        return (abs(this->x - rLoc.x) + abs(this->y - rLoc.y));
    }
};

extern const Location PLAYER0_LOC;  // ���0�ĳ�ʼλ�� 
extern const Location PLAYER1_LOC;  // ���1�ĳ�ʼλ�� 

struct BlockBar {
    Location start;  // ���忪ʼ����
    Location stop;   // �����������
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
    bool isNan() const {  // �ж��Ƿ��е���, ����true��ʾ���ݲ��Ϸ���ʾû�е��� 
        return this->start.x < 0 || this->start.x > SIZE ||  // ���ݲ��Ϸ� 
               this->start.y < 0 || this->start.y > SIZE || 
               this->stop.x < 0 || this->stop.x > SIZE ||
               this->stop.y < 0 || this->stop.y > SIZE || 
               !(isH() || isV()) ||                          // ������б 
               (start.distance(stop) != BLOCK_LEN);      // ���峤�Ȳ��� 
    };
    bool isH() const { // �жϵ��巽���Ƿ�Ϊ���� 
        return this->start.y == this->stop.y && this->start.x != this->stop.x;
    };
    bool isV() const { // �жϵ��巽���Ƿ�Ϊ���� 
        return this->start.x == this->stop.x && this->start.y != this->stop.y;
    };
    void normalization() {  // ��׼��Ϊ start < stop, ֻ�ύ�� start �� stop, �����޸�����
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
    BlockBar newEnemyBlockBar;  // ���з��ڷ����˸��������Ϊ�������ʼ�ս�㣬
                                // δ������Ĭ��Ϊ(-1, -1, -1, -1) 
    bool isFinish() const {     // �ж���Ϸ�Ƿ���� 
        return isWin() || isLost();
    }

    bool isWin() const {        // �ж��Ƿ�ʤ�� 
        switch (this->status) {
        case GameStatus::EnemyClosed:
        case GameStatus::Win:
            return true;
        default:
            return false;
        }
    }

    bool isLost() const {       // �ж��Ƿ�ʧ�� 
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
    Location myNewLoc;         // �Լ��ƶ���Ŀ������, ���ƶ���Ĭ��Ϊ(-1, -1)
    BlockBar myNewBlockBar;    // ���Լ��ڷ����˸��������Ϊ�������ʼ����ս�㣬
                               // δ������Ĭ��Ϊ(-1, -1, -1, -1) 
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

// ��ʹ�� Location �� BlockBar ��Ϊ unordered_map/unordered_set �� key, ��ʹ�ô˹�ϣ, �÷�����: 
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

extern Step changeEndian(const Step& step, int intChangeEndian(int));  // ͨ�����ݴ�С�˴���, ѧ��������ô˺��� 
extern ChessboardChange changeEndian(const ChessboardChange& chessboardChange, int intChangeEndian(int));  // ͨ�����ݴ�С�˴���, ѧ��������ô˺���
}


/*
 *
 * ������������:                          ��������ṹ���£�
 * ��-��-��-��-��-��-��-��-��-��          ��-��-��-��-��-��-��-��-��-��9
 * ��-��-��-��-��-��-��-��-��-�ȨI9       ��-��-��-��-��-��-��-��-��-��8
 * ��-��-��-��-��-��-��-��-��-�ȨI8       ��-��-��-��-��-��-��-��-��-��7
 * ��-��-��-��-��-��-��-��-��-�ȨI7       ��-��-��-��-��-��-��-��-��-��6
 * ��-��-��-��-��-��-��-��-��-�ȨI6       ��-��-��-��-��-��-��-��-��-��5
 * ��-��-��-��-��-��-��-��-��-�ȨI5       ��-��-��-��-��-��-��-��-��-��4
 * ��-��-��-��-��-��-��-��-��-�ȨI4       ��-��-��-��-��-��-��-��-��-��3
 * ��-��-��-��-��-��-��-��-��-�ȨI3       ��-��-��-��-��-��-��-��-��-��2
 * ��-��-��-��-��-��-��-��-��-�ȨI2       ��-��-��-��-��-��-��-��-��-��1
 * ��-��-��-��-��-��-��-��-��-���I1 y     ��-��-��-��-��-��-��-��-��-��0 y
 *x  1  2  3  4  5  6  7  8  9          x  0  1  2  3  4  5  6  7  8  9
 *
 *
 */