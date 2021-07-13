#pragma once
#include <iostream>
#include <string>
#include "UI.h"
//#include "Game.h"

class Game;
class Garden;

using namespace std;

const int PLANT_TYPE_MAX = 10; // ֲ��������
enum Plant_Type { SUNFLOWER, PEASHOOTER, REPEATER, SNOWPEA, WALLNUT, TALLNUT, SQUASH, CHERRYBOMB, GARLIC, PUMPKIN };// ֲ������

class Plant
{
protected:
	string name; // ֲ������
	int hp; // ֲ��Ѫ��
	int hp_left; // ֲ��ʣ��Ѫ��
	int num_x; // ���ڲݵصĻ�԰x����
	int num_y; // ���ڲݵصĻ�԰y����
	int timer; // ��ʱ��
	int color; //ֲ�������ɫ
	void Set(int _num_x, int _num_y); // ����ֲ��Ļ�԰����
public:
	Plant();
	virtual bool Functioning(Game& game) { return true; } // ֲ�﹦�ܺ��� 

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
	int sunshine_speed; // ��������ٶ�
	int sunshine_produce; // ��������Ĳ�����
public:
	Sunflower() { name = "���տ�"; hp = hp_left = 100; sunshine_speed = 30; color = SUNFLOWER_COLOR; sunshine_produce = 25; }
	bool Functioning(Game& game); // ��������
};

class Peashooter :public Plant
{
private:
	int pea_speed; // �����㶹���ٶ�
public:
	Peashooter() { name = "�㶹����"; hp = hp_left = 100; color = PEASHOOTER_COLOR; pea_speed = 30; }
	bool Functioning(Game& game); // �����㶹
	bool Check_Zombie(Garden& garden); // �жϸ����Ƿ��н�ʬ
};

class Repeater :public Plant
{
private:
	int pea_speed; // �����㶹���ٶ�
	bool shoot_flag; // �Ƿ���Ҫ����ڶ����㶹
public:
	Repeater() { name = "˫������"; hp = hp_left = 100; color = REPEATER_COLOR; pea_speed = 30; shoot_flag = false; }
	bool Functioning(Game& game);
	bool Check_Zombie(Garden& garden); // �жϸ����Ƿ��н�ʬ
};

class Snowpea :public Plant
{
private:
	int pea_speed; // �����㶹���ٶ�
public:
	Snowpea() { name = "��������"; hp = hp_left = 100; color = SNOWPEA_COLOR; pea_speed = 30; }
	bool Functioning(Game& game);
	bool Check_Zombie(Garden& garden); // �жϸ����Ƿ��н�ʬ
};

class Wallnut :public Plant
{
private:
public:
	Wallnut() { name = "���ǽ"; hp = hp_left = 300; color = WALLNUT_COLOR;}
	bool Functioning(Game& game);
};

class Tallnut :public Plant
{
private:
public:
	Tallnut() { name = "�߼��"; hp = hp_left = 600; color = TALLNUT_COLOR;}
	bool Functioning(Game& game);
};

class Squash :public Plant
{
private:
	int bomb_speed; // ����ֲ����ը��ʱ��
public:
	Squash() { name = "�ѹ�"; hp = hp_left = 100; color = SQUASH_COLOR; bomb_speed = 5; }
	bool Functioning(Game& game);
};

class Cherrybomb :public Plant
{
private:
	int bomb_speed; // ����ֲ����ը��ʱ��
public:
	Cherrybomb() { name = "ӣ��ը��"; hp = hp_left = 100; color = CHERRYBOMB_COLOR; bomb_speed = 10; }
	bool Functioning(Game& game);
};

class Garlic :public Plant
{
private:
public:
	Garlic() { name = "����"; hp = hp_left = 125; color = GARLIC_COLOR;}
	bool Functioning(Game& game);
};

class Pumpkin :public Plant
{
private:
public:
	Pumpkin() { name = "�Ϲ�ͷ"; hp = hp_left = 300; color = PUMPKIN_COLOR;}
	bool Functioning(Game& game);
};