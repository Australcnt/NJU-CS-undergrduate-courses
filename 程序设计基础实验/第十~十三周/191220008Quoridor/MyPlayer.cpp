#include "MyPlayer.h"

#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <math.h>

 //面向过程实现开始
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
// 面向过程实现结束

namespace QuoridorUtils {

/*
 * Step MyPlayer::nextStep(const ChessboardChange& newChange)
 *
 * newChange 为修改的棋局, 其格式为
 * (GameStatus status, Location enemyLoc, Location myLoc, BlockBar newEnemyBlockBar)
 * 其中棋子坐标和挡板坐标见下图, 当对手没有添加新的挡板时,
 * newChange.newEnemyBlockBar.isNan()为true
 * 
 * 需要返回的数据Step为
 * (Location myNewLoc, BlockBar myNewBlockBar)
 * 仅能选择让移动棋子一步（前后左右四个方向）或者放一个挡板:
 * 当移动棋子时, step.myNewBlockBar.isNan()为true; 
 * 当放置挡板时, step.myNewLoc为newChange中的myLoc
 *
 * 所有错误(挡板位置错误, 挡板已用完, 移动位置错误, 同时移动并放置挡板, 超时等)均由服务器检测,
 * 可能需要在自行实现错误避免功能. 
 *
 *  棋子坐标如下:                          挡板坐标结构如下：
 *  ┌-┬-┬-┬-┬-┬-┬-┬-┬-┐          ┌-┬-┬-┬-┬-┬-┬-┬-┬-┐9
 *  ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖9       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤8
 *  ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖8       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤7
 *  ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖7       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤6
 *  ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖6       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤5
 *  ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖5       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤4
 *  ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖4       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤3
 *  ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖3       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤2
 *  ├-┼-┼-┼-┼-┼-┼-┼-┼-┤↖2       ├-┼-┼-┼-┼-┼-┼-┼-┼-┤1
 *  └-┴-┴-┴-┴-┴-┴-┴-┴-┘↖1 y     └-┴-┴-┴-┴-┴-┴-┴-┴-┘0 y
 * x  1  2  3  4  5  6  7  8  9          x  0  1  2  3  4  5  6  7  8  9
 *
 */

// 面向对象实现开始
//Location MyPlayer::randomWalk(const Location& myLoc, const Location& enemyLoc) {
//    bool directions[4];
//    directions[0] = myLoc.y < SIZE;                          // 是否可以向上走 
//    directions[1] = myLoc.y > 1;                             // 是否可以向下走 
//    directions[2] = myLoc.x > 1;                             // 是否可以向左走 
//    directions[3] = myLoc.x < SIZE;                          // 是否可以向右走 
//    for (auto block : this->blocks) {                        // 遍历挡板列表, 找到被阻挡的方向 
//        if (block.isH()) {                                   // 水平方向挡板, start 与 stop 的 y 相等 
//            if (block.start.x == myLoc.x - 1 ||
//                block.start.x == myLoc.x - 2) {              // 可能挡路的挡板 
//                if (block.start.y == myLoc.y) {
//                    directions[0] = false;
//                } else if (block.start.y == myLoc.y - 1) {
//                    directions[1] = false;
//                }
//            }
//        }
//        if (block.isV()) {                                   // 竖直方向挡板, start 与 stop 的 x 相等 
//            if (block.start.y == myLoc.y - 1 ||
//                block.start.y == myLoc.y - 2) {              // 可能挡路的挡板 
//                if (block.start.x == myLoc.x) {
//                    directions[2] = false;
//                } else if (block.start.x == myLoc.x - 1) {
//                    directions[3] = false;
//                }
//            }
//        }
//    }
//    int optionsCount = int(directions[0]) + int(directions[1]) + 
//                       int(directions[2]) + int(directions[3]);    // 规则中不能堵死棋子, 必定大于等于1 
//    int tmp = rand() % optionsCount;                               // 随机一个 [0, optionsCount - 1] 的整数
//    int directionIndex;                                            // 找出随机方向的下标 
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
//    case 0:   // 向上走
//        nextLoc.y++;
//        break;
//    case 1:   // 向下走
//        nextLoc.y--;
//        break;
//    case 2:   // 向左走
//        nextLoc.x--;
//        break;
//    case 3:   // 向右走
//        nextLoc.x++;
//        break;
//    default: ;
//    }
//    if (nextLoc.distance(enemyLoc) == 0) {                   // 下一步是敌军位置则应跳过敌军棋子 
//        nextLoc.x = -1;                                      // 此处不做实现, 默认下一步空操作 
//        nextLoc.y = -1;
//    }
//    return nextLoc;
//}
//
//Step MyPlayer::nextStep(const ChessboardChange& newChange) {
//    // 须知: 本示例代码仅作为 API 使用以及游戏规则了解范例, 甚至保证不了正确性, 切勿照抄照搬 
//    if (this->targetY == 0) {                                // 判断并记录自己的目标 
//        const auto d = std::chrono::system_clock::now().time_since_epoch();
//        const int nanosecond = (std::chrono::nanoseconds(d).count() / 100) % int64_t(INT32_MAX);
//        srand(nanosecond);
//        if (newChange.myLoc == PLAYER0_LOC) {                // 己方初始坐标为 (5,1) 则目标为 (x,9) 
//            this->targetY = PLAYER1_LOC.y;
//        } else {                                             // 己方初始坐标为 (5,9) 则目标为 (x,1) 
//            this->targetY = PLAYER0_LOC.y;
//        }
//    }
//    std::cout << newChange;                                  // 输出接收到的数据到控制台显示 
//    if (!newChange.newEnemyBlockBar.isNan()) {               // 对方放置了挡板 
//        BlockBar tmp = newChange.newEnemyBlockBar;
//        tmp.normalization();                                 // 规范为 start 坐标小于 stop 坐标的形式 
//        this->blocks.push_back(tmp);                         // 存储规范挡板 
//    }
//    Step step;                                               // 初始化 step 默认不移动不放板 
//    step.myNewLoc = randomWalk(newChange.myLoc, newChange.enemyLoc);
//    std::cout << " -> " << step << std::endl;                // 输出我的决策到控制台显示 
//    return step;
//}
//
//void MyPlayer::restart() {
//    this->blocks.clear();
//    this->targetY = 0;
//}
// 面向对象实现结束

// 面向过程实现开始
Step MyPlayer::nextStep(const ChessboardChange& newChange) 
{ 
    clock_t start, finish;//计时
    start = clock();
    double result;
    if (targetY == 0) {                                // 判断并记录自己的目标
        const auto d = std::chrono::system_clock::now().time_since_epoch();
        const int nanosecond = (std::chrono::nanoseconds(d).count() / 100) % int64_t(INT32_MAX);
        srand(nanosecond);
        if (newChange.myLoc == PLAYER0_LOC) // 己方初始坐标为 (5,1) 则目标为 (x,9)
        {                
            targetY = PLAYER1_LOC.y;
        } 
        else // 己方初始坐标为 (5,9) 则目标为 (x,1)
        {                                             
            targetY = PLAYER0_LOC.y;
        }
    }
    if (newChange.status == GameStatus::InvalidStep)//记录无效操作次数
    {
        illegal = 1;
        my_illegal_times++;
    }
    std::cout << newChange;                     // 输出接收到的数据到控制台显示  
    if (!newChange.newEnemyBlockBar.isNan()) // 对方放置了挡板
    {                
        BlockBar tmp = newChange.newEnemyBlockBar;
        tmp.normalization();                                 // 规范为 start 坐标小于 stop 坐标的形式
        if (tmp.isV())
        {
            if (tmp.start.x == 1 || tmp.start.x == 8)//判断是否为陷阱式木板
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
                                blocks.push_back(tmp);                         // 存储挡板 
                                enemy_block_left--;
                                goto T;
                            }
                        }
                    }
                }
            }
        }
        blocks.push_back(tmp);                         // 存储挡板 
        enemy_block_left--;
    }
    my_strategy(newChange.myLoc, newChange.enemyLoc);
    T:
    Step step;                                     // 初始化 step 默认不移动不放板 
    if (path_status == 1)//判断移动还是放木板，以输出
        step.myNewLoc = next_Loc;
    else if (block_status == 1)
    {
        step.myNewBlockBar = next_block_set;
        blocks.push_back(next_block_set);
        my_block_left--;
    }
    std::cout << " -> " << step;                          // 输出我的决策到控制台显示 
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
    std::cout << "    " << result << std::endl;  //输出单位为s，精确到ms
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
// 面向过程实现结束
}

void direction_check(bool directions[], const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc)
{
    directions[0] = myLoc.y < QuoridorUtils::SIZE;           // 是否可以向上走 
    directions[1] = myLoc.y > 1;                             // 是否可以向下走 
    directions[2] = myLoc.x > 1;                             // 是否可以向左走 
    directions[3] = myLoc.x < QuoridorUtils::SIZE;           // 是否可以向右走
    if (myLoc.y != 9 && board[myLoc.x - 1][myLoc.y])         // 搜索路径时，已经去过的位置不能再去
        directions[0] = false;
    if (myLoc.y != 1 && board[myLoc.x - 1][myLoc.y - 2])
        directions[1] = false;
    if (myLoc.x != 1 && board[myLoc.x - 2][myLoc.y - 1])
        directions[2] = false;
    if (myLoc.x != 9 && board[myLoc.x][myLoc.y - 1])
        directions[3] = false;
    for (auto block : blocks)//遍历挡板列表, 找到被阻挡的方向 
    {                        
        if (block.isH())//水平方向挡板, start 与 stop 的 y 相等
        {                                    
            if ((block.start.x == myLoc.x - 1 && block.stop.x == myLoc.x + 1) || (block.start.x == myLoc.x - 2 && block.stop.x == myLoc.x)) //可能挡路的挡板 
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
        if (block.isV())// 竖直方向挡板, start 与 stop 的 x 相等
        {                                    
            if ((block.start.y == myLoc.y - 1 && block.stop.y == myLoc.y + 1) || (block.start.y == myLoc.y - 2 && block.stop.y == myLoc.y)) // 可能挡路的挡板
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
        if (head >= tail)//当队头和队尾相等时，退出
        {
            board_initialize();
            queue_initialize();
            memset(queue, 0, sizeof(queue));
            memset(path, 0, sizeof(path));
            return -1;
        }
        temp = pop();
        if (temp==NULL)//路被堵死
        {
            board_initialize();
            queue_initialize();
            memset(queue, 0, sizeof(queue));
            memset(path, 0, sizeof(path));
            return -1;
        }
        if (temp->Loc.y==targetY)//当走到终点时，用path数组保存从终点返回到起点的路径
        {
            while (temp != NULL)//第一个数据的next指针指向空，作为返回起点的终止条件。
            {
                path[path_min_step_number_seek].Loc = temp->Loc;
                if (temp->Loc.distance(enemyLoc) == 0)
                    encounter = 1;
                path_min_step_number_seek++;
                if (temp && temp->next && temp->next->next == NULL)//记录最短路径的下一步移动位置
                {
                    if (temp->Loc.distance(enemyLoc) == 0)//对下一步可能需要跨越对方的处理
                    {
                        if (temp->next->Loc.x == enemyLoc.x - 1)//位于对方左边
                        {
                            if (!temp->directions[3])//对方身后有木板
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
                        else if (temp->next->Loc.x == enemyLoc.x + 1)//位于对方右边
                        {
                            if (!temp->directions[2])//对方身后有木板
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
                        else if (temp->next->Loc.y == enemyLoc.y - 1)//位于对方下边
                        {
                            if (temp->Loc.y == 9 || !temp->directions[0])//对方身后有木板
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
                        else if (temp->next->Loc.y == enemyLoc.y + 1)//位于对方上边
                        {
                            if (temp->Loc.y == 1 || !temp->directions[1])//对方身后有木板
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
        direction_check(temp->directions, temp->Loc, enemyLoc);//判断当前可移动的方向
        board[temp->Loc.x - 1][temp->Loc.y - 1] = 1;
        if (targetY == 9)//遍历四个方向，只要满足条件，就加入队列
        {
            if (temp->directions[2])//左
            {
                Node* temp3 = new Node;
                temp3->Loc = temp->Loc;
                temp3->Loc.x--;
                push(temp3->Loc, temp);
                board[temp3->Loc.x - 1][temp3->Loc.y - 1] = 1;
            }
            if (temp->directions[3])//右
            {
                Node* temp4 = new Node;
                temp4->Loc = temp->Loc;
                temp4->Loc.x++;
                push(temp4->Loc, temp);
                board[temp4->Loc.x - 1][temp4->Loc.y - 1] = 1;
            }
            if (temp->directions[0])//上
            {
                Node* temp2 = new Node;
                temp2->Loc = temp->Loc;
                temp2->Loc.y++;
                push(temp2->Loc, temp);
                board[temp2->Loc.x - 1][temp2->Loc.y - 1] = 1;
            }
            if (temp->directions[1])//下
            {
                Node* temp5 = new Node;
                temp5->Loc = temp->Loc;
                temp5->Loc.y--;
                push(temp5->Loc, temp);
                board[temp5->Loc.x - 1][temp5->Loc.y - 1] = 1;
            }
            if(!temp->directions[0] && !temp->directions[1] && !temp->directions[2] && !temp->directions[3])//路被堵死
                continue;
        }
        else
        { 
            if (temp->directions[2])//左
            {
                Node* temp3 = new Node;
                temp3->Loc = temp->Loc;
                temp3->Loc.x--;
                push(temp3->Loc, temp);
                board[temp3->Loc.x - 1][temp3->Loc.y - 1] = 1;
            }
            if (temp->directions[3])//右
            {
                Node* temp4 = new Node;
                temp4->Loc = temp->Loc;
                temp4->Loc.x++;
                push(temp4->Loc, temp);
                board[temp4->Loc.x - 1][temp4->Loc.y - 1] = 1;
            }
            if (temp->directions[1])//下
            {
                Node* temp5 = new Node;
                temp5->Loc = temp->Loc;
                temp5->Loc.y--;
                push(temp5->Loc, temp);
                board[temp5->Loc.x - 1][temp5->Loc.y - 1] = 1;
            }
            if (temp->directions[0])//上
            {
                Node* temp2 = new Node;
                temp2->Loc = temp->Loc;
                temp2->Loc.y++;
                push(temp2->Loc, temp);
                board[temp2->Loc.x - 1][temp2->Loc.y - 1] = 1;
            }
            if (!temp->directions[0] && !temp->directions[1] && !temp->directions[2] && !temp->directions[3])//路被堵死
                continue;
        }
    }
}

bool block_check(const QuoridorUtils::BlockBar& block_set, const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc)
{
    for (auto block : blocks)
    {
        if (block.start == block_set.start && block.stop == block_set.stop)//新放置木板与原有木板完全重合
            return false;
        if (block_set.isH() && block.isH())//新放置的木板和原有木板均为横向
        {
            if (block.start.y == block_set.start.y && (((block.start.x == (block_set.start.x - 1)) && (block.stop.x == (block_set.stop.x - 1))) || ((block.start.x == (block_set.start.x + 1)) && (block.stop.x == (block_set.stop.x + 1)))))//新放置的横向木板与原有木板部分重合
                return false;
        }
        else if (block_set.isV() && block.isV())//新放置的木板和原有模板均为竖向
        {
            if (block.start.x == block_set.start.x && (((block.start.y == (block_set.start.y - 1)) && (block.stop.y == (block_set.stop.y - 1))) || ((block.start.y == (block_set.start.y + 1)) && (block.stop.y == (block_set.stop.y + 1)))))//新放置的竖向木板与原有木板部分重合
                return false;
        }
        else//新放置的木板与原有木板方向不同
            continue;
    }
    targetY = 10 - targetY;
    if(path_seek(enemyLoc,myLoc) == -1)//判断是否把对方堵死
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
                    )//缺少最佳木板评估函数,可考虑系数问题
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
                    )//缺少最佳木板评估函数,可考虑系数问题
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

void queue_initialize()//队列初始化
{
    head = 0;
    tail = 0;
}

Node* pop()//弹出队列成员
{
    Node* p;
    p = &queue[head];
    head++;
    return p;
}

void push(QuoridorUtils::Location Loc, Node* next)// 将走过的点信息加入队列，next为指向上一个节点数据的指针
{
    queue[tail].Loc = Loc;
    queue[tail].next = next;
    tail++;
}

void board_initialize()//棋盘中走过的位置初始化
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            board[i][j] = 0;
}

double evaluation(double my_path_number, double my_block_number, double enemy_path_number, double enemy_block_number)//评估函数
{
    double score = 0;
    score = 12 * pow(my_path_number, my_block_number/10) - my_block_number * pow(enemy_path_number, 10);
    return score;
}

/*randomwalk示例
QuoridorUtils::Location randomWalk(const QuoridorUtils::Location& myLoc, const QuoridorUtils::Location& enemyLoc) {
    bool directions[4];
    directions[0] = myLoc.y < QuoridorUtils::SIZE;           // 是否可以向上走
    directions[1] = myLoc.y > 0;                             // 是否可以向下走
    directions[2] = myLoc.x > 0;                             // 是否可以向左走
    directions[3] = myLoc.x < QuoridorUtils::SIZE;           // 是否可以向右走
    for (auto block : blocks) {                        // 遍历挡板列表, 找到被阻挡的方向
        if (block.isH()) {                                   // 水平方向挡板, start 与 stop 的 y 相等
            if (block.start.x == myLoc.x - 1 ||
                block.start.x == myLoc.x - 2) {              // 可能挡路的挡板
                if (block.start.y == myLoc.y) {
                    directions[0] = false;
                } else if (block.start.y == myLoc.y - 1) {
                    directions[1] = false;
                }
            }
        }
        if (block.isV()) {                                   // 竖直方向挡板, start 与 stop 的 x 相等
            if (block.start.y == myLoc.y - 1 ||
                block.start.y == myLoc.y - 2) {              // 可能挡路的挡板
                if (block.start.x == myLoc.x) {
                    directions[3] = false;
                } else if (block.start.x == myLoc.x - 1) {
                    directions[2] = false;
                }
            }
        }
    }
    int optionsCount = directions[0] + directions[1] +
                       directions[2] + directions[3];        // 规则不能堵死棋子, 必定大于等于1
    int tmp = rand() % optionsCount;                         // 随机一个 [0, optionsCount - 1] 的整数
    int directionIndex;                                      // 找出随机方向的下标
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
    case 0:   // 向上走
        nextLoc.y++;
        break;
    case 1:   // 向下走
        nextLoc.y--;
        break;
    case 2:   // 向左走
        nextLoc.x--;
        break;
    case 3:   // 向右走
        nextLoc.x++;
        break;
    default: ;
    }
    if (nextLoc.distance(enemyLoc) == 0) {                   // 下一步是敌军位置则应跳过敌军棋子
        nextLoc.x = -1;                                      // 此处不做实现, 默认下一步空操作
        nextLoc.y = -1;
    }
    return nextLoc;
}
// 面向过程实现结束
*/

/*nextStep示例
namespace QuoridorUtils {
// 面向过程实现开始
Step MyPlayer::nextStep(const ChessboardChange& newChange) {
    // 须知: 本示例代码仅作为 API 使用以及游戏规则了解范例, 甚至保证不了正确性, 切勿照抄照搬
    if (targetY == 0) {                                // 判断并记录自己的目标
        const auto d = std::chrono::system_clock::now().time_since_epoch();
        const int nanosecond = (std::chrono::nanoseconds(d).count() / 100) % int64_t(INT32_MAX);
        srand(nanosecond);
        if (newChange.myLoc == PLAYER0_LOC) {                // 己方初始坐标为 (5,1) 则目标为 (x,9)
            targetY = PLAYER1_LOC.y;
        } else {                                             // 己方初始坐标为 (5,9) 则目标为 (x,1)
            targetY = PLAYER0_LOC.y;
        }
    }
    std::cout << newChange;                     // 输出接收到的数据到控制台显示
    if (!newChange.newEnemyBlockBar.isNan()) {               // 对方放置了挡板
        BlockBar tmp = newChange.newEnemyBlockBar;
        tmp.normalization();                                 // 规范为 start 坐标小于 stop 坐标的形式
        blocks.push_back(tmp);                         // 存储挡板
    }
    Step step;                                               // 初始化 step 默认不移动不放板
    step.myNewLoc = randomWalk(newChange.myLoc, newChange.enemyLoc);
    std::cout << " -> " << step << std::endl;                          // 输出我的决策到控制台显示
    return step;
}

void MyPlayer::restart() {
    blocks.clear();
    targetY = 0;
}
// 面向过程实现结束
}
*/