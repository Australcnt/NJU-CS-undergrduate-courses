#pragma once
#include <iostream>
#include <string>
#include "UI.h"
//#include "Game.h"

class Game;
class Garden;

using namespace std;

const int PLANT_TYPE_MAX = 10; // 植物种类数
enum Plant_Type { SUNFLOWER, PEASHOOTER, REPEATER, SNOWPEA, WALLNUT, TALLNUT, SQUASH, CHERRYBOMB, GARLIC, PUMPKIN };// 植物种类

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
	virtual bool Functioning(Game& game) { return true; } // 植物功能函数 

	friend class Sward;
	friend class Zombie;
	friend class Polevaultingzombie;
	friend class Catapultzombie;
	friend class Game;
	friend class Store;
};

class Sunflower :public Plant
{
private:
	int sunshine_speed; // 阳光产生速度
	int sunshine_produce; // 单次阳光的产生量
public:
	Sunflower() { name = "向日葵"; hp = hp_left = 100; sunshine_speed = 30; color = SUNFLOWER_COLOR; sunshine_produce = 25; }
	bool Functioning(Game& game); // 产生阳光
};

class Peashooter :public Plant
{
private:
	int pea_speed; // 发射豌豆的速度
public:
	Peashooter() { name = "豌豆射手"; hp = hp_left = 100; color = PEASHOOTER_COLOR; pea_speed = 30; }
	bool Functioning(Game& game); // 发射豌豆
	bool Check_Zombie(Garden& garden); // 判断该行是否有僵尸
};

class Repeater :public Plant
{
private:
	int pea_speed; // 发射豌豆的速度
	bool shoot_flag; // 是否需要发射第二颗豌豆
public:
	Repeater() { name = "双发射手"; hp = hp_left = 100; color = REPEATER_COLOR; pea_speed = 30; shoot_flag = false; }
	bool Functioning(Game& game);
	bool Check_Zombie(Garden& garden); // 判断该行是否有僵尸
};

class Snowpea :public Plant
{
private:
	int pea_speed; // 发射豌豆的速度
public:
	Snowpea() { name = "寒冰射手"; hp = hp_left = 100; color = SNOWPEA_COLOR; pea_speed = 30; }
	bool Functioning(Game& game);
	bool Check_Zombie(Garden& garden); // 判断该行是否有僵尸
};

class Wallnut :public Plant
{
private:
public:
	Wallnut() { name = "坚果墙"; hp = hp_left = 300; color = WALLNUT_COLOR;}
	bool Functioning(Game& game);
};

class Tallnut :public Plant
{
private:
public:
	Tallnut() { name = "高坚果"; hp = hp_left = 600; color = TALLNUT_COLOR;}
	bool Functioning(Game& game);
};

class Squash :public Plant
{
private:
	int bomb_speed; // 从种植到爆炸的时间
public:
	Squash() { name = "窝瓜"; hp = hp_left = 100; color = SQUASH_COLOR; bomb_speed = 5; }
	bool Functioning(Game& game);
};

class Cherrybomb :public Plant
{
private:
	int bomb_speed; // 从种植到爆炸的时间
public:
	Cherrybomb() { name = "樱桃炸弹"; hp = hp_left = 100; color = CHERRYBOMB_COLOR; bomb_speed = 10; }
	bool Functioning(Game& game);
};

class Garlic :public Plant
{
private:
public:
	Garlic() { name = "大蒜"; hp = hp_left = 125; color = GARLIC_COLOR;}
	bool Functioning(Game& game);
};

class Pumpkin :public Plant
{
private:
public:
	Pumpkin() { name = "南瓜头"; hp = hp_left = 300; color = PUMPKIN_COLOR;}
	bool Functioning(Game& game);
};