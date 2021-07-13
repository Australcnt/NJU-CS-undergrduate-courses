#include "Zombie.h"
//#include "Game.h"

#include <iostream>
using namespace std;

Zombie::Zombie()
{
	timer = 0;
	color = DEFAULT_COLOR;
	freezing_flag = false;
	freezing_timer = 0;
	extra_flag = true;
}

void Zombie::Set(Garden& garden, const string& _name, int _hp, int _attack, int _move_speed, int _kill_score, int _num_x, int _num_y, int _freezing_time)
{
	name = _name;
	hp = hp_left = _hp;
	attack = _attack;
	move_speed = _move_speed;
	kill_score = _kill_score;
	num_x = _num_x;
	num_y = _num_y;
	freezing_time = _freezing_time;
}

void Zombie::Locate(Garden& garden, int index)
{
	if (garden.swards[num_y][num_x].plant == NULL && garden.swards[num_y][num_x].extra_plant == NULL)
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
	if(freezing_flag)
	{
		color = FREEZING_COLOR;
		freezing_timer++;
		if (freezing_timer == freezing_time)
		{
			move_speed *= 2;
			freezing_timer = 0;
			freezing_flag = false;
			color = DEFAULT_COLOR;
		}
	}
	if (timer + 1 == move_speed)
	{
		if (game.garden.swards[num_y][num_x].plant != NULL || game.garden.swards[num_y][num_x].extra_plant != NULL)
		{
			game.garden.swards[num_y][num_x].eat_flag = true;
			Eat(game.garden);
		}
		else
		{
			num_x--;
			if (num_x < 0)
				game.Game_Over();
			else
			{
				Zombie* zombie_copy = NULL;
				if (name == "普通僵尸")
					zombie_copy = new Zombie;
				else if (name == "路障僵尸")
					zombie_copy = new Coneheadzombie;
				else if (name == "读报僵尸")
					zombie_copy = new Newspaperzombie;
				else if (name == "撑杆僵尸")
					zombie_copy = new Polevaultingzombie;
				else if (name == "小丑僵尸")
					zombie_copy = new Jackintheboxzombie;
				else if (name == "投石僵尸")
					zombie_copy = new Catapultzombie;
				else
					zombie_copy = new Zombie;
				zombie_copy->name = name;
				zombie_copy->hp = hp;
				zombie_copy->hp_left = hp_left;
				zombie_copy->attack = attack;
				zombie_copy->move_speed = move_speed;
				zombie_copy->kill_score = kill_score;
				zombie_copy->num_x = num_x;
				zombie_copy->num_y = num_y;
				zombie_copy->color = color;
				zombie_copy->freezing_flag = freezing_flag;
				zombie_copy->freezing_time = freezing_time;
				zombie_copy->extra_flag = extra_flag;

				game.garden.swards[num_y][num_x].Add_Zombie(game.garden, zombie_copy);
				game.garden.swards[num_y][num_x + 1].update_flag = true;
				return false;
			}
		}
		timer = 0;
	}
	else
	{
		timer++;
	}
	return true;
}

void Zombie::Eat(Garden& garden)
{
	if(garden.swards[num_y][num_x].extra_plant != NULL)
	{
		garden.swards[num_y][num_x].extra_plant->hp_left -= attack;
		garden.swards[num_y][num_x].update_flag = true;
		if (garden.swards[num_y][num_x].extra_plant->hp_left < 0)
		{
			garden.swards[num_y][num_x].extra_plant->hp_left = 0;
			garden.swards[num_y][num_x].Delete_Extra_Plant();
			garden.swards[num_y][num_x].eat_flag = false;
		}
	}
	else
	{
		garden.swards[num_y][num_x].plant->hp_left -= attack;
		garden.swards[num_y][num_x].update_flag = true;
		if (garden.swards[num_y][num_x].plant->hp_left < 0)
		{
			garden.swards[num_y][num_x].plant->hp_left = 0;
			garden.swards[num_y][num_x].Delete_Plant();
			garden.swards[num_y][num_x].eat_flag = false;
		}
	}
}

/*路障僵尸*/

bool Coneheadzombie::Move(Game& game)
{
	return Zombie::Move(game);
}

/*读报僵尸*/

bool Newspaperzombie::Move(Game& game)
{
	if (hp_left <= 100 && extra_flag)
	{
		move_speed /= 2;
		color = BACKGROUND_RED | DEFAULT_COLOR;
		extra_flag = false;
	}
	return Zombie::Move(game);
}

/*撑杆僵尸*/

bool Polevaultingzombie::Move(Game& game)
{
	if(extra_flag)
	{
		if (freezing_flag)
		{
			color = FREEZING_COLOR;
			freezing_timer++;
			if (freezing_timer == freezing_time)
			{
				move_speed /= 2;
				freezing_timer = 0;
				freezing_flag = false;
				color = DEFAULT_COLOR;
			}
		}
		if (timer + 1 == move_speed)
		{
			int move_step = 1;
			if (num_x >= 1 && (game.garden.swards[num_y][num_x - 1].plant != NULL || game.garden.swards[num_y][num_x - 1].extra_plant != NULL))
			{
				if(game.garden.swards[num_y][num_x - 1].plant != NULL && game.garden.swards[num_y][num_x - 1].plant->name == "高坚果")
					return Zombie::Move(game);
				num_x--;
				extra_flag = false;
				move_step = 2;
			}
			else if (game.garden.swards[num_y][num_x].plant != NULL || game.garden.swards[num_y][num_x].extra_plant != NULL)
			{
				if (game.garden.swards[num_y][num_x].plant != NULL && game.garden.swards[num_y][num_x].plant->name == "高坚果")
					return Zombie::Move(game);
				extra_flag = false;
			}
			num_x--;
			if (num_x < 0)
				game.Game_Over();
			else
			{
				Polevaultingzombie* zombie_copy = new Polevaultingzombie;
				zombie_copy->name = name;
				zombie_copy->hp = hp;
				zombie_copy->hp_left = hp_left;
				zombie_copy->attack = attack;
				zombie_copy->move_speed = move_speed;
				zombie_copy->kill_score = kill_score;
				zombie_copy->num_x = num_x;
				zombie_copy->num_y = num_y;
				zombie_copy->color = color;
				zombie_copy->freezing_flag = freezing_flag;
				zombie_copy->freezing_time = freezing_time;
				zombie_copy->extra_flag = extra_flag;

				game.garden.swards[num_y][num_x].Add_Zombie(game.garden, zombie_copy);
				game.garden.swards[num_y][num_x + move_step].update_flag = true;

				return false;
			}
			timer = 0;
		}
		else
		{
			timer++;
		}
		return true;
	}
	else
	{
		return Zombie::Move(game);
	}
}

/*小丑僵尸*/

bool Jackintheboxzombie::Move(Game& game)
{
	bomb_flag = (rand() % SWARD_NUM_X) < (SWARD_NUM_X - num_x);
	if(bomb_flag)
	{
		if (freezing_flag)
		{
			color = FREEZING_COLOR;
			freezing_timer++;
			if (freezing_timer == freezing_time)
			{
				move_speed *= 2;
				freezing_timer = 0;
				freezing_flag = false;
				color = DEFAULT_COLOR;
			}
		}
		if (timer + 1 == move_speed)
		{
			for (int i = num_y - 1; i <= num_y + 1; i++)
			{
				for (int j = num_x - 1; j <= num_x + 1; j++)
				{
					if (i >= 0 && i < SWARD_NUM_Y && j >= 0 && j < SWARD_NUM_X)
					{
						if (game.garden.swards[i][j].plant != NULL)
							game.garden.swards[i][j].Delete_Plant();
						if (game.garden.swards[i][j].extra_plant != NULL)
							game.garden.swards[i][j].Delete_Extra_Plant();
						// 输出爆炸特效
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
	else
	{
		return Zombie::Move(game);
	}
}

/*投石僵尸*/

bool Catapultzombie::Move(Game& game)
{
	if (freezing_flag)
	{
		color = FREEZING_COLOR;
		freezing_timer++;
		if (freezing_timer == freezing_time)
		{
			move_speed *= 2;
			freezing_timer = 0;
			freezing_flag = false;
			color = DEFAULT_COLOR;
		}
	}
	if (timer + 1 == move_speed)
	{
		int plant_num_x = Check_Plant(game.garden);
		if (num_x <= SWARD_NUM_X - 2 && extra_flag && plant_num_x != -1)
		{
			if (game.garden.swards[num_y][plant_num_x].extra_plant != NULL)
			{
				game.garden.swards[num_y][plant_num_x].extra_plant->hp_left -= attack;
				if (game.garden.swards[num_y][plant_num_x].extra_plant->hp_left < 0)
				{
					game.garden.swards[num_y][plant_num_x].extra_plant->hp_left = 0;
					game.garden.swards[num_y][plant_num_x].Delete_Extra_Plant();
				}
			}
			else
			{
				game.garden.swards[num_y][plant_num_x].plant->hp_left -= attack;
				if (game.garden.swards[num_y][plant_num_x].plant->hp_left < 0)
				{
					game.garden.swards[num_y][plant_num_x].plant->hp_left = 0;
					game.garden.swards[num_y][plant_num_x].Delete_Plant();
				}
			}
			stone_left--;
			if (stone_left == 0)
				extra_flag = false;
			game.garden.swards[num_y][plant_num_x].update_flag = true;
			// 输出爆炸特效
			game.garden.swards[num_y][plant_num_x].bomb_flag = true;
		}
		else
		{
			num_x--;
			if (num_x < 0)
				game.Game_Over();
			else
			{
				if (game.garden.swards[num_y][num_x].plant != NULL)
					game.garden.swards[num_y][num_x].Delete_Plant();
				if (game.garden.swards[num_y][num_x].extra_plant != NULL)
					game.garden.swards[num_y][num_x].Delete_Extra_Plant();
				if (num_x != SWARD_NUM_X - 1)
				{
					if (game.garden.swards[num_y][num_x + 1].plant != NULL)
						game.garden.swards[num_y][num_x + 1].Delete_Plant();
					if (game.garden.swards[num_y][num_x + 1].extra_plant != NULL)
						game.garden.swards[num_y][num_x + 1].Delete_Extra_Plant();
				}
				Catapultzombie* zombie_copy = new Catapultzombie;
				zombie_copy->name = name;
				zombie_copy->hp = hp;
				zombie_copy->hp_left = hp_left;
				zombie_copy->attack = attack;
				zombie_copy->move_speed = move_speed;
				zombie_copy->kill_score = kill_score;
				zombie_copy->num_x = num_x;
				zombie_copy->num_y = num_y;
				zombie_copy->color = color;
				zombie_copy->freezing_flag = freezing_flag;
				zombie_copy->freezing_time = freezing_time;
				zombie_copy->extra_flag = extra_flag;
				zombie_copy->stone = stone;
				zombie_copy->stone_left= stone_left;

				game.garden.swards[num_y][num_x].Add_Zombie(game.garden, zombie_copy);
				game.garden.swards[num_y][num_x + 1].update_flag = true;

				return false;
			}
		}
		timer = 0;
	}
	else
	{
		timer++;
	}
	return true;
}

int Catapultzombie::Check_Plant(Garden& garden) // 判断该行是否有植物
{
	int plant_num_x = -1;
	for (int i = 0; i <= num_x; i++)
	{
		if (garden.swards[num_y][i].plant != NULL || garden.swards[num_y][i].extra_plant != NULL)
		{
			plant_num_x = i;
			break;
		}
	}
	return plant_num_x; // 返回植物花园x坐标
}