#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "UI.h"
//#include "Game.h"
#include "Map.h"

class Game;

using namespace std;

class PlantCard
{
private:
	int index; // ��Ʒ���
	string name; // ��Ʒ����
	int price; // ��Ʒ�۸�
	int cd; // ��Ʒ��ȴʱ��
	int timer; // ��ʱ��
	bool select_flag; // �Ƿ�ѡ��
	bool cooldown_flag; // �Ƿ�������ȴ
	bool update_flag; // �Ƿ���Ҫ������Ʒ��Ϣ
public:
	void Set(int _index, string _name, int price, int cd); // ������Ʒ��ز���
	void Print(); // ��ӡ��Ʒ
	void Cool_Down(); // ��ȴ��Ʒ

	friend class UI;
	friend class Store;
	friend class Game;
};

class Store
{
private:
	int sunshine; // ������
	int sunshine_speed; // ��Ȼ��������ٶ�
	int sunshine_produce; // ���β�������Ȼ������
	bool sunshine_update_flag; // �Ƿ���Ҫ����������
	int timer; // ��ʱ��
	PlantCard plant_card[PLANT_TYPE_MAX]; // ��Ʒ����
public:
	Store();
	void Print(); // ��ӡ�̵�
	bool Perchase(int plant_type, int num_x, int num_y, Garden& garden); // ������Ʒ
	Plant* Type_To_Plant(int plant_type, int num_x, int num_y); // ��Ʒ��Ŷ�Ӧֲ��
	void Sunshine_Produce(Game& game); // ������Ȼ����
	void Update_Sunshine(Game& game); // ����������

	friend class UI;
	friend class Game;
	friend class Sunflower;
};