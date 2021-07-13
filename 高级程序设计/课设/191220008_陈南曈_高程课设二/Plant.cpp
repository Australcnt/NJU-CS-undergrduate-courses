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

/*���տ�*/

bool Sunflower::Functioning(Game& game)
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
	return true;
}

/*�㶹����*/

bool Peashooter::Functioning(Game& game)
{
	if (timer + 1 == pea_speed)
	{
		if (Check_Zombie(game.garden))
		{
			int loc_x = (SWARD_LENGTH_X + 1) * num_x + 12 - PEA_SINGLE_MOVE;
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
	return true;
}

bool Peashooter::Check_Zombie(Garden& garden) // �жϸ����Ƿ��н�ʬ
{
	for (int i = num_x; i < SWARD_NUM_X; i++)
	{
		if (!garden.swards[num_y][i].zombies.empty())
			return true;
	}
	return false;
}

/*˫������*/

bool Repeater::Functioning(Game& game)
{
	if (timer + 1 == pea_speed)
	{
		if (Check_Zombie(game.garden))
		{
			int loc_x = (SWARD_LENGTH_X + 1) * num_x + 12 - PEA_SINGLE_MOVE;
			int loc_y = (STORE_LENGTH_Y + 1) + (SWARD_LENGTH_Y + 1) * num_y + 4;
			Pea* pea = new Pea(loc_x, loc_y);
			game.peas.push_back(pea);
			shoot_flag = true;
		}
		timer = 0;
	}
	else
	{
		if (timer + 1 == 6 && shoot_flag)
		{
			int loc_x = (SWARD_LENGTH_X + 1) * num_x + 12 - PEA_SINGLE_MOVE;
			int loc_y = (STORE_LENGTH_Y + 1) + (SWARD_LENGTH_Y + 1) * num_y + 4;
			Pea* pea = new Pea(loc_x, loc_y);
			game.peas.push_back(pea);
			shoot_flag = false;
		}
		timer++;
	}
	return true;
}

bool Repeater::Check_Zombie(Garden& garden) // �жϸ����Ƿ��н�ʬ
{
	for (int i = num_x; i < SWARD_NUM_X; i++)
	{
		if (!garden.swards[num_y][i].zombies.empty())
			return true;
	}
	return false;
}

/*��������*/

bool Snowpea::Functioning(Game& game)
{
	if (timer + 1 == pea_speed)
	{
		if (Check_Zombie(game.garden))
		{
			int loc_x = (SWARD_LENGTH_X + 1) * num_x + 12 - PEA_SINGLE_MOVE;
			int loc_y = (STORE_LENGTH_Y + 1) + (SWARD_LENGTH_Y + 1) * num_y + 4;
			SnowPea* snowpea = new SnowPea(loc_x, loc_y);
			game.peas.push_back(snowpea);
		}
		timer = 0;
	}
	else
	{
		timer++;
	}
	return true;
}

bool Snowpea::Check_Zombie(Garden& garden) // �жϸ����Ƿ��н�ʬ
{
	for (int i = num_x; i < SWARD_NUM_X; i++)
	{
		if (!garden.swards[num_y][i].zombies.empty())
			return true;
	}
	return false;
}

/*���ǽ*/

bool Wallnut::Functioning(Game& game)
{
	return true;
}

/*�߼��*/

bool Tallnut::Functioning(Game& game)
{
	return true;
}

/*�ѹ�*/

bool Squash::Functioning(Game& game)
{
	if (!game.garden.swards[num_y][num_x].zombies.empty())
	{
		if (timer + 1 == bomb_speed)
		{

			for (auto i = game.garden.swards[num_y][num_x].zombies.begin(); i < game.garden.swards[num_y][num_x].zombies.end(); )
			{
				i = game.garden.swards[num_y][num_x].zombies.erase(i);
			}
			timer = 0;
			// �����ը��Ч
			game.garden.swards[num_y][num_x].bomb_flag = true;
			game.garden.swards[num_y][num_x].update_flag = true;
			return false;
		}
		else
		{
			timer++;
		}
	}
	return true;
}

/*ӣ��ը��*/

bool Cherrybomb::Functioning(Game& game)
{
	if (timer + 1 == bomb_speed)
	{
		for (int i = num_y - 1; i <= num_y + 1; i++)
		{
			for (int j = num_x - 1; j <= num_x + 1; j++)
			{
				if (i >= 0 && i < SWARD_NUM_Y && j >= 0 && j < SWARD_NUM_X)
				{
					for (auto k = game.garden.swards[i][j].zombies.begin(); k < game.garden.swards[i][j].zombies.end(); )
					{
						k = game.garden.swards[i][j].zombies.erase(k);
						game.garden.swards[i][j].update_flag = true;
					}
					// �����ը��Ч
					game.garden.swards[i][j].bomb_flag = true;
					game.garden.swards[i][j].update_flag = true;
				}
				
			}
		}
		timer = 0;
		return false;
	}
	else
	{
		timer++;
	}
	return true;
}

/*����*/

bool Garlic::Functioning(Game& game)
{
	if(game.garden.swards[num_y][num_x].eat_flag)
	{
		int move_direction = -1 + rand() % 2 * 2;
		if (num_y == 0)
			move_direction = 1;
		else if (num_y == SWARD_NUM_Y - 1)
			move_direction = -1;
		Zombie* zombie_copy = NULL;
		if (game.garden.swards[num_y][num_x].zombies[0]->name == "��ͨ��ʬ")
			zombie_copy = new Zombie;
		else if (game.garden.swards[num_y][num_x].zombies[0]->name == "·�Ͻ�ʬ")
			zombie_copy = new Coneheadzombie;
		else if (game.garden.swards[num_y][num_x].zombies[0]->name == "������ʬ")
			zombie_copy = new Newspaperzombie;
		else if (game.garden.swards[num_y][num_x].zombies[0]->name == "�Ÿ˽�ʬ")
			zombie_copy = new Polevaultingzombie;
		else if (game.garden.swards[num_y][num_x].zombies[0]->name == "С��ʬ")
			zombie_copy = new Jackintheboxzombie;
		else if (game.garden.swards[num_y][num_x].zombies[0]->name == "Ͷʯ��ʬ")
			zombie_copy = new Catapultzombie;
		else
			zombie_copy = new Zombie;
		zombie_copy->name = game.garden.swards[num_y][num_x].zombies[0]->name;
		zombie_copy->hp = game.garden.swards[num_y][num_x].zombies[0]->hp;
		zombie_copy->hp_left = game.garden.swards[num_y][num_x].zombies[0]->hp_left;
		zombie_copy->attack = game.garden.swards[num_y][num_x].zombies[0]->attack;
		zombie_copy->move_speed = game.garden.swards[num_y][num_x].zombies[0]->move_speed;
		zombie_copy->kill_score = game.garden.swards[num_y][num_x].zombies[0]->kill_score;
		zombie_copy->num_x = game.garden.swards[num_y][num_x].zombies[0]->num_x;
		zombie_copy->num_y = game.garden.swards[num_y][num_x].zombies[0]->num_y + move_direction;
		zombie_copy->color = game.garden.swards[num_y][num_x].zombies[0]->color;
		zombie_copy->freezing_flag = game.garden.swards[num_y][num_x].zombies[0]->freezing_flag;
		zombie_copy->freezing_time = game.garden.swards[num_y][num_x].zombies[0]->freezing_time;
		zombie_copy->extra_flag = game.garden.swards[num_y][num_x].zombies[0]->extra_flag;

		game.garden.swards[num_y][num_x].Delete_Zombie(game.garden, game.garden.swards[num_y][num_x].zombies[0]);
		game.garden.swards[num_y + move_direction][num_x].Add_Zombie(game.garden, zombie_copy);
		game.garden.swards[num_y][num_x].eat_flag = false;
	}
	return true;
}

/*�Ϲ�ͷ*/

bool Pumpkin::Functioning(Game& game)
{
	return true;
}