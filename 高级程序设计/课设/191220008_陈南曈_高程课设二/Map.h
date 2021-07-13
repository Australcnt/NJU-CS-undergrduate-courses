#pragma once
#include <iostream>
#include <vector>
#include "UI.h"
#include "Plant.h"
//#include "Zombie.h"

class Zombie;

using namespace std;

class Sward
{
private:
	int loc_x; // �ݵ�ԭ���ʵ��x����
	int loc_y; // �ݵ�ԭ���ʵ��y����
	Plant* plant; // �ݵ��ϵ�ֲ��
	Plant* extra_plant; // �ݵ��ϸ��ӵ�ֲ��
	vector<Zombie*> zombies; // �ݵ��ϵĽ�ʬ
	bool select_flag; // �Ƿ�ѡ��
	bool eat_flag; // �Ƿ����ڱ���
	bool update_flag; // �Ƿ���Ҫ���²ݵ�
	bool bomb_flag; // �Ƿ����ڱ�ը
	int bomb_timer; // ��ը��ʱ��
	int bomb_time; // ��ըʱ��
public:
	Sward();
	void Locate(int num_x, int num_y); // ��԰������ʵ�������ת��
	void Print(); // ��ӡ�ݵ��ϵ�����
	void Print_Select(); // ��ӡѡ�б�־
	void Print_Bomb(); // ��ӡ��ը��Ч
	void Print_Plant(); // ��ӡ�ݵ��ϵ�ֲ��
	void Print_Extra_Plant(); // ��ӡ�ݵ��ϵĸ���ֲ��
	void Print_Zombie(); // ��ӡ�ݵ��ϵĽ�ʬ
	void Add_Plant(Plant* _plant); // ���ֲ��
	void Delete_Plant(); // ɾ��ֲ��
	void Add_Extra_Plant(Plant* _extra_plant); // ��Ӹ���ֲ��
	void Delete_Extra_Plant(); // ɾ������ֲ��
	void Add_Zombie(Garden& garden, Zombie* _zombie); // ��ӽ�ʬ
	void Delete_Zombie(Garden& garden, Zombie* _zombie); // ɾ����ʬ

	friend class Garden;
	friend class Zombie;
	friend class Polevaultingzombie;
	friend class Jackintheboxzombie;
	friend class Catapultzombie;
	friend class Pea;
	friend class SnowPea;
	friend class Game;
	friend class Store;
	friend class Peashooter;
	friend class Repeater;
	friend class Snowpea;
	friend class Squash;
	friend class Cherrybomb;
	friend class Garlic;
};

class Garden
{
private:
	Sward swards[SWARD_NUM_Y][SWARD_NUM_X + 1]; // ���вݵ�
public:
	Garden();
	void Print(); // ��ӡ��԰
	void Update_Swards(); // �������вݵ� 

	friend class Zombie;
	friend class Polevaultingzombie;
	friend class Jackintheboxzombie;
	friend class Catapultzombie;
	friend class Pea;
	friend class SnowPea;
	friend class Game;
	friend class Store;
	friend class Peashooter;
	friend class Repeater;
	friend class Snowpea;
	friend class Squash;
	friend class Cherrybomb;
	friend class Garlic;
};