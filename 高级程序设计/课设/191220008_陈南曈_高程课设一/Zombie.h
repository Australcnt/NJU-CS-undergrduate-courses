#pragma once

#include <string>
#include<random>
#include "Map.h"
#include "Game.h"

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
public:
	Zombie();
	void Locate(Garden& garden, int index); // ��԰�����ʵ�������ת��
	void Set(Garden& garden, const string& _name = "��ͨ��ʬ", int _hp = 100, int _attack = 25, int _move_speed = 50, int _kill_score = 10, int _num_x = SWARD_NUM_X, int _num_y = rand() % SWARD_NUM_Y);  // ���ý�ʬ��ز���
	bool Move(Game& game); // ��ʬ�ƶ�
	void Eat(Garden& garden); // ��ʬ��ʳ

	friend class Sward;
	friend class Pea;
	friend class Game;
};