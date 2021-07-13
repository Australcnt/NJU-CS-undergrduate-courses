#pragma once

#include <string>
#include<random>
#include "Map.h"
#include "Game.h"

const int ZOMBIE_TYPE_MAX = 6; // ��ʬ������
enum Zombie_Type { ZOMBIE, CONEHEADZOMBIE, NEWSPAPERZOMBIE, POLEVAULTINGZOMBIE, JACKINTHEBOXZOMBIE, CATAPULTZOMBIE }; // ��ʬ����

/*��ͨ��ʬ*/

class Zombie
{
protected:
	string name; // ��ʬ����
	int hp; // ��ʬѪ��
	int hp_left; // ��ʬʣ��Ѫ��
	int attack; // ��ʬ������
	int move_speed; // ��ʬ�ƶ��ٶ�
	int timer; // ��ʱ��
	int kill_score; // ��ɱ��ʬ�ĵ÷�
	int loc_x; // ��ʬ��ʵ��x����
	int loc_y; // ��ʬ��ʵ��y����
	int num_x; // ��ʬ�Ļ�԰x����
	int num_y; // ��ʬ�Ļ�԰y����
	int color; // ��ʬ�������ɫ
	bool freezing_flag; // �Ƿ񱻱���
	int freezing_time; // ��������ʱ��
	int freezing_timer; // �������ļ�ʱ��
	bool extra_flag; // �Ƿ��ж������Ʒ
public:
	Zombie();
	void Locate(Garden& garden, int index); // ��԰�����ʵ�������ת��
	void Set(Garden& garden, const string& _name, int _hp, int _attack, int _move_speed, int _kill_score, int _num_x, int _num_y, int _freezing_time);  // ���ý�ʬ��ز���
	virtual bool Move(Game& game); // ��ʬ�ƶ�
	void Eat(Garden& garden); // ��ʬ��ʳ

	friend class Sward;
	friend class Pea;
	friend class SnowPea;
	friend class Garlic;
	friend class Game;
};

/*·�Ͻ�ʬ*/

class Coneheadzombie :public Zombie
{
private:
public:
	Coneheadzombie() :Zombie() {}
	bool Move(Game& game); // ��ʬ�ƶ�
};

/*������ʬ*/

class Newspaperzombie :public Zombie
{
private:
	bool newspaper_flag; // �Ƿ��б�ֽ
public:
	Newspaperzombie() :Zombie() { newspaper_flag = true; }
	bool Move(Game& game); // ��ʬ�ƶ�
};

/*�Ÿ˽�ʬ*/

class Polevaultingzombie :public Zombie
{
private:
public:
	Polevaultingzombie() :Zombie() {}
	bool Move(Game& game); // ��ʬ�ƶ�
};

/*С��ʬ*/

class Jackintheboxzombie :public Zombie
{
private:
	bool bomb_flag; // �Ƿ�ᱬը
public:
	Jackintheboxzombie() :Zombie() {}
	bool Move(Game& game); // ��ʬ�ƶ�
};

/*Ͷʯ��ʬ*/

class Catapultzombie :public Zombie
{
private:
	int stone;
	int stone_left;
public:
	Catapultzombie() :Zombie() { stone = stone_left = 10; }
	bool Move(Game& game); // ��ʬ�ƶ�
	int Check_Plant(Garden& garden); // �жϸ����Ƿ���ֲ��
};