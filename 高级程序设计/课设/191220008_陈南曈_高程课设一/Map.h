#pragma once
#include <iostream>
#include <vector>
#include "UI.h"
#include "Plant.h"
//#include "Zombie.h"

class Zombie;

using namespace std;

const int PLANT_TYPE_MAX = 2; // ֲ��������
enum Plant_Type { SUNFLOWER, PEASHOOTER }; // ֲ������

class Sward
{
private:
	int loc_x; // �ݵ�ԭ���ʵ��x����
	int loc_y; // �ݵ�ԭ���ʵ��y����
	Plant* plant; // �ݵ��ϵ�ֲ��
	vector<Zombie*> zombies; // �ݵ��ϵĽ�ʬ
	bool select_flag; // �Ƿ�ѡ��
	bool eat_flag; // �Ƿ����ڱ��ԣ�ֲ����˸��
	bool update_flag; // �Ƿ���Ҫ���²ݵ�
public:
	Sward();
	void Locate(int num_x, int num_y); // ��԰������ʵ�������ת��
	void Print(); // ��ӡ�ݵ��ϵ�����
	void Print_Select(); // ��ӡѡ�б�־
	void Print_Plant(); // ��ӡ�ݵ��ϵ�ֲ��
	void Print_Zombie(); // ��ӡ�ݵ��ϵĽ�ʬ
	void Add_Plant(Plant* _plant); // ���ֲ��
	void Delete_Plant(); // ɾ��ֲ��
	void Add_Zombie(Garden& garden, Zombie* _zombie); // ��ӽ�ʬ
	void Delete_Zombie(Garden& garden, Zombie* _zombie); // ɾ����ʬ

	friend class Garden;
	friend class Zombie;
	friend class Pea;
	friend class Game;
	friend class Store;
	friend class Peashooter;
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
	friend class Pea;
	friend class Game;
	friend class Store;
	friend class Peashooter;
};