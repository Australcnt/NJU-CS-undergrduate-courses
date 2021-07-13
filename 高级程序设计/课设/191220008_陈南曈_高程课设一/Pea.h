#pragma once
#include <iostream>
#include "UI.h"
//#include "Game.h"

class Game;

using namespace std;

class Pea
{
private:
	string name;
	int speed;
	int attack;
	int color;
	int loc_x;
	int loc_y;
	int num_x;
	int num_y;
	int timer;
public:
	Pea(int _loc_x, int _loc_y);
	void Locate();
	bool Move(Game& game);
	void Hit(Game& game);
	void Print(Garden &garden);

	friend class Plant;
	friend class Game;
};