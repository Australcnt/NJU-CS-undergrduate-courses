#pragma once
#include <iostream>
using namespace std;

class Seat
{
protected:
	int _row;
	int _col;
public:
	int _price;
	bool buy_flag;
	Seat();
	Seat(int row, int col);
	int GetRow();
	int GetCol();
	bool operator > (const Seat& b);
	bool operator == (const Seat& b);
	int operator - (const Seat& b);
};

class RegularSeat:public Seat
{
public:
	RegularSeat(int row, int col);
	int GetRow();
	int GetCol();
	int Price();
};

class VIPSeat :public Seat
{
public:
	VIPSeat(int row, int col);
	int GetRow();
	int GetCol();
	int Price();
};