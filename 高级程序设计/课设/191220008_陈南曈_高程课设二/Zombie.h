#pragma once

#include <string>
#include<random>
#include "Map.h"
#include "Game.h"

const int ZOMBIE_TYPE_MAX = 6; // 僵尸种类数
enum Zombie_Type { ZOMBIE, CONEHEADZOMBIE, NEWSPAPERZOMBIE, POLEVAULTINGZOMBIE, JACKINTHEBOXZOMBIE, CATAPULTZOMBIE }; // 僵尸种类

/*普通僵尸*/

class Zombie
{
protected:
	string name; // 僵尸名字
	int hp; // 僵尸血量
	int hp_left; // 僵尸剩余血量
	int attack; // 僵尸攻击力
	int move_speed; // 僵尸移动速度
	int timer; // 计时器
	int kill_score; // 击杀僵尸的得分
	int loc_x; // 僵尸的实际x坐标
	int loc_y; // 僵尸的实际y坐标
	int num_x; // 僵尸的花园x坐标
	int num_y; // 僵尸的花园y坐标
	int color; // 僵尸输出的颜色
	bool freezing_flag; // 是否被冰冻
	int freezing_time; // 被冰冻的时间
	int freezing_timer; // 被冰冻的计时器
	bool extra_flag; // 是否有额外的饰品
public:
	Zombie();
	void Locate(Garden& garden, int index); // 花园坐标和实际坐标的转换
	void Set(Garden& garden, const string& _name, int _hp, int _attack, int _move_speed, int _kill_score, int _num_x, int _num_y, int _freezing_time);  // 设置僵尸相关参数
	virtual bool Move(Game& game); // 僵尸移动
	void Eat(Garden& garden); // 僵尸进食

	friend class Sward;
	friend class Pea;
	friend class SnowPea;
	friend class Garlic;
	friend class Game;
};

/*路障僵尸*/

class Coneheadzombie :public Zombie
{
private:
public:
	Coneheadzombie() :Zombie() {}
	bool Move(Game& game); // 僵尸移动
};

/*读报僵尸*/

class Newspaperzombie :public Zombie
{
private:
	bool newspaper_flag; // 是否有报纸
public:
	Newspaperzombie() :Zombie() { newspaper_flag = true; }
	bool Move(Game& game); // 僵尸移动
};

/*撑杆僵尸*/

class Polevaultingzombie :public Zombie
{
private:
public:
	Polevaultingzombie() :Zombie() {}
	bool Move(Game& game); // 僵尸移动
};

/*小丑僵尸*/

class Jackintheboxzombie :public Zombie
{
private:
	bool bomb_flag; // 是否会爆炸
public:
	Jackintheboxzombie() :Zombie() {}
	bool Move(Game& game); // 僵尸移动
};

/*投石僵尸*/

class Catapultzombie :public Zombie
{
private:
	int stone;
	int stone_left;
public:
	Catapultzombie() :Zombie() { stone = stone_left = 10; }
	bool Move(Game& game); // 僵尸移动
	int Check_Plant(Garden& garden); // 判断该行是否有植物
};