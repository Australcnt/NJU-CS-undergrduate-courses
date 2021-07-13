#pragma once

#include <string>
#include<random>
#include "Map.h"
#include "Game.h"

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
public:
	Zombie();
	void Locate(Garden& garden, int index); // 花园坐标和实际坐标的转换
	void Set(Garden& garden, const string& _name = "普通僵尸", int _hp = 100, int _attack = 25, int _move_speed = 50, int _kill_score = 10, int _num_x = SWARD_NUM_X, int _num_y = rand() % SWARD_NUM_Y);  // 设置僵尸相关参数
	bool Move(Game& game); // 僵尸移动
	void Eat(Garden& garden); // 僵尸进食

	friend class Sward;
	friend class Pea;
	friend class Game;
};