#include "Store.h"
#include "Game.h"

#include <iostream>
using namespace std;

void PlantCard::Set(int _index, string _name, int _price, int _cd)
{
	index = _index;
	name = _name;
	price = _price;
	cd = _cd;
	timer = 0;
	select_flag = false;
	cooldown_flag = false;
}

void PlantCard::Print()
{
	//参考位置设定
	int loc_x = 3 + (PLANTCARD_LENGTH_X * index) % 150;
	int loc_y = 2 + (PLANTCARD_LENGTH_X * index) / 150;
	UI::Move_Cursor(loc_x, loc_y);
	string str(PLANTCARD_LENGTH_X, ' ');
	cout << str;
	UI::Move_Cursor(loc_x, loc_y);
	if (select_flag)
	{
		if (!cooldown_flag)
			UI::Set_Color(BACKGROUND_SELECTED_COLOR);
		else
			UI::Set_Color(BACKGROUND_SELECTED_COLOR | COOLDOWN_COLOR);
	}
	else if (cooldown_flag)
		UI::Set_Color(COOLDOWN_COLOR);
	if (index < 9)
		cout << index + 1 << '.' << setw(8) << left << name << " | " << price << "$";
	else
		cout << (char)('a' + index - 9) << "." << setw(8) << left << name << " | " << price << "$";
	if (cooldown_flag)
	{
		cout << "(" << timer * 100 / cd << "%)";
	}
	UI::Set_Color(DEFAULT_COLOR);
}

void PlantCard::Cool_Down()
{
	if (timer + 1 == cd)
	{
		cooldown_flag = false;
		timer = 0;
	}
	else
	{
		timer++;
	}
	Print();
}

Store::Store()
{
	plant_card[0].Set(0, "向日葵", 50, 75);
	plant_card[1].Set(1, "豌豆射手", 100, 75);
	sunshine = 1000;
	//每5秒生成阳光
	sunshine_speed = 50;
	sunshine_produce = 25;
	sunshine_update_flag = false;
	timer = 0;
}

void Store::Print()
{

	//固定不变的UI部分
	UI::Move_Cursor(3, 0);
	UI::Print_With_Color("【商店】", DEFAULT_COLOR);
	UI::Move_Cursor(20, 0);
	UI::Print_With_Color("阳光:", DEFAULT_COLOR);
	UI::Move_Cursor(135, 0);
	UI::Print_With_Color("得分:", DEFAULT_COLOR);
	UI::Move_Cursor(0, 1);
	string str(WINDOW_LENGTH_X, '-');
	UI::Print_With_Color(str, DEFAULT_COLOR);

	//可变的UI部分的首次输出
	for (int i = 0; i < PLANT_TYPE_MAX; i++)
	{
		plant_card[i].Print();
	}
}

bool Store::Perchase(int plant_type, int num_x, int num_y, Garden& garden)
{
	if (plant_card[plant_type].cooldown_flag == true)
		return false;
	if (sunshine < plant_card[plant_type].price)
		return false;
	if (garden.swards[num_y][num_x].plant != NULL)
		return false;
	garden.swards[num_y][num_x].Add_Plant(Type_To_Plant(plant_type, num_x, num_y));
	sunshine -= plant_card[plant_type].price;
	plant_card[plant_type].cooldown_flag = true;
	sunshine_update_flag = true;
	return true;
}

Plant* Store::Type_To_Plant(int plant_type, int num_x, int num_y)
{
	Plant* plant = NULL;
	switch (plant_type)
	{
	case SUNFLOWER:
		plant = new Sunflower;
		break;
	case PEASHOOTER:
		plant = new Peashooter;
		break;
	default:
		break;
	}
	plant->Set(num_x, num_y);
	return plant;
}

void Store::Sunshine_Produce(Game& game) // 产生自然阳光
{
	if (timer + 1 == sunshine_speed)
	{
		sunshine += sunshine_produce;
		//game.Update_Sunshine();
		sunshine_update_flag = true;
		timer = 0;
	}
	else
	{
		timer++;
	}
}

void Store::Update_Sunshine(Game& game) // 更新阳光数
{
	for (int i = 0; i < SWARD_NUM_Y; i++)
	{
		for (int j = 0; j < SWARD_NUM_X; j++)
		{
			if (game.garden.swards[i][j].plant != NULL && game.garden.swards[i][j].plant->name == "向日葵")
				game.garden.swards[i][j].plant->Functioning(game);
		}
	}
	UI::Move_Cursor(26, 0);
	string str(10, ' ');
	cout << str;
	UI::Move_Cursor(26, 0);
	UI::Print_With_Color(sunshine, DEFAULT_COLOR);
	sunshine_update_flag = false;
}