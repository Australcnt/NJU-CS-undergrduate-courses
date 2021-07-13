#include "Zombie.h"
//#include "Game.h"

#include <iostream>
using namespace std;

Zombie::Zombie()
{
	timer = 0;
}

void Zombie::Set(Garden& garden, const string& _name, int _hp, int _attack, int _move_speed, int _kill_score, int _num_x, int _num_y)
{
	name = _name;
	hp = hp_left = _hp;
	attack = _attack;
	move_speed = _move_speed;
	kill_score = _kill_score;
	num_x = _num_x;
	num_y = _num_y;

}

void Zombie::Locate(Garden& garden, int index)
{
	if (garden.swards[num_y][num_x].plant == NULL)
	{
		if (garden.swards[num_y][num_x].zombies.size() == 1)
		{
			loc_x = num_x * (SWARD_LENGTH_X + 1) + 4;
			loc_y = (STORE_LENGTH_Y + 1) + num_y * (SWARD_LENGTH_Y + 1) + 3;
		}
		else if (garden.swards[num_y][num_x].zombies.size() == 2)
		{
			loc_x = num_x * (SWARD_LENGTH_X + 1) + 4;
			loc_y = (STORE_LENGTH_Y + 1) + num_y * (SWARD_LENGTH_Y + 1) + 2 * (index + 1);
		}
		else
		{
			loc_x = num_x * (SWARD_LENGTH_X + 1) + 4;
			loc_y = (STORE_LENGTH_Y + 1) + num_y * (SWARD_LENGTH_Y + 1) + 3;
		}
	}
	else
	{
		loc_x = num_x * (SWARD_LENGTH_X + 1) + 4;
		loc_y = (STORE_LENGTH_Y + 1) + num_y * (SWARD_LENGTH_Y + 1) + 5;
	}
}

bool Zombie::Move(Game& game)
{
	if (timer + 1 == move_speed)
	{
		if (game.garden.swards[num_y][num_x].eat_flag)
		{
			Eat(game.garden);
		}
		else
		{
			if (game.garden.swards[num_y][num_x].plant != NULL)
			{
				game.garden.swards[num_y][num_x].eat_flag = true;
				Eat(game.garden);
				return false;
			}
			num_x--;
			if (num_x < 0)
				game.Game_Over();
			else
			{
				Zombie* zombie_copy = new Zombie;
				zombie_copy->name = name;
				zombie_copy->hp = hp;
				zombie_copy->hp_left = hp_left;
				zombie_copy->attack = attack;
				zombie_copy->move_speed = move_speed;
				zombie_copy->kill_score = kill_score;
				zombie_copy->num_x = num_x;
				zombie_copy->num_y = num_y;
				
				game.garden.swards[num_y][num_x].Add_Zombie(game.garden, zombie_copy);
				//for (auto i = game.garden.swards[num_y][num_x].zombies.begin(); i < game.garden.swards[num_y][num_x].zombies.end(); i++)
				//	(*i)->Locate(game.garden);
				//game.garden.swards[num_y][num_x].update_flag = true;
				game.garden.swards[num_y][num_x + 1].update_flag = true;
				//game.garden.swards[num_y][num_x].Add_Zombie(game.garden, this);
				//game.garden.swards[num_y][num_x + 1].Delete_Zombie(game.garden, this);
				return true;
			}
		}
		timer = 0;
	}
	else
	{
		timer++;
	}
	return false;
}

void Zombie::Eat(Garden& garden)
{
	garden.swards[num_y][num_x].eat_flag = true;
	garden.swards[num_y][num_x].plant->hp_left -= attack;
	garden.swards[num_y][num_x].update_flag = true;
	if (garden.swards[num_y][num_x].plant->hp_left < 0)
	{
		garden.swards[num_y][num_x].plant->hp_left = 0;
		garden.swards[num_y][num_x].Delete_Plant();
		garden.swards[num_y][num_x].eat_flag = false;
	}
}