//#include "Pea.h"
#include "Game.h"

#include <iostream>
using namespace std;


Pea::Pea()
{
	;
}

Pea::Pea(int _loc_x, int _loc_y)
{
	name = "¡ñ";
	speed = 1;
	attack = 25;
	color = PEA_COLOR;
	loc_x = _loc_x;
	loc_y = _loc_y;
	timer = 0;
	Locate();
}

void Pea::Locate() // È·¶¨Íã¶¹ËùÔÚµÄ²ÝµØ
{
	if (loc_x + 1 < SWARD_NUM_X * (SWARD_LENGTH_X + 1))
		num_x = (loc_x + 1) / (SWARD_LENGTH_X + 1);
	else
		num_x = 10;
	num_y = (loc_y - STORE_LENGTH_Y - 1) / (SWARD_LENGTH_Y + 1);
}

bool Pea::Move(Game& game) // Íã¶¹ÒÆ¶¯
{
	if (timer + 1 == speed)
	{
		//if (loc_x + PEA_SINGLE_MOVE >= WINDOW_LENGTH_X - 1)
		if (loc_x + PEA_SINGLE_MOVE >= (SWARD_NUM_X + 1) * (SWARD_LENGTH_X + 1) - 1)
		{
			UI::Move_Cursor(loc_x, loc_y);
			cout << "  ";
			//game.Delete_Pea(this);
			return false;
		}
		if (loc_x % (SWARD_LENGTH_X + 1) == 12)
		{
			if (!game.garden.swards[num_y][num_x].zombies.empty() && num_x != SWARD_NUM_X + 1)
			{
				UI::Move_Cursor(loc_x, loc_y);
				cout << "  ";
				Hit(game);
				//game.Delete_Pea(this);
				return false;
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
			return false;
		}
		Print(game.garden);
		timer = 0;
	}
	else
	{
		timer++;
	}
	return true;
}

void Pea::Hit(Game& game) // Íã¶¹»÷ÖÐ½©Ê¬
{
	game.garden.swards[num_y][num_x].zombies[0]->hp_left -= attack;
	if (game.garden.swards[num_y][num_x].zombies[0]->hp_left < 0)
	{
		game.garden.swards[num_y][num_x].zombies[0]->hp_left = 0;
		game.score += game.garden.swards[num_y][num_x].zombies[0]->kill_score;
		game.garden.swards[num_y][num_x].Delete_Zombie(game.garden, game.garden.swards[num_y][num_x].zombies[0]);
		game.garden.swards[num_y][num_x].eat_flag = false;
		//game.Update_Score();
		game.score_update_flag = true;
	}
	game.garden.swards[num_y][num_x].update_flag = true;
	game.garden.swards[num_y][num_x].Print();
}

void Pea::Print(Garden& garden) // ´òÓ¡Íã¶¹
{
	UI::Move_Cursor(loc_x - PEA_SINGLE_MOVE, loc_y);
	if ((loc_x - PEA_SINGLE_MOVE) % (SWARD_LENGTH_X + 1) == 0 && loc_x - PEA_SINGLE_MOVE != 150)
		cout << "# "; // ²¹Æë²ÝµØ±ß¿ò
	else if ((loc_x - PEA_SINGLE_MOVE + 1) % (SWARD_LENGTH_X + 1) == 0 && loc_x - PEA_SINGLE_MOVE + 1 != 150)
		cout << " #"; // ²¹Æë²ÝµØ±ß¿ò
	else
		cout << "  "; // Çå¿ÕÇ°Ò»Ö¡µÄÍã¶¹
	int last_num_x = 0;
	int last_num_y = num_y;
	if (loc_x - PEA_SINGLE_MOVE + 1 < SWARD_NUM_X * (SWARD_LENGTH_X + 1))
		last_num_x = (loc_x - PEA_SINGLE_MOVE + 1) / (SWARD_LENGTH_X + 1);
	else
		last_num_x = 9;
	if (last_num_x == 9 || garden.swards[last_num_y][last_num_x].plant != NULL || !garden.swards[last_num_y][last_num_x].zombies.empty())
		//garden.swards[last_num_y][last_num_x].update_flag = true;
		garden.swards[last_num_y][last_num_x].Print();
	UI::Move_Cursor(loc_x, loc_y);
	cout << "  ";
	UI::Move_Cursor(loc_x, loc_y);
	UI::Print_With_Color(name, color);
}

SnowPea::SnowPea()
{
	color = PEASNOW_COLOR;
}

void SnowPea::Hit(Game& game) // Íã¶¹»÷ÖÐ(±ù¶³)
{
	game.garden.swards[num_y][num_x].zombies[0]->hp_left -= attack;
	if (!game.garden.swards[num_y][num_x].zombies[0]->freezing_flag)
		game.garden.swards[num_y][num_x].zombies[0]->move_speed *= 2;
	game.garden.swards[num_y][num_x].zombies[0]->freezing_flag = true;
	game.garden.swards[num_y][num_x].zombies[0]->color = FREEZING_COLOR;
	game.garden.swards[num_y][num_x].zombies[0]->freezing_timer = 0;
	if (game.garden.swards[num_y][num_x].zombies[0]->hp_left < 0)
	{
		game.garden.swards[num_y][num_x].zombies[0]->hp_left = 0;
		game.score += game.garden.swards[num_y][num_x].zombies[0]->kill_score;
		game.garden.swards[num_y][num_x].Delete_Zombie(game.garden, game.garden.swards[num_y][num_x].zombies[0]);
		game.garden.swards[num_y][num_x].eat_flag = false;
		//game.Update_Score();
		game.score_update_flag = true;
	}
	game.garden.swards[num_y][num_x].update_flag = true;
	game.garden.swards[num_y][num_x].Print();
}