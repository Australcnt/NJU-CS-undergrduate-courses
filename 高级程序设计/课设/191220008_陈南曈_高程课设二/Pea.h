#pragma once
#include <iostream>
#include "UI.h"
//#include "Game.h"

class Game;

using namespace std;

const int PEA_SINGLE_MOVE = 2; // �㶹�����ƶ�����

class Pea
{
protected:
	string name; // �㶹����
	int speed; // �㶹�ٶ�
	int attack; // �㶹������
	int color; // �㶹��ɫ
	int loc_x; // �㶹ʵ��x����
	int loc_y; // �㶹ʵ��y����
	int num_x; // �㶹��԰x����
	int num_y; // �㶹��԰y����
	int timer; // ��ʱ��
public:
	Pea();
	Pea(int _loc_x, int _loc_y);
	void Locate(); // ʵ�������뻨԰�����ת��
	bool Move(Game& game); // �㶹�ƶ�
	virtual void Hit(Game& game); // �㶹���н�ʬ
	void Print(Garden &garden); // ��ӡ�㶹

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
	void Hit(Game& game); // �㶹���н�ʬ(����)
};