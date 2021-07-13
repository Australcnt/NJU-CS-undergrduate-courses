//#include "Map.h"
#include "Zombie.h"

#include <iostream>
using namespace std;

Sward::Sward()
{
	plant = NULL;
	extra_plant = NULL;
	select_flag = false;
	eat_flag = false;
	update_flag = false;
	bomb_flag = false;
	bomb_timer = 0;
	bomb_time = 5;
}

void Sward::Locate(int num_x,int num_y)
{
	loc_x = (SWARD_LENGTH_X + 1) * num_x + 1;
	loc_y = (STORE_LENGTH_Y + 1) + (SWARD_LENGTH_Y + 1) * num_y + 1;
}

void Sward::Print()
{
	for (int i = 0; i < SWARD_LENGTH_Y; i++)
	{
		string str(SWARD_LENGTH_X, ' ');
		UI::Move_Cursor(loc_x, loc_y + i);
		cout << str;
	}
	if (plant != NULL)
	{
		Print_Plant();
	}
	if (extra_plant != NULL)
	{
		Print_Extra_Plant();
	}
	if(!zombies.empty())
	{
		Print_Zombie();
	}
	if(select_flag)
	{
		Print_Select();
	}
	if(bomb_flag)
	{
		Print_Bomb();
	}
}

void Sward::Print_Select()
{
	string str = "+";
	for (int i = 0; i < SWARD_LENGTH_X - 2; i++)
		str += "-";
	str += "+";
	UI::Move_Cursor(loc_x, loc_y);
	UI::Print_With_Color(str, FOREGROUND_SELECTED_COLOR);
	UI::Move_Cursor(loc_x, loc_y + SWARD_LENGTH_Y - 1);
	UI::Print_With_Color(str, FOREGROUND_SELECTED_COLOR);
	for (int j = 0; j < SWARD_LENGTH_Y - 2; j++)
	{
		UI::Move_Cursor(loc_x, loc_y + j + 1);
		UI::Print_With_Color("|", FOREGROUND_SELECTED_COLOR);
		UI::Move_Cursor(loc_x + SWARD_LENGTH_X - 1, loc_y + j + 1);
		UI::Print_With_Color("|", FOREGROUND_SELECTED_COLOR);
	}
}

void Sward::Print_Bomb()
{
	if (bomb_timer + 1 == bomb_time)
	{
		string str = " ";
		for (int i = 0; i < SWARD_LENGTH_X - 2; i++)
			str += " ";
		str += " ";
		UI::Move_Cursor(loc_x, loc_y);
		UI::Print_With_Color(str, DEFAULT_COLOR);
		UI::Move_Cursor(loc_x, loc_y + SWARD_LENGTH_Y - 1);
		UI::Print_With_Color(str, DEFAULT_COLOR);
		for (int j = 0; j < SWARD_LENGTH_Y - 2; j++)
		{
			UI::Move_Cursor(loc_x, loc_y + j + 1);
			UI::Print_With_Color(" ", DEFAULT_COLOR);
			UI::Move_Cursor(loc_x + SWARD_LENGTH_X - 1, loc_y + j + 1);
			UI::Print_With_Color(" ", DEFAULT_COLOR);
		}
		bomb_timer = 0;
		bomb_flag = false;
	}
	else
	{
		string str = "*";
		for (int i = 0; i < SWARD_LENGTH_X - 2; i++)
			str += "*";
		str += "*";
		UI::Move_Cursor(loc_x, loc_y);
		UI::Print_With_Color(str, BOMB_COLOR);
		UI::Move_Cursor(loc_x, loc_y + SWARD_LENGTH_Y - 1);
		UI::Print_With_Color(str, BOMB_COLOR);
		for (int j = 0; j < SWARD_LENGTH_Y - 2; j++)
		{
			UI::Move_Cursor(loc_x, loc_y + j + 1);
			UI::Print_With_Color("*", BOMB_COLOR);
			UI::Move_Cursor(loc_x + SWARD_LENGTH_X - 1, loc_y + j + 1);
			UI::Print_With_Color("*", BOMB_COLOR);
		}
		bomb_timer++;
	}
}

void Sward::Print_Plant()
{
	UI::Move_Cursor(loc_x + SWARD_LENGTH_X / 2 - plant->name.size() / 2, loc_y + 2); // 植物名字居中输出
	UI::Print_With_Color(plant->name, plant->color);
	UI::Move_Cursor(loc_x + 3, loc_y + 3);
	int hp_percentage = plant->hp_left * 100 / plant->hp;
	UI::Print_With_Color("( " + to_string(hp_percentage) + "% )", DEFAULT_COLOR);
}

void Sward::Print_Extra_Plant()
{
	UI::Move_Cursor(loc_x + 1, loc_y + 1);
	UI::Print_With_Color(extra_plant->name, extra_plant->color);
	UI::Move_Cursor(loc_x + 1 + extra_plant->name.size(), loc_y + 1);
	int hp_percentage = extra_plant->hp_left * 100 / extra_plant->hp;
	UI::Print_With_Color("(" + to_string(hp_percentage) + "%)", extra_plant->color);
}

void Sward::Print_Zombie()
{
	/*for (int i = 0; i < SWARD_LENGTH_Y; i++)
	{
		string str(SWARD_LENGTH_X, ' ');
		UI::Move_Cursor(loc_x, loc_y + i);
		cout << str;
	}*/
	if (plant == NULL && extra_plant == NULL && zombies.size() < 3)
	{
		for (auto i = zombies.begin(); i < zombies.end(); i++)
		{
			if (((*i)->name == "读报僵尸" || (*i)->name == "撑杆僵尸" || (*i)->name == "投石僵尸") && (*i)->extra_flag)
			{
				UI::Move_Cursor((*i)->loc_x - 2, (*i)->loc_y);
				UI::Print_With_Color((*i)->name, (*i)->color);
				if ((*i)->name == "读报僵尸")
				{
					UI::Move_Cursor((*i)->loc_x - 2+(*i)->name.size(), (*i)->loc_y);
					UI::Print_With_Color("(报)", (*i)->color);
				}
				else if((*i)->name == "撑杆僵尸")
				{
					UI::Move_Cursor((*i)->loc_x - 2 + (*i)->name.size(), (*i)->loc_y);
					UI::Print_With_Color("(杆)", (*i)->color);
				}
				else if ((*i)->name == "投石僵尸")
				{
					UI::Move_Cursor((*i)->loc_x - 2 + (*i)->name.size(), (*i)->loc_y);
					UI::Print_With_Color("(石)", (*i)->color);
				}
			}
			else
			{
				UI::Move_Cursor((*i)->loc_x, (*i)->loc_y);
				UI::Print_With_Color((*i)->name, (*i)->color);
			}
			UI::Move_Cursor((*i)->loc_x, (*i)->loc_y + 1);
			int hp_percentage = (*i)->hp_left * 100 / (*i)->hp;
			UI::Print_With_Color("( " + to_string(hp_percentage) + "% )", DEFAULT_COLOR);
		}
	}
	else
	{
		UI::Move_Cursor((zombies[0])->loc_x, (zombies[0])->loc_y);
		UI::Print_With_Color("僵尸×", (zombies[0]->color));
		UI::Move_Cursor((zombies[0])->loc_x + 6, (zombies[0])->loc_y);
		UI::Print_With_Color(to_string(zombies.size()), zombies[0]->color);
		UI::Move_Cursor(zombies[0]->loc_x, zombies[0]->loc_y + 1);
		int hp_percentage = zombies[0]->hp_left * 100 / zombies[0]->hp;
		UI::Print_With_Color("( " + to_string(hp_percentage) + "% )", DEFAULT_COLOR);
	}
}

void Sward::Add_Plant(Plant* _plant)
{
	plant = _plant;
	update_flag = true;
}

void Sward::Delete_Plant()
{
	delete plant;
	plant = NULL;
	update_flag = true;
}

void Sward::Add_Extra_Plant(Plant* _extra_plant)
{
	extra_plant = _extra_plant;
	update_flag = true;
}

void Sward::Delete_Extra_Plant()
{
	delete extra_plant;
	extra_plant = NULL;
	update_flag = true;
}

void Sward::Add_Zombie(Garden& garden, Zombie* _zombie)
{
	zombies.push_back(_zombie);
	int j = 0;
	for (auto i = zombies.begin(); i < zombies.end(); i++, j++)
	{
		(*i)->Locate(garden, j);
	}
	update_flag = true;
}

void Sward::Delete_Zombie(Garden& garden, Zombie* _zombie)
{
	for (auto i = zombies.begin(); i < zombies.end(); i++)
	{
		if ((*i) == _zombie)
		{
			i = zombies.erase(i);
			break;
		}
	}
	int j = 0;
	for (auto i = zombies.begin(); i < zombies.end(); i++, j++)
	{
		(*i)->Locate(garden, j);
	}
	update_flag = true;
}

Garden::Garden()
{
	// 打印花园
	Print();
	// 每个格子初始化
	for (int i = 0; i < SWARD_NUM_Y; i++)
	{
		for (int j = 0; j < SWARD_NUM_X + 1; j++)
		{
			swards[i][j].Locate(j, i);
		}
	}
}

// 打印花园
void Garden::Print()
{
	string str(WINDOW_LENGTH_X, '#');
	for (int i = 0; i < SWARD_NUM_Y; i++)
	{
		UI::Move_Cursor(0, (STORE_LENGTH_Y + 1) + (SWARD_LENGTH_Y + 1) * i);
		UI::Print_With_Color(str, DEFAULT_COLOR);
		for (int j = 0; j < SWARD_LENGTH_Y; j++)
		{
			for (int k = 0; k < (SWARD_NUM_X + 1); k++)
			{
				UI::Move_Cursor((SWARD_LENGTH_X + 1) * k, (STORE_LENGTH_Y + 1) + (SWARD_LENGTH_Y + 1) * i + j + 1);
				UI::Print_With_Color("#", DEFAULT_COLOR);
			}
		}
	}
	UI::Move_Cursor(0, 43);
	UI::Print_With_Color(str, DEFAULT_COLOR);
}

void Garden::Update_Swards()
{
	for (int i = 0; i < SWARD_NUM_Y; i++)
	{
		for (int j = 0; j < SWARD_NUM_X + 1; j++)
		{
			if (swards[i][j].update_flag || swards[i][j].bomb_flag)
			{
				swards[i][j].Print();
				swards[i][j].update_flag = false;
			}
		}
	}
}