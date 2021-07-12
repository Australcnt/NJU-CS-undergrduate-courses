#pragma once
#include <unordered_map>
#include <queue>
#include "Player.h"

namespace QuoridorUtils {
// ÿ�����Ӷ���������������, ģ��һ�������ĸ���, ���žͲ�����. 
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
    // ת�����嵽 chessboard, isDel ������ӻ�ɾ��, Ĭ��Ϊ��ӵ���  
    void addOrDelBlock(const BlockBar& block, const bool isDel = false);
    // �������������Ŀ��yֵ, ���� myLoc ����ָ�� y ֵ����С������ɴ�·��, ���ɴ��򷵻� INT32_MAX 
    // ע��: ��ʱδʹ�� enemyLoc 
    // ���� path ���ȱ����, �ٰ����� myLoc ������������λ������� pair, ��С����Ϊ1 
    int minDistancePath(const Location& myLoc, const Location& enemyLoc,
                        const int myTargetY, std::queue<std::pair<Location, int>>& path);
    // ��������·��, �������ŵ���λ�� 
    BlockBar bestBlockBar(const Location& myLoc, const Location& enemyLoc, 
                          std::queue<std::pair<Location, int>>& myPath,
                          std::queue<std::pair<Location, int>>& enemyPath);
    // ģ����õ���, ����·���������·��֮��, �����뵲���Է�����ʤ��·������Ϊ����, ���� INT32_MIN ��ʾΥ�� 
    int simulateBlockBar(const Location& myLoc, const Location& enemyLoc,
                         const BlockBar& fakeBlock);
    // ���� minDistancePath ȡ��������һ���ƶ�λ��
    Location bestMove(const Location& myLoc, const Location& enemyLoc, std::queue<std::pair<Location, int>>& myPath);

public:
    BaselinePlayer(const std::string& key) : Player("193304X") { };
    QuoridorUtils::Step nextStep(const QuoridorUtils::ChessboardChange& newChange) override;
    void restart() override;
};
}
