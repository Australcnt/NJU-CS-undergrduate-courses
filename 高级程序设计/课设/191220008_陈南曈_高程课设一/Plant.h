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
	virtual void Functioning(Game& game){} // ֲ�﹦�ܺ���

	friend class Sward;
	friend class Zombie;
	friend class Game;
	friend class Store;
};

class Peashooter :public Plant
{
private:
	int pea_speed; // �����㶹���ٶ�
public:
	Peashooter() { name = "�㶹����"; hp = hp_left = 100; color = PEASHOOTER_COLOR, pea_speed = 30; }
	void Functioning(Game& game); // �����㶹
	bool Check_Zombie(Garden& garden); // �жϸ����Ƿ��н�ʬ
};

class Sunflower :public Plant
{
private:
	int sunshine_speed; // ��������ٶ�
	int sunshine_produce; // ��������Ĳ�����
public:
	Sunflower() { name = "���տ�"; hp = hp_left = 100; sunshine_speed = 30; color = SUNFLOWER_COLOR, sunshine_produce = 25; }
	void Functioning(Game& game); // ��������
};