#pragma once
#include <iostream>
#include <string>
#include "UI.h"
//#include "Game.h"

class Game;
class Garden;

using namespace std;

class Plant
{
protected:
	string name; // 植物名字
	int hp; // 植物血量
	int hp_left; // 植物剩余血量
	int num_x; // 所在草地的花园x坐标
	int num_y; // 所在草地的花园y坐标
	int timer; // 计时器
	int color; //植物输出颜色
	void Set(int _num_x, int _num_y); // 设置植物的花园坐标
public:
	Plant();
	virtual void Functioning(Game& game){} // 植物功能函数

	friend class Sward;
	friend class Zombie;
	friend class Game;
	friend class Store;
};

class Peashooter :public Plant
{
private:
	int pea_speed; // 发射豌豆的速度
public:
	Peashooter() { name = "豌豆射手"; hp = hp_left = 100; color = PEASHOOTER_COLOR, pea_speed = 30; }
	void Functioning(Game& game); // 发射豌豆
	bool Check_Zombie(Garden& garden); // 判断该行是否有僵尸
};

class Sunflower :public Plant
{
private:
	int sunshine_speed; // 阳光产生速度
	int sunshine_produce; // 单次阳光的产生量
public:
	Sunflower() { name = "向日葵"; hp = hp_left = 100; sunshine_speed = 30; color = SUNFLOWER_COLOR, sunshine_produce = 25; }
	void Functioning(Game& game); // 产生阳光
};