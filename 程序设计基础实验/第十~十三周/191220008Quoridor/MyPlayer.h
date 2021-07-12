#pragma once
#include <vector>

#include "Player.h"

//�������
//namespace QuoridorUtils {
//class MyPlayer final : public Player{
//private:
//    std::vector<BlockBar> blocks;                                           // ʵ������Ҫ, ��ɾ 
//    int targetY = 0;                                                        // ʵ������Ҫ, ��ɾ 
//    Location randomWalk(const Location& myLoc, const Location& enemyLoc);   // ʵ������Ҫ, ��ɾ 
//public:
//    MyPlayer(const std::string& key) : Player(key) {};            // �������, �����޸� 
//    Step nextStep(const ChessboardChange& newChange) override;    // ��������ʵ�� 
//    void restart() override;                                      // ��������ʵ�� 
//};
//}

// �������
namespace QuoridorUtils {
class MyPlayer final : public Player {
public:
    MyPlayer(const std::string& key) : Player(key) { };          // ������� 
    Step nextStep(const ChessboardChange& newChange) override;   // ��������ʵ�� 
    void restart() override;                                     // ��������ʵ��
};
}

struct Node
{
    QuoridorUtils::Location Loc;
    bool directions[4];
    Node* next;
};

void direction_check(bool directions[], const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc);
int path_seek(const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc);
bool block_check(const QuoridorUtils::BlockBar& block_set, const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc);
int block_seek(const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc);

void queue_initialize();
void board_initialize();
Node* pop();
void push(QuoridorUtils::Location Loc, Node* next);
double evaluation(double my_path_number, double my_block_number, double enemy_path_number, double enemy_block_number);

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