//#include "Map.h"
#include "Zombie.h"

#include <iostream>
using namespace std;

Sward::Sward()
{
	plant = NULL;
	select_flag = false;
	eat_flag = false;
	update_flag = false;
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
	if(!zombies.empty())
	{
		Print_Zombie();
	}
	if(select_flag)
	{
		Print_Select();
	}
	update_flag = false;
}

void Sward::Print_Select()
{
	if (select_flag)
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
	else
	{
		string str = " ";
		for (int i = 0; i < SWARD_LENGTH_X - 2; i++)
			str += " ";
		str += " ";
		UI::Move_Cursor(loc_x, loc_y);
		UI::Print_With_Color(str, FOREGROUND_SELECTED_COLOR);
		UI::Move_Cursor(loc_x, loc_y + SWARD_LENGTH_Y - 1);
		UI::Print_With_Color(str, FOREGROUND_SELECTED_COLOR);
		for (int j = 0; j < SWARD_LENGTH_Y - 2; j++)
		{
			UI::Move_Cursor(loc_x, loc_y + j + 1);
			UI::Print_With_Color(" ", FOREGROUND_SELECTED_COLOR);
			UI::Move_Cursor(loc_x + SWARD_LENGTH_X - 1, loc_y + j + 1);
			UI::Print_With_Color(" ", FOREGROUND_SELECTED_COLOR);
		}
	}
}

void Sward::Print_Plant()
{
	if (plant->name == "向日葵")
		UI::Move_Cursor(loc_x + 4, loc_y + 2);
	else
		UI::Move_Cursor(loc_x + 3, loc_y + 2);
	UI::Print_With_Color(plant->name, plant->color);
	UI::Move_Cursor(loc_x + 3, loc_y + 3);
	int hp_percentage = plant->hp_left * 100 / plant->hp;
	UI::Print_With_Color("( " + to_string(hp_percentage) + "% )", DEFAULT_COLOR);
}

void Sward::Print_Zombie()
{
	/*for (int i = 0; i < SWARD_LENGTH_Y; i++)
	{
		string str(SWARD_LENGTH_X, ' ');
		UI::Move_Cursor(loc_x, loc_y + i);
		cout << str;
	}*/
	if (plant == NULL && zombies.size() < 3)
	{
		for (auto i = zombies.begin(); i < zombies.end(); i++)
		{
			UI::Move_Cursor((*i)->loc_x, (*i)->loc_y);
			UI::Print_With_Color((*i)->name, DEFAULT_COLOR);
			UI::Move_Cursor((*i)->loc_x, (*i)->loc_y + 1);
			int hp_percentage = (*i)->hp_left * 100 / (*i)->hp;
			UI::Print_With_Color("( " + to_string(hp_percentage) + "% )", DEFAULT_COLOR);
		}
	}
	else
	{
		UI::Move_Cursor((zombies[0])->loc_x, (zombies[0])->loc_y);
		UI::Print_With_Color("僵尸×", DEFAULT_COLOR);
		UI::Move_Cursor((zombies[0])->loc_x + 6, (zombies[0])->loc_y);
		UI::Print_With_Color(to_string(zombies.size()), DEFAULT_COLOR);
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
			zombies.erase(i);
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
			if (swards[i][j].update_flag)
			{
				swards[i][j].Print();
			}
		}
	}
}