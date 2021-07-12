#pragma once
#include <string>
#include "../QuoridorUtils/QuoridorUtils.h"

namespace QuoridorUtils {
class DataLoader {
public:
    virtual ~DataLoader() = default;
    // player0Name �������� QuoridorUtils::PLAYER0_LOC ��ʼ�����;
    // player1Name �������� QuoridorUtils::PLAYER1_LOC ��ʼ�����;
    virtual void getPlayerName(std::string& player0Name, std::string& player1Name) = 0;
    virtual bool getNextStep(std::string& playerName, QuoridorUtils::Step& nextStep, 
                             QuoridorUtils::GameStatus& status) = 0;
    virtual int getRemainingStep() = 0;
};
}
