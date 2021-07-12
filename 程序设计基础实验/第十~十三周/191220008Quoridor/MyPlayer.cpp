#include "MyPlayer.h"

#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <math.h>

 //�������ʵ�ֿ�ʼ
using namespace QuoridorUtils;
int targetY = 0;
QuoridorUtils::Location min_Loc;
QuoridorUtils::Location min_Loc_seek;
QuoridorUtils::BlockBar min_block_set;
QuoridorUtils::Location next_Loc;
QuoridorUtils::BlockBar next_block_set;
int path_status = -1;
int block_status = -1;
int step_number = 0;
int my_path_min_step_number = 0;
int enemy_path_min_step_number = 0;
int my_block_step_number = 0;
int my_block_min_step_number = 0;
int enemy_block_step_number = 0;
int enemy_block_min_step_number = 0;
std::vector<QuoridorUtils::BlockBar> blocks;
int head = 0, tail = 0;
Node queue[100], path[10000];
int board[9][9] = { 0 };
int my_block_left = 10;
int enemy_block_left = 10;
int illegal = 0;
int my_illegal_times = 0;


void my_strategy(const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc) 
{
    my_path_min_step_number = path_seek(myLoc, enemyLoc);
    min_Loc = min_Loc_seek;
    targetY = 10 - targetY;
    enemy_path_min_step_number = path_seek(enemyLoc, myLoc);
    targetY = 10 - targetY;
    if (my_block_left > 0)
        block_status = block_seek(myLoc, enemyLoc);
    double score_1 = 0;
    double score_2 = 0;
    score_1 = 22.0 * (double)enemy_path_min_step_number + 1.0 * (double)enemy_block_left - 5.0 * (double)my_path_min_step_number - 3.0 * (double)my_block_left;
    score_2 = 2.0 * (double)enemy_block_min_step_number - 1.0 * (double)enemy_block_left - 5.0 * (double)my_block_min_step_number + 4.0 * ((double)my_block_left - 1) + 40.0 * ((double)enemy_block_min_step_number - (double)enemy_path_min_step_number);
    if (my_block_min_step_number - my_path_min_step_number > enemy_block_min_step_number - enemy_path_min_step_number)
        score_1 = score_1 + 50;
    if (my_path_min_step_number < 4 && my_path_min_step_number < enemy_path_min_step_number)
        score_1 = score_1 + 10000;
    if (enemy_path_min_step_number < 4 && my_path_min_step_number >= enemy_path_min_step_number)
        score_2 = score_2 + 10000;
    if (my_path_min_step_number > enemy_path_min_step_number + 1)
        score_2 = score_2 + 10;
    else if (my_path_min_step_number > enemy_path_min_step_number)
        score_2 = score_2 + 15;
    if (my_path_min_step_number > enemy_path_min_step_number + 3 && my_block_min_step_number - my_path_min_step_number <= enemy_block_min_step_number - enemy_path_min_step_number)
        score_2 = score_2 + 25;
    if (my_block_min_step_number - my_path_min_step_number + 1 < enemy_block_min_step_number - enemy_path_min_step_number)
        score_2 = score_2 + 35;
    if (my_block_min_step_number - my_path_min_step_number <= enemy_block_min_step_number - enemy_path_min_step_number && my_path_min_step_number > enemy_path_min_step_number + 2)
        score_2 = score_2 + 50;
    if(illegal || my_illegal_times == 2)
    {
        next_Loc = min_Loc;
        path_status = 1;
        return;
    }
    if(block_status==-1 || min_Loc.y == targetY)
    {
        next_Loc = min_Loc;
        path_status = 1;
        return;
    }
    if(my_path_min_step_number > 0 && score_1 >= score_2)
    {
        next_Loc = min_Loc;
        path_status = 1;
        return;
    }
    else
    {
        next_block_set = min_block_set;
        block_status = 1;
        return;
    }
}
// �������ʵ�ֽ���

namespace QuoridorUtils {

/*
 * Step MyPlayer::nextStep(const ChessboardChange& newChange)
 *
 * newChange Ϊ�޸ĵ����, ���ʽΪ
 * (GameStatus status, Location enemyLoc, Location myLoc, BlockBar newEnemyBlockBar)
 * ������������͵����������ͼ, ������û������µĵ���ʱ,
 * newChange.newEnemyBlockBar.isNan()Ϊtrue
 * 
 * ��Ҫ���ص�����StepΪ
 * (Location myNewLoc, BlockBar myNewBlockBar)
 * ����ѡ�����ƶ�����һ����ǰ�������ĸ����򣩻��߷�һ������:
 * ���ƶ�����ʱ, step.myNewBlockBar.isNan()Ϊtrue; 
 * �����õ���ʱ, step.myNewLocΪnewChange�е�myLoc
 *
 * ���д���(����λ�ô���, ����������, �ƶ�λ�ô���, ͬʱ�ƶ������õ���, ��ʱ��)���ɷ��������,
 * ������Ҫ������ʵ�ִ�����⹦��. 
 *
 *  ������������:                          ��������ṹ���£�
 *  ��-��-��-��-��-��-��-��-��-��          ��-��-��-��-��-��-��-��-��-��9
 *  ��-��-��-��-��-��-��-��-��-�ȨI9       ��-��-��-��-��-��-��-��-��-��8
 *  ��-��-��-��-��-��-��-��-��-�ȨI8       ��-��-��-��-��-��-��-��-��-��7
 *  ��-��-��-��-��-��-��-��-��-�ȨI7       ��-��-��-��-��-��-��-��-��-��6
 *  ��-��-��-��-��-��-��-��-��-�ȨI6       ��-��-��-��-��-��-��-��-��-��5
 *  ��-��-��-��-��-��-��-��-��-�ȨI5       ��-��-��-��-��-��-��-��-��-��4
 *  ��-��-��-��-��-��-��-��-��-�ȨI4       ��-��-��-��-��-��-��-��-��-��3
 *  ��-��-��-��-��-��-��-��-��-�ȨI3       ��-��-��-��-��-��-��-��-��-��2
 *  ��-��-��-��-��-��-��-��-��-�ȨI2       ��-��-��-��-��-��-��-��-��-��1
 *  ��-��-��-��-��-��-��-��-��-���I1 y     ��-��-��-��-��-��-��-��-��-��0 y
 * x  1  2  3  4  5  6  7  8  9          x  0  1  2  3  4  5  6  7  8  9
 *
 */

// �������ʵ�ֿ�ʼ
//Location MyPlayer::randomWalk(const Location& myLoc, const Location& enemyLoc) {
//    bool directions[4];
//    directions[0] = myLoc.y < SIZE;                          // �Ƿ���������� 
//    directions[1] = myLoc.y > 1;                             // �Ƿ���������� 
//    directions[2] = myLoc.x > 1;                             // �Ƿ���������� 
//    directions[3] = myLoc.x < SIZE;                          // �Ƿ���������� 
//    for (auto block : this->blocks) {                        // ���������б�, �ҵ����赲�ķ��� 
//        if (block.isH()) {                                   // ˮƽ���򵲰�, start �� stop �� y ��� 
//            if (block.start.x == myLoc.x - 1 ||
//                block.start.x == myLoc.x - 2) {              // ���ܵ�·�ĵ��� 
//                if (block.start.y == myLoc.y) {
//                    directions[0] = false;
//                } else if (block.start.y == myLoc.y - 1) {
//                    directions[1] = false;
//                }
//            }
//        }
//        if (block.isV()) {                                   // ��ֱ���򵲰�, start �� stop �� x ��� 
//            if (block.start.y == myLoc.y - 1 ||
//                block.start.y == myLoc.y - 2) {              // ���ܵ�·�ĵ��� 
//                if (block.start.x == myLoc.x) {
//                    directions[2] = false;
//                } else if (block.start.x == myLoc.x - 1) {
//                    directions[3] = false;
//                }
//            }
//        }
//    }
//    int optionsCount = int(directions[0]) + int(directions[1]) + 
//                       int(directions[2]) + int(directions[3]);    // �����в��ܶ�������, �ض����ڵ���1 
//    int tmp = rand() % optionsCount;                               // ���һ�� [0, optionsCount - 1] ������
//    int directionIndex;                                            // �ҳ����������±� 
//    for (directionIndex = 0; directionIndex < 4; directionIndex++) {
//        if (directions[directionIndex]) {
//            if (tmp <= 0) {
//                break;
//            }
//            tmp--;
//        }
//    }
//    Location nextLoc = myLoc;
//    switch (directionIndex) {
//    case 0:   // ������
//        nextLoc.y++;
//        break;
//    case 1:   // ������
//        nextLoc.y--;
//        break;
//    case 2:   // ������
//        nextLoc.x--;
//        break;
//    case 3:   // ������
//        nextLoc.x++;
//        break;
//    default: ;
//    }
//    if (nextLoc.distance(enemyLoc) == 0) {                   // ��һ���ǵо�λ����Ӧ�����о����� 
//        nextLoc.x = -1;                                      // �˴�����ʵ��, Ĭ����һ���ղ��� 
//        nextLoc.y = -1;
//    }
//    return nextLoc;
//}
//
//Step MyPlayer::nextStep(const ChessboardChange& newChange) {
//    // ��֪: ��ʾ���������Ϊ API ʹ���Լ���Ϸ�����˽ⷶ��, ������֤������ȷ��, �����ճ��հ� 
//    if (this->targetY == 0) {                                // �жϲ���¼�Լ���Ŀ�� 
//        const auto d = std::chrono::system_clock::now().time_since_epoch();
//        const int nanosecond = (std::chrono::nanoseconds(d).count() / 100) % int64_t(INT32_MAX);
//        srand(nanosecond);
//        if (newChange.myLoc == PLAYER0_LOC) {                // ������ʼ����Ϊ (5,1) ��Ŀ��Ϊ (x,9) 
//            this->targetY = PLAYER1_LOC.y;
//        } else {                                             // ������ʼ����Ϊ (5,9) ��Ŀ��Ϊ (x,1) 
//            this->targetY = PLAYER0_LOC.y;
//        }
//    }
//    std::cout << newChange;                                  // ������յ������ݵ�����̨��ʾ 
//    if (!newChange.newEnemyBlockBar.isNan()) {               // �Է������˵��� 
//        BlockBar tmp = newChange.newEnemyBlockBar;
//        tmp.normalization();                                 // �淶Ϊ start ����С�� stop �������ʽ 
//        this->blocks.push_back(tmp);                         // �洢�淶���� 
//    }
//    Step step;                                               // ��ʼ�� step Ĭ�ϲ��ƶ����Ű� 
//    step.myNewLoc = randomWalk(newChange.myLoc, newChange.enemyLoc);
//    std::cout << " -> " << step << std::endl;                // ����ҵľ��ߵ�����̨��ʾ 
//    return step;
//}
//
//void MyPlayer::restart() {
//    this->blocks.clear();
//    this->targetY = 0;
//}
// �������ʵ�ֽ���

// �������ʵ�ֿ�ʼ
Step MyPlayer::nextStep(const ChessboardChange& newChange) 
{ 
    clock_t start, finish;//��ʱ
    start = clock();
    double result;
    if (targetY == 0) {                                // �жϲ���¼�Լ���Ŀ��
        const auto d = std::chrono::system_clock::now().time_since_epoch();
        const int nanosecond = (std::chrono::nanoseconds(d).count() / 100) % int64_t(INT32_MAX);
        srand(nanosecond);
        if (newChange.myLoc == PLAYER0_LOC) // ������ʼ����Ϊ (5,1) ��Ŀ��Ϊ (x,9)
        {                
            targetY = PLAYER1_LOC.y;
        } 
        else // ������ʼ����Ϊ (5,9) ��Ŀ��Ϊ (x,1)
        {                                             
            targetY = PLAYER0_LOC.y;
        }
    }
    if (newChange.status == GameStatus::InvalidStep)//��¼��Ч��������
    {
        illegal = 1;
        my_illegal_times++;
    }
    std::cout << newChange;                     // ������յ������ݵ�����̨��ʾ  
    if (!newChange.newEnemyBlockBar.isNan()) // �Է������˵���
    {                
        BlockBar tmp = newChange.newEnemyBlockBar;
        tmp.normalization();                                 // �淶Ϊ start ����С�� stop �������ʽ
        if (tmp.isV())
        {
            if (tmp.start.x == 1 || tmp.start.x == 8)//�ж��Ƿ�Ϊ����ʽľ��
            {
                BlockBar trap_block1, trap_block2;
                for(auto block : blocks)
                {
                    if(block.isV())
                    {
                        if (block.start.x == tmp.start.x)
                        {
                            if (tmp.start.y == block.start.y + 2 || tmp.start.y == block.start.y - 2)
                            {
                                trap_block1 = block;
                            }
                            else if (tmp.start.y == block.start.y + 4 || tmp.start.y == block.start.y - 4)
                            {
                                trap_block2 = block;
                            }
                            if(tmp.start.y + trap_block1.start.y + trap_block2.start.y == 3 * tmp.start.y || tmp.start.y + trap_block1.start.y + trap_block2.start.y == 3 * trap_block1.start.y || tmp.start.y + trap_block1.start.y + trap_block2.start.y == 3 * trap_block2.start.y)
                            {
                                BlockBar prevent;
                                prevent.start.x = tmp.start.x - 1;
                                prevent.start.y = tmp.start.y + trap_block1.start.y + trap_block2.start.y / 3;
                                prevent.stop.x = tmp.start.x + 1;
                                prevent.stop.y = tmp.start.y + trap_block1.start.y + trap_block2.start.y / 3;
                                if (!block_check(prevent, newChange.myLoc, newChange.enemyLoc))
                                    break;
                                block_status = 1;
                                next_block_set = prevent;
                                blocks.push_back(tmp);                         // �洢���� 
                                enemy_block_left--;
                                goto T;
                            }
                        }
                    }
                }
            }
        }
        blocks.push_back(tmp);                         // �洢���� 
        enemy_block_left--;
    }
    my_strategy(newChange.myLoc, newChange.enemyLoc);
    T:
    Step step;                                     // ��ʼ�� step Ĭ�ϲ��ƶ����Ű� 
    if (path_status == 1)//�ж��ƶ����Ƿ�ľ�壬�����
        step.myNewLoc = next_Loc;
    else if (block_status == 1)
    {
        step.myNewBlockBar = next_block_set;
        blocks.push_back(next_block_set);
        my_block_left--;
    }
    std::cout << " -> " << step;                          // ����ҵľ��ߵ�����̨��ʾ 
    path_status = -1;
    block_status = -1;
    step_number = 0;
    my_path_min_step_number = 0;
    enemy_path_min_step_number = 0;
    my_block_step_number = 0;
    my_block_min_step_number = 0;
    enemy_block_step_number = 0;
    enemy_block_min_step_number = 0;
    memset(queue, 0, sizeof(queue));
    memset(path, 0, sizeof(path));
    queue_initialize();
    board_initialize();
    illegal = 0;
    finish = clock();
    result = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout << "    " << result << std::endl;  //�����λΪs����ȷ��ms
    return step;
}

void MyPlayer::restart() 
{
    blocks.clear();
    targetY = 0;
    path_status = -1;
    block_status = -1;
    step_number = 0;
    my_path_min_step_number = 0;
    enemy_path_min_step_number = 0;
    my_block_step_number = 0;
    my_block_min_step_number = 0;
    enemy_block_step_number = 0;
    enemy_block_min_step_number = 0;
    memset(queue, 0, sizeof(queue));
    memset(path, 0, sizeof(path));
    my_block_left = 10;
    enemy_block_left = 10;
    queue_initialize();
    board_initialize();
    illegal = 0;
    my_illegal_times = 0;
}
// �������ʵ�ֽ���
}

void direction_check(bool directions[], const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc)
{
    directions[0] = myLoc.y < QuoridorUtils::SIZE;           // �Ƿ���������� 
    directions[1] = myLoc.y > 1;                             // �Ƿ���������� 
    directions[2] = myLoc.x > 1;                             // �Ƿ���������� 
    directions[3] = myLoc.x < QuoridorUtils::SIZE;           // �Ƿ����������
    if (myLoc.y != 9 && board[myLoc.x - 1][myLoc.y])         // ����·��ʱ���Ѿ�ȥ����λ�ò�����ȥ
        directions[0] = false;
    if (myLoc.y != 1 && board[myLoc.x - 1][myLoc.y - 2])
        directions[1] = false;
    if (myLoc.x != 1 && board[myLoc.x - 2][myLoc.y - 1])
        directions[2] = false;
    if (myLoc.x != 9 && board[myLoc.x][myLoc.y - 1])
        directions[3] = false;
    for (auto block : blocks)//���������б�, �ҵ����赲�ķ��� 
    {                        
        if (block.isH())//ˮƽ���򵲰�, start �� stop �� y ���
        {                                    
            if ((block.start.x == myLoc.x - 1 && block.stop.x == myLoc.x + 1) || (block.start.x == myLoc.x - 2 && block.stop.x == myLoc.x)) //���ܵ�·�ĵ��� 
            {              
                if (block.start.y == myLoc.y) 
                {
                    directions[0] = false;
                }
                else if (block.start.y == myLoc.y - 1) 
                {
                    directions[1] = false;
                }
            }
        }
        if (block.isV())// ��ֱ���򵲰�, start �� stop �� x ���
        {                                    
            if ((block.start.y == myLoc.y - 1 && block.stop.y == myLoc.y + 1) || (block.start.y == myLoc.y - 2 && block.stop.y == myLoc.y)) // ���ܵ�·�ĵ���
            {               
                if (block.start.x == myLoc.x) 
                {
                    directions[3] = false;
                }
                else if (block.start.x == myLoc.x - 1) 
                {
                    directions[2] = false;
                }
            }
        }
    }
}

int path_seek(const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc)
{
    Node* temp;
    int path_min_step_number_seek = 0;
    int encounter = 0;
    push(myLoc, NULL);
    while (1) 
    {
        if (head >= tail)//����ͷ�Ͷ�β���ʱ���˳�
        {
            board_initialize();
            queue_initialize();
            memset(queue, 0, sizeof(queue));
            memset(path, 0, sizeof(path));
            return -1;
        }
        temp = pop();
        if (temp==NULL)//·������
        {
            board_initialize();
            queue_initialize();
            memset(queue, 0, sizeof(queue));
            memset(path, 0, sizeof(path));
            return -1;
        }
        if (temp->Loc.y==targetY)//���ߵ��յ�ʱ����path���鱣����յ㷵�ص�����·��
        {
            while (temp != NULL)//��һ�����ݵ�nextָ��ָ��գ���Ϊ����������ֹ������
            {
                path[path_min_step_number_seek].Loc = temp->Loc;
                if (temp->Loc.distance(enemyLoc) == 0)
                    encounter = 1;
                path_min_step_number_seek++;
                if (temp && temp->next && temp->next->next == NULL)//��¼���·������һ���ƶ�λ��
                {
                    if (temp->Loc.distance(enemyLoc) == 0)//����һ��������Ҫ��Խ�Է��Ĵ���
                    {
                        if (temp->next->Loc.x == enemyLoc.x - 1)//λ�ڶԷ����
                        {
                            if (!temp->directions[3])//�Է������ľ��
                            {
                                if (targetY == 9)
                                {
                                    if (temp->next->directions[0])
                                    {
                                        temp->Loc.x--;
                                        temp->Loc.y++;
                                    }
                                    else if (temp->next->directions[2])
                                    {
                                        temp->Loc.x--;
                                        temp->Loc.x--;
                                    }
                                    else if (temp->next->directions[1])
                                    {
                                        temp->Loc.x--;
                                        temp->Loc.y--;
                                    }
                                }
                                else
                                {
                                    if (temp->next->directions[1])
                                    {
                                        temp->Loc.x--;
                                        temp->Loc.y--;
                                    }
                                    else if (temp->next->directions[2])
                                    {
                                        temp->Loc.x--;
                                        temp->Loc.x--;
                                    }
                                    else if (temp->next->directions[0])
                                    {
                                        temp->Loc.x--;
                                        temp->Loc.y++;
                                    }
                                }
                            }
                            else
                                temp->Loc.x++;
                        }
                        else if (temp->next->Loc.x == enemyLoc.x + 1)//λ�ڶԷ��ұ�
                        {
                            if (!temp->directions[2])//�Է������ľ��
                            {
                                if (targetY == 9)
                                {
                                    if (temp->next->directions[0])
                                    {
                                        temp->Loc.x++;
                                        temp->Loc.y++;
                                    }
                                    else if (temp->next->directions[3])
                                    {
                                        temp->Loc.x++;
                                        temp->Loc.x++;
                                    }
                                    else if (temp->next->directions[1])
                                    {
                                        temp->Loc.x++;
                                        temp->Loc.y--;
                                    }
                                }
                                else
                                {
                                    if (temp->next->directions[1])
                                    {
                                        temp->Loc.x++;
                                        temp->Loc.y--;
                                    }
                                    else if (temp->next->directions[3])
                                    {
                                        temp->Loc.x++;
                                        temp->Loc.x++;
                                    }
                                    else if (temp->next->directions[0])
                                    {
                                        temp->Loc.x++;
                                        temp->Loc.y++;
                                    }
                                }
                            }
                            else
                                temp->Loc.x--;
                        }
                        else if (temp->next->Loc.y == enemyLoc.y - 1)//λ�ڶԷ��±�
                        {
                            if (temp->Loc.y == 9 || !temp->directions[0])//�Է������ľ��
                            {
                                if (temp->next->directions[2])
                                {
                                    temp->Loc.x--;
                                    temp->Loc.y--;
                                }
                                else if (temp->next->directions[3])
                                {
                                    temp->Loc.x++;
                                    temp->Loc.y--;
                                }
                                else if (temp->next->directions[1])
                                {
                                    temp->Loc.y--;
                                    temp->Loc.y--;
                                }
                            }
                            else
                                temp->Loc.y++;
                        }
                        else if (temp->next->Loc.y == enemyLoc.y + 1)//λ�ڶԷ��ϱ�
                        {
                            if (temp->Loc.y == 1 || !temp->directions[1])//�Է������ľ��
                            {
                                if (temp->next->directions[2])
                                {
                                    temp->Loc.x--;
                                    temp->Loc.y++;
                                }
                                else if (temp->next->directions[3])
                                {
                                    temp->Loc.x++;
                                    temp->Loc.y++;
                                }
                                else if (temp->next->directions[0])
                                {
                                    temp->Loc.y++;
                                    temp->Loc.y++;
                                }
                            }
                            else
                                temp->Loc.y--;
                        }
                    }
                    min_Loc_seek = temp->Loc;
                }
                temp = temp->next;
            }
            board_initialize();
            queue_initialize();
            memset(queue, 0, sizeof(queue));
            memset(path, 0, sizeof(path));
            if (encounter)
                path_min_step_number_seek--;
            return --path_min_step_number_seek;
        }
        direction_check(temp->directions, temp->Loc, enemyLoc);//�жϵ�ǰ���ƶ��ķ���
        board[temp->Loc.x - 1][temp->Loc.y - 1] = 1;
        if (targetY == 9)//�����ĸ�����ֻҪ�����������ͼ������
        {
            if (temp->directions[2])//��
            {
                Node* temp3 = new Node;
                temp3->Loc = temp->Loc;
                temp3->Loc.x--;
                push(temp3->Loc, temp);
                board[temp3->Loc.x - 1][temp3->Loc.y - 1] = 1;
            }
            if (temp->directions[3])//��
            {
                Node* temp4 = new Node;
                temp4->Loc = temp->Loc;
                temp4->Loc.x++;
                push(temp4->Loc, temp);
                board[temp4->Loc.x - 1][temp4->Loc.y - 1] = 1;
            }
            if (temp->directions[0])//��
            {
                Node* temp2 = new Node;
                temp2->Loc = temp->Loc;
                temp2->Loc.y++;
                push(temp2->Loc, temp);
                board[temp2->Loc.x - 1][temp2->Loc.y - 1] = 1;
            }
            if (temp->directions[1])//��
            {
                Node* temp5 = new Node;
                temp5->Loc = temp->Loc;
                temp5->Loc.y--;
                push(temp5->Loc, temp);
                board[temp5->Loc.x - 1][temp5->Loc.y - 1] = 1;
            }
            if(!temp->directions[0] && !temp->directions[1] && !temp->directions[2] && !temp->directions[3])//·������
                continue;
        }
        else
        { 
            if (temp->directions[2])//��
            {
                Node* temp3 = new Node;
                temp3->Loc = temp->Loc;
                temp3->Loc.x--;
                push(temp3->Loc, temp);
                board[temp3->Loc.x - 1][temp3->Loc.y - 1] = 1;
            }
            if (temp->directions[3])//��
            {
                Node* temp4 = new Node;
                temp4->Loc = temp->Loc;
                temp4->Loc.x++;
                push(temp4->Loc, temp);
                board[temp4->Loc.x - 1][temp4->Loc.y - 1] = 1;
            }
            if (temp->directions[1])//��
            {
                Node* temp5 = new Node;
                temp5->Loc = temp->Loc;
                temp5->Loc.y--;
                push(temp5->Loc, temp);
                board[temp5->Loc.x - 1][temp5->Loc.y - 1] = 1;
            }
            if (temp->directions[0])//��
            {
                Node* temp2 = new Node;
                temp2->Loc = temp->Loc;
                temp2->Loc.y++;
                push(temp2->Loc, temp);
                board[temp2->Loc.x - 1][temp2->Loc.y - 1] = 1;
            }
            if (!temp->directions[0] && !temp->directions[1] && !temp->directions[2] && !temp->directions[3])//·������
                continue;
        }
    }
}

bool block_check(const QuoridorUtils::BlockBar& block_set, const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc)
{
    for (auto block : blocks)
    {
        if (block.start == block_set.start && block.stop == block_set.stop)//�·���ľ����ԭ��ľ����ȫ�غ�
            return false;
        if (block_set.isH() && block.isH())//�·��õ�ľ���ԭ��ľ���Ϊ����
        {
            if (block.start.y == block_set.start.y && (((block.start.x == (block_set.start.x - 1)) && (block.stop.x == (block_set.stop.x - 1))) || ((block.start.x == (block_set.start.x + 1)) && (block.stop.x == (block_set.stop.x + 1)))))//�·��õĺ���ľ����ԭ��ľ�岿���غ�
                return false;
        }
        else if (block_set.isV() && block.isV())//�·��õ�ľ���ԭ��ģ���Ϊ����
        {
            if (block.start.x == block_set.start.x && (((block.start.y == (block_set.start.y - 1)) && (block.stop.y == (block_set.stop.y - 1))) || ((block.start.y == (block_set.start.y + 1)) && (block.stop.y == (block_set.stop.y + 1)))))//�·��õ�����ľ����ԭ��ľ�岿���غ�
                return false;
        }
        else//�·��õ�ľ����ԭ��ľ�巽��ͬ
            continue;
    }
    targetY = 10 - targetY;
    if(path_seek(enemyLoc,myLoc) == -1)//�ж��Ƿ�ѶԷ�����
    {
        targetY = 10 - targetY;
        return false;
    }
    targetY = 10 - targetY;
    return true;
}

int block_seek(const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc)
{
    int random_number = 0;
    random_number = rand() % 2;
    QuoridorUtils::BlockBar block_set;
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (random_number == 0)
            {
                block_set.start.x = j;
                block_set.start.y = i;
                block_set.stop.x = j + 2;
                block_set.stop.y = i;
            }
            else
            {
                block_set.start.x = i;
                block_set.start.y = j;
                block_set.stop.x = i;
                block_set.stop.y = j + 2;
            }
            if (!block_check(block_set, myLoc, enemyLoc))
                continue;
            blocks.push_back(block_set);
            my_block_step_number = path_seek(myLoc, enemyLoc);
            targetY = 10 - targetY;
            enemy_block_step_number = path_seek(enemyLoc, myLoc);
            targetY = 10 - targetY;
            blocks.pop_back();
            if (my_block_step_number == -1 || enemy_block_step_number == -1)
                continue;
            if (my_block_min_step_number)
            {
                if (enemy_block_step_number - my_block_step_number > enemy_block_min_step_number - my_block_min_step_number
                    //|| (enemy_block_step_number - my_block_step_number == enemy_block_min_step_number - my_block_min_step_number && enemy_block_step_number > enemy_block_min_step_number)
                    )//ȱ�����ľ����������,�ɿ���ϵ������
                {
                    my_block_min_step_number = my_block_step_number;
                    enemy_block_min_step_number = enemy_block_step_number;
                    block_set.normalization();
                    min_block_set = block_set;
                }
            }
            else if (!my_block_min_step_number)
            {
                my_block_min_step_number = my_block_step_number;
                enemy_block_min_step_number = enemy_block_step_number;
                block_set.normalization();
                min_block_set = block_set;
            }
        }
    }
    for(int i = 1; i < 9; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if (random_number == 1)
            {
                block_set.start.x = j;
                block_set.start.y = i;
                block_set.stop.x = j + 2;
                block_set.stop.y = i;
            }
            else
            {
                block_set.start.x = i;
                block_set.start.y = j;
                block_set.stop.x = i;
                block_set.stop.y = j + 2;
            }
            if (!block_check(block_set, myLoc, enemyLoc))
                continue;
            blocks.push_back(block_set);
            my_block_step_number = path_seek(myLoc, enemyLoc);
            targetY = 10 - targetY;
            enemy_block_step_number = path_seek(enemyLoc,myLoc);
            targetY = 10 - targetY;
            blocks.pop_back();
            if (my_block_step_number == -1 || enemy_block_step_number == -1)
                continue;
            if(my_block_min_step_number)
            {
                if (enemy_block_step_number - my_block_step_number > enemy_block_min_step_number - my_block_min_step_number
                    //|| (enemy_block_step_number - my_block_step_number == enemy_block_min_step_number - my_block_min_step_number && enemy_block_step_number > enemy_block_min_step_number)
                    )//ȱ�����ľ����������,�ɿ���ϵ������
                {
                    my_block_min_step_number = my_block_step_number;
                    enemy_block_min_step_number = enemy_block_step_number;
                    block_set.normalization();
                    min_block_set = block_set;
                }
            }
            else if(!my_block_min_step_number)
            {
                my_block_min_step_number = my_block_step_number;
                enemy_block_min_step_number = enemy_block_step_number;
                block_set.normalization();
                min_block_set = block_set;
            }
        }
    }
    if (!my_block_min_step_number)
        return -1;
    return 0;
}

void queue_initialize()//���г�ʼ��
{
    head = 0;
    tail = 0;
}

Node* pop()//�������г�Ա
{
    Node* p;
    p = &queue[head];
    head++;
    return p;
}

void push(QuoridorUtils::Location Loc, Node* next)// ���߹��ĵ���Ϣ������У�nextΪָ����һ���ڵ����ݵ�ָ��
{
    queue[tail].Loc = Loc;
    queue[tail].next = next;
    tail++;
}

void board_initialize()//�������߹���λ�ó�ʼ��
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            board[i][j] = 0;
}

double evaluation(double my_path_number, double my_block_number, double enemy_path_number, double enemy_block_number)//��������
{
    double score = 0;
    score = 12 * pow(my_path_number, my_block_number/10) - my_block_number * pow(enemy_path_number, 10);
    return score;
}

/*randomwalkʾ��
QuoridorUtils::Location randomWalk(const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc) {
    bool directions[4];
    directions[0] = myLoc.y < QuoridorUtils::SIZE;           // �Ƿ����������
    directions[1] = myLoc.y > 0;                             // �Ƿ����������
    directions[2] = myLoc.x > 0;                             // �Ƿ����������
    directions[3] = myLoc.x < QuoridorUtils::SIZE;           // �Ƿ����������
    for (auto block : blocks) {                        // ���������б�, �ҵ����赲�ķ���
        if (block.isH()) {                                   // ˮƽ���򵲰�, start �� stop �� y ���
            if (block.start.x == myLoc.x - 1 ||
                block.start.x == myLoc.x - 2) {              // ���ܵ�·�ĵ���
                if (block.start.y == myLoc.y) {
                    directions[0] = false;
                } else if (block.start.y == myLoc.y - 1) {
                    directions[1] = false;
                }
            }
        }
        if (block.isV()) {                                   // ��ֱ���򵲰�, start �� stop �� x ���
            if (block.start.y == myLoc.y - 1 ||
                block.start.y == myLoc.y - 2) {              // ���ܵ�·�ĵ���
                if (block.start.x == myLoc.x) {
                    directions[3] = false;
                } else if (block.start.x == myLoc.x - 1) {
                    directions[2] = false;
                }
            }
        }
    }
    int optionsCount = directions[0] + directions[1] +
                       directions[2] + directions[3];        // �����ܶ�������, �ض����ڵ���1
    int tmp = rand() % optionsCount;                         // ���һ�� [0, optionsCount - 1] ������
    int directionIndex;                                      // �ҳ����������±�
    for (directionIndex = 0; directionIndex < 4; directionIndex++) {
        if (directions[directionIndex]) {
            if (tmp <= 0) {
                break;
            }
            tmp--;
        }
    }
    QuoridorUtils::Location nextLoc = myLoc;
    switch (directionIndex) {
    case 0:   // ������
        nextLoc.y++;
        break;
    case 1:   // ������
        nextLoc.y--;
        break;
    case 2:   // ������
        nextLoc.x--;
        break;
    case 3:   // ������
        nextLoc.x++;
        break;
    default: ;
    }
    if (nextLoc.distance(enemyLoc) == 0) {                   // ��һ���ǵо�λ����Ӧ�����о�����
        nextLoc.x = -1;                                      // �˴�����ʵ��, Ĭ����һ���ղ���
        nextLoc.y = -1;
    }
    return nextLoc;
}
// �������ʵ�ֽ���
*/

/*nextStepʾ��
namespace QuoridorUtils {
// �������ʵ�ֿ�ʼ
Step MyPlayer::nextStep(const ChessboardChange& newChange) {
    // ��֪: ��ʾ���������Ϊ API ʹ���Լ���Ϸ�����˽ⷶ��, ������֤������ȷ��, �����ճ��հ�
    if (targetY == 0) {                                // �жϲ���¼�Լ���Ŀ��
        const auto d = std::chrono::system_clock::now().time_since_epoch();
        const int nanosecond = (std::chrono::nanoseconds(d).count() / 100) % int64_t(INT32_MAX);
        srand(nanosecond);
        if (newChange.myLoc == PLAYER0_LOC) {                // ������ʼ����Ϊ (5,1) ��Ŀ��Ϊ (x,9)
            targetY = PLAYER1_LOC.y;
        } else {                                             // ������ʼ����Ϊ (5,9) ��Ŀ��Ϊ (x,1)
            targetY = PLAYER0_LOC.y;
        }
    }
    std::cout << newChange;                     // ������յ������ݵ�����̨��ʾ
    if (!newChange.newEnemyBlockBar.isNan()) {               // �Է������˵���
        BlockBar tmp = newChange.newEnemyBlockBar;
        tmp.normalization();                                 // �淶Ϊ start ����С�� stop �������ʽ
        blocks.push_back(tmp);                         // �洢����
    }
    Step step;                                               // ��ʼ�� step Ĭ�ϲ��ƶ����Ű�
    step.myNewLoc = randomWalk(newChange.myLoc, newChange.enemyLoc);
    std::cout << " -> " << step << std::endl;                          // ����ҵľ��ߵ�����̨��ʾ
    return step;
}

void MyPlayer::restart() {
    blocks.clear();
    targetY = 0;
}
// �������ʵ�ֽ���
}
*/