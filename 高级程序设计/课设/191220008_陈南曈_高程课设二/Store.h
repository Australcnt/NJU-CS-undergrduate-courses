#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "UI.h"
//#include "Game.h"
#include "Map.h"

class Game;

using namespace std;

class PlantCard
{
private:
	int index; // 商品序号
	string name; // 商品名字
	int price; // 商品价格
	int cd; // 商品冷却时间
	int timer; // 计时器
	bool select_flag; // 是否被选中
	bool cooldown_flag; // 是否正在冷却
	bool update_flag; // 是否需要更新商品信息
public:
	void Set(int _index, string _name, int price, int cd); // 设置商品相关参数
	void Print(); // 打印商品
	void Cool_Down(); // 冷却商品

	friend class UI;
	friend class Store;
	friend class Game;
};

class Store
{
private:
	int sunshine; // 阳光数
	int sunshine_speed; // 自然阳光产生速度
	int sunshine_produce; // 单次产生的自然阳光数
	bool sunshine_update_flag; // 是否需要更新阳光数
	int timer; // 计时器
	PlantCard plant_card[PLANT_TYPE_MAX]; // 商品序列
public:
	Store();
	void Print(); // 打印商店
	bool Perchase(int plant_type, int num_x, int num_y, Garden& garden); // 购买商品
	Plant* Type_To_Plant(int plant_type, int num_x, int num_y); // 商品序号对应植物
	void Sunshine_Produce(Game& game); // 产生自然阳光
	void Update_Sunshine(Game& game); // 更新阳光数

	friend class UI;
	friend class Game;
	friend class Sunflower;
};