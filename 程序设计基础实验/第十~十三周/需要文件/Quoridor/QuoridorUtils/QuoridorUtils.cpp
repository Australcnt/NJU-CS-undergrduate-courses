#include "QuoridorUtils.h"

namespace QuoridorUtils {
const int SIZE = 9;                      // 棋盘大小 
const int BLOCK_SUM = 10;                // 玩家拥有的挡板总数 
const int BLOCK_LEN = 2;                 // 挡板长度 

const Location PLAYER0_LOC{ 5, 1 };  // 玩家0的初始位置 
const Location PLAYER1_LOC{ 5, SIZE };  // 玩家1的初始位置 

std::ostream& operator<<(std::ostream& os, const QuoridorUtils::GameStatus status) {
    switch (status) {
    case QuoridorUtils::GameStatus::Ok: os << "Ok"; break;
    case QuoridorUtils::GameStatus::Win: os << "Win"; break;
    case QuoridorUtils::GameStatus::Lost: os << "Lost"; break;
    case QuoridorUtils::GameStatus::Timeout: os << "Timeout"; break;
    case QuoridorUtils::GameStatus::EnemyClosed: os << "EnemyClosed"; break;
    case QuoridorUtils::GameStatus::RulesBreaker: os << "RulesBreaker"; break;
    case QuoridorUtils::GameStatus::InsufficientBlock: os << "InsufficientBlock"; break;
    case QuoridorUtils::GameStatus::InvalidStep: os << "InvalidStep"; break;
    case QuoridorUtils::GameStatus::None: os << "None"; break;
    default: os.setstate(std::ios_base::failbit);
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const QuoridorUtils::Location loc) {
    os << '(' << loc.x << ", " << loc.y << ')';
    return os;
}

std::ostream& operator<<(std::ostream& os, const QuoridorUtils::BlockBar block) {
    if (block.isNan()) {
        os << "Nan BlockBar.";
    } else {
        os << '[' << block.start << "; " << block.stop << ']';
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const QuoridorUtils::ChessboardChange change) {
    os << "game status: " << change.status
       << "; my loc: " << change.myLoc
       << "; enemy loc: " << change.enemyLoc;
    if (!change.newEnemyBlockBar.isNan()) {
        os << "; enemy new BlockBar: " << change.newEnemyBlockBar;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const QuoridorUtils::Step step) {
    if (step.isNan()) {
        os << "no operation!";
    } else {
        if (step.isMove() && !step.myNewBlockBar.isNan()) {
            os << "move to: " << step.myNewLoc << " and add BlockBar: " << step.myNewBlockBar;
        }else if (step.isMove()) {
            os << "move to: " << step.myNewLoc;
        }
        else if (!step.myNewBlockBar.isNan()) {
            os << "add BlockBar: " << step.myNewBlockBar;
        }
    }
    return os;
}

Step changeEndian(const Step& step, int intChangeEndian(int)) {
    Step changed;
    changed.myNewLoc.x = intChangeEndian(step.myNewLoc.x);
    changed.myNewLoc.y = intChangeEndian(step.myNewLoc.y);
    changed.myNewBlockBar.start.x = intChangeEndian(step.myNewBlockBar.start.x);
    changed.myNewBlockBar.start.y = intChangeEndian(step.myNewBlockBar.start.y);
    changed.myNewBlockBar.stop.x = intChangeEndian(step.myNewBlockBar.stop.x);
    changed.myNewBlockBar.stop.y = intChangeEndian(step.myNewBlockBar.stop.y);
    return changed;
}

ChessboardChange changeEndian(const ChessboardChange& chessboardChange, int intChangeEndian(int)) {
    ChessboardChange changed;
    changed.status = GameStatus(intChangeEndian(int(chessboardChange.status)));
    changed.myLoc.x = intChangeEndian(chessboardChange.myLoc.x);
    changed.myLoc.y = intChangeEndian(chessboardChange.myLoc.y);
    changed.enemyLoc.x = intChangeEndian(chessboardChange.enemyLoc.x);
    changed.enemyLoc.y = intChangeEndian(chessboardChange.enemyLoc.y);
    changed.newEnemyBlockBar.start.x = intChangeEndian(chessboardChange.newEnemyBlockBar.start.x);
    changed.newEnemyBlockBar.start.y = intChangeEndian(chessboardChange.newEnemyBlockBar.start.y);
    changed.newEnemyBlockBar.stop.x = intChangeEndian(chessboardChange.newEnemyBlockBar.stop.x);
    changed.newEnemyBlockBar.stop.y = intChangeEndian(chessboardChange.newEnemyBlockBar.stop.y);
    return changed;
}
}