#pragma once
#include <iostream>
#include <time.h>
#include <stdio.h>
#include "UI.h"
#include "Map.h"
#include "Store.h"
#include "Pea.h"
#include "Zombie.h"

using namespace std;

enum STATE { RUNNING, PERCHASING, WEEDING, PAUSING }; // ��Ϸ����״̬
const int SLEEP_TIME = 100; // ʱ�����ڣ����룩
const int ZOMBIE_TYPE_MAX = 1; // ��ʬ������
enum Zombie_Type { ZOMBIE }; // ��ʬ����
const int PEA_SINGLE_MOVE = 2; // �㶹�����ƶ�����


class Game
{
private:
	UI ui; // ��ǰUI
	Garden garden; // ��ǰ��԰
	Store store; // ��ǰ�̵�
	STATE state; // ��Ϸ״̬
	int num_x; // ѡ��Ĳݵص�x����
	int num_y; // ѡ��Ĳݵص�y����
	vector<Pea*> peas; // �����㶹
	int plant_type; // ѡ���ֲ������
	int score; // ����
	bool score_update_flag; // �Ƿ���Ҫ���·���
	int timer; // ��ʱ��
	int zombie_speed; // ��ʬ�����ٶ�
public:
	Game();
	void Menu(); // ���˵�
	void Game_Start(); // ��ʼ��Ϸ
	void Game_Over(); // ��Ϸ����
	void Quit(); // �˳���Ϸ

	void Running(); // ��������
	void Perchasing(); // ����ֲ��
	void Weeding(); // �Ƴ�ֲ��
	void Pausing(); // ��ͣ��Ϸ

	void Add_Pea(Pea* pea); // ����㶹
	void Delete_Pea(Pea* pea); //ɾ���㶹

	void Tip(); // ��ʾ��ʾ��Ϣ

	void Create_Zombie(); // ���ɽ�ʬ

	void Update_Score(); // ���·���

	friend class Store;
	friend class Zombie;
	friend class Pea;
	friend class Peashooter;
	friend class Sunflower;
};