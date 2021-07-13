//#include "Pea.h"
#include "Game.h"

#include <iostream>
using namespace std;

Pea::Pea(int _loc_x, int _loc_y)
{
	name = "��";
	speed = 2;
	attack = 25;
	color = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	loc_x = _loc_x;
	loc_y = _loc_y;
	timer = 0;
	Locate();
}

void Pea::Locate() // ȷ���㶹���ڵĲݵ�
{
	if (loc_x + 1 < SWARD_NUM_X * (SWARD_LENGTH_X + 1))
		num_x = (loc_x + 1) / (SWARD_LENGTH_X + 1);
	else
		num_x = 10;
	num_y = (loc_y - STORE_LENGTH_Y - 1) / (SWARD_LENGTH_Y + 1);
}

bool Pea::Move(Game& game) // �㶹�ƶ�
{
	if (timer + 1 == speed)
	{
		
		//if (loc_x + PEA_SINGLE_MOVE >= WINDOW_LENGTH_X - 1)
		if (loc_x + PEA_SINGLE_MOVE >= (SWARD_NUM_X + 1) * (SWARD_LENGTH_X + 1) - 1)
		{
			UI::Move_Cursor(loc_x, loc_y);
			cout << "  ";
			//game.Delete_Pea(this);
			return true;
		}
		if (loc_x % (SWARD_LENGTH_X + 1) == 12)
		{
			if (!game.garden.swards[num_y][num_x].zombies.empty() && num_x != SWARD_NUM_X + 1)
			{
				UI::Move_Cursor(loc_x, loc_y);
				cout << "  ";
				Hit(game);
				//game.Delete_Pea(this);
				return true;
			}
		}
		loc_x += PEA_SINGLE_MOVE;
		Locate();
		if (!game.garden.swards[num_y][num_x].zombies.empty() && num_x != SWARD_NUM_X + 1)
		{
			UI::Move_Cursor(loc_x - PEA_SINGLE_MOVE, loc_y);
			cout << "  ";
			Hit(game);
			//game.Delete_Pea(this);
			return true;
		}
		Print(game.garden);
		timer = 0;
	}
	else
	{
		timer++;
	}
	return false;
}

void Pea::Hit(Game& game) // �㶹���н�ʬ
{
	game.garden.swards[num_y][num_x].zombies[0]->hp_left -= attack;
	if (game.garden.swards[num_y][num_x].zombies[0]->hp_left < 0)
	{
		game.garden.swards[num_y][num_x].zombies[0]->hp_left = 0;
		game.score += game.garden.swards[num_y][num_x].zombies[0]->kill_score;
		game.garden.swards[num_y][num_x].Delete_Zombie(game.garden, game.garden.swards[num_y][num_x].zombies[0]);
		//game.Update_Score();
		game.score_update_flag = true;
	}
	game.garden.swards[num_y][num_x].Print();
}

void Pea::Print(Garden& garden) // ��ӡ�㶹
{
	UI::Move_Cursor(loc_x - PEA_SINGLE_MOVE, loc_y);
	if ((loc_x - PEA_SINGLE_MOVE) % (SWARD_LENGTH_X + 1) == 0 && loc_x - PEA_SINGLE_MOVE != 150)
		cout << "# "; // ����ݵر߿�
	else if ((loc_x - PEA_SINGLE_MOVE + 1) % (SWARD_LENGTH_X + 1) == 0 && loc_x - PEA_SINGLE_MOVE + 1 != 150)
		cout << " #"; // ����ݵر߿�
	else
		cout << "  "; // ���ǰһ֡���㶹
	UI::Move_Cursor(loc_x, loc_y);
	cout << "  ";
	UI::Move_Cursor(loc_x, loc_y);
	UI::Print_With_Color(name, color);
	if (garden.swards[num_y][num_x].plant != NULL)
		garden.swards[num_y][num_x].update_flag = true;
}