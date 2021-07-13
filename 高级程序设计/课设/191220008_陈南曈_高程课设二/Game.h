#pragma once
#include <iostream>
#include <time.h>
#include <stdio.h>
#include "UI.h"
#include "Map.h"
#include "Store.h"
#include "Pea.h"
#include "Zombie.h"

using namespace std;

enum STATE { RUNNING, PERCHASING, WEEDING, PAUSING }; // 游戏运行状态
const int SLEEP_TIME = 100; // 时钟周期（毫秒）

class Game
{
private:
	UI ui; // 当前UI
	Garden garden; // 当前花园
	Store store; // 当前商店
	STATE state; // 游戏状态
	int num_x; // 选择的草地的x坐标
	int num_y; // 选择的草地的y坐标
	vector<Pea*> peas; // 所有豌豆
	int plant_type; // 选择的植物种类
	int score; // 分数
	bool score_update_flag; // 是否需要更新分数
	bool tip_update_flag; // 是否需要更新提示信息
	int timer; // 计时器
	int zombie_speed; // 僵尸产生速度
public:
	Game();
	void Menu(); // 主菜单
	void Game_Start(); // 开始游戏
	void Game_Over(); // 游戏结束
	void Quit(); // 退出游戏

	void Running(); // 正常运行
	void Perchasing(); // 购买植物
	void Weeding(); // 移除植物
	void Pausing(); // 暂停游戏

	void Add_Pea(Pea* pea); // 添加豌豆
	void Delete_Pea(Pea* pea); //删除豌豆

	void Tip(); // 显示提示信息

	void Create_Zombie(); // 生成僵尸

	void Update_Score(); // 更新分数

	friend class Store;
	friend class Zombie;
	friend class Polevaultingzombie;
	friend class Jackintheboxzombie;
	friend class Catapultzombie;
	friend class Pea;
	friend class SnowPea;
	friend class Peashooter;
	friend class Sunflower;
	friend class Repeater;
	friend class Snowpea;
	friend class Squash;
	friend class Cherrybomb;
	friend class Garlic;
};