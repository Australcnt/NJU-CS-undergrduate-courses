#pragma once
#include <iostream>
#include "UI.h"
//#include "Game.h"

class Game;

using namespace std;

const int PEA_SINGLE_MOVE = 2; // 豌豆单步移动距离

class Pea
{
protected:
	string name; // 豌豆名字
	int speed; // 豌豆速度
	int attack; // 豌豆攻击力
	int color; // 豌豆颜色
	int loc_x; // 豌豆实际x坐标
	int loc_y; // 豌豆实际y坐标
	int num_x; // 豌豆花园x坐标
	int num_y; // 豌豆花园y坐标
	int timer; // 计时器
public:
	Pea();
	Pea(int _loc_x, int _loc_y);
	void Locate(); // 实际坐标与花园坐标的转换
	bool Move(Game& game); // 豌豆移动
	virtual void Hit(Game& game); // 豌豆击中僵尸
	void Print(Garden &garden); // 打印豌豆

	friend class Plant;
	friend class Game;
	friend class Peashooter;
	friend class Repeater;
	friend class Snowpea;
};

class SnowPea :public Pea
{
private:
public:
	SnowPea();
	SnowPea(int _loc_x, int _loc_y) :Pea(_loc_x, _loc_y) { color = PEASNOW_COLOR; };
	void Hit(Game& game); // 豌豆击中僵尸(冰冻)
};