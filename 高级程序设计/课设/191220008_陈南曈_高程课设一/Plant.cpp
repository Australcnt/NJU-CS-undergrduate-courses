//#include "Plant.h"
#include "Game.h"

#include <iostream>
using namespace std;

Plant::Plant()
{
	timer = 0;
}

void Plant::Set(int _num_x, int _num_y)
{
	num_x = _num_x;
	num_y = _num_y;
}

void Peashooter::Functioning(Game& game)
{

	{if (timer + 1 == pea_speed)
	{
		if (Check_Zombie(game.garden))
		{
			int loc_x = (SWARD_LENGTH_X + 1) * num_x + 12;
			int loc_y = (STORE_LENGTH_Y + 1) + (SWARD_LENGTH_Y + 1) * num_y + 4;
			Pea* pea = new Pea(loc_x, loc_y);
			game.peas.push_back(pea);

		}
		timer = 0;
	}
	else
	{
		timer++;
	}
	}
}

bool Peashooter::Check_Zombie(Garden& garden) // 判断该行是否有僵尸
{
	for (int i = num_x; i < SWARD_NUM_X; i++)
	{
		if (!garden.swards[num_y][i].zombies.empty())
			return true;
	}
	return false;
}

void Sunflower::Functioning(Game& game)
{
	
	if (timer + 1 == sunshine_speed)
	{
		game.store.sunshine += sunshine_produce;
		game.store.sunshine_update_flag = true;
		timer = 0;
	}
	else
	{
		timer++;
	}
}