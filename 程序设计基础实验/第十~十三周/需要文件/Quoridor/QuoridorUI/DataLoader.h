#pragma once
#include <string>
#include "../QuoridorUtils/QuoridorUtils.h"

namespace QuoridorUtils {
class DataLoader {
public:
    virtual ~DataLoader() = default;
    // player0Name 是坐标在 QuoridorUtils::PLAYER0_LOC 开始的玩家;
    // player1Name 是坐标在 QuoridorUtils::PLAYER1_LOC 开始的玩家;
    virtual void getPlayerName(std::string& player0Name, std::string& player1Name) = 0;
    virtual bool getNextStep(std::string& playerName, QuoridorUtils::Step& nextStep, 
                             QuoridorUtils::GameStatus& status) = 0;
    virtual int getRemainingStep() = 0;
};
}
