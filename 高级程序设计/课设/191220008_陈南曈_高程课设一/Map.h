#pragma once
#include <iostream>
#include <vector>
#include "UI.h"
#include "Plant.h"
//#include "Zombie.h"

class Zombie;

using namespace std;

const int PLANT_TYPE_MAX = 2; // 植物种类数
enum Plant_Type { SUNFLOWER, PEASHOOTER }; // 植物种类

class Sward
{
private:
	int loc_x; // 草地原点的实际x坐标
	int loc_y; // 草地原点的实际y坐标
	Plant* plant; // 草地上的植物
	vector<Zombie*> zombies; // 草地上的僵尸
	bool select_flag; // 是否被选中
	bool eat_flag; // 是否正在被吃（植物闪烁）
	bool update_flag; // 是否需要更新草地
public:
	Sward();
	void Locate(int num_x, int num_y); // 花园坐标与实际坐标的转换
	void Print(); // 打印草地上的内容
	void Print_Select(); // 打印选中标志
	void Print_Plant(); // 打印草地上的植物
	void Print_Zombie(); // 打印草地上的僵尸
	void Add_Plant(Plant* _plant); // 添加植物
	void Delete_Plant(); // 删除植物
	void Add_Zombie(Garden& garden, Zombie* _zombie); // 添加僵尸
	void Delete_Zombie(Garden& garden, Zombie* _zombie); // 删除僵尸

	friend class Garden;
	friend class Zombie;
	friend class Pea;
	friend class Game;
	friend class Store;
	friend class Peashooter;
};

class Garden
{
private:
	Sward swards[SWARD_NUM_Y][SWARD_NUM_X + 1]; // 所有草地
public:
	Garden();
	void Print(); // 打印花园
	void Update_Swards(); // 更新所有草地 

	friend class Zombie;
	friend class Pea;
	friend class Game;
	friend class Store;
	friend class Peashooter;
};