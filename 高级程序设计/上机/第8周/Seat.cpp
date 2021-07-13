#include "Seat.h"

Seat::Seat()
{
	buy_flag = false;
}

Seat::Seat(int row, int col)
{
	_row = row;
	_col = col;
	_price = 100;
	buy_flag = false;
}

int Seat::GetRow()
{
	return _row;
}

int Seat::GetCol()
{
	return _col;
}

bool Seat::operator > (const Seat& b)
{
	return _row > b._row;
}

bool Seat::operator == (const Seat& b)
{
	return _row == b._row;
}

int Seat::operator - (const Seat& b)
{
	if (_row != b._row)
		return -1;
	if (_col - b._col > 0)
		return _col - b._col;
	else
		return b._col - _col;
}



RegularSeat::RegularSeat(int row, int col)
{
	_row = row;
	_col = col;
	_price = 100;
	buy_flag = false;
}

int RegularSeat::GetRow()
{
	return _row;
}

int RegularSeat::GetCol()
{
	return _col;
}
int RegularSeat::Price()
{
	return _price;
}



VIPSeat::VIPSeat(int row, int col)
{
	_row = row;
	_col = col;
	_price = 500;
	buy_flag = false;
}

// 成员函数(继承⾃基类)，返回该座位的所在⾏
int VIPSeat::GetRow()
{
	return _row;
}


int VIPSeat::GetCol()
{
	return _col;
}

int VIPSeat::Price()
{
	return _price;
}