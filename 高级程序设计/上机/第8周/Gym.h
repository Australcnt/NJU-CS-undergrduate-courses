#pragma once
#include <iostream>
#include <vector>
#include "Seat.h"

using namespace std;

class Gym
{
protected:
	vector<Seat*>regularseat;
	int regularseat_num;
	vector<Seat*>vipseat;
	int vipseat_num;
	int income;
public:
	Gym();
	Gym(int RegularSeatNum, int VIPSeatNum);
	bool AddSeat(Seat* seat, int type);
	bool DeleteSeat(Seat* seat, int type);
	Seat* Buy(int row, int col);
	Seat* Refund(int row, int col);
	int Income();
};