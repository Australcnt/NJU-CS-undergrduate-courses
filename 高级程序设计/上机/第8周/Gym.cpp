#include "Gym.h"


Gym::Gym()
{
	;
}

Gym::Gym(int RegularSeatNum, int VIPSeatNum)
{
	regularseat_num = RegularSeatNum;
	vipseat_num = VIPSeatNum;
	income = 0;
}

bool Gym::AddSeat(Seat* seat, int type)
{
	if (type == 0)
	{
		if ((int)regularseat.size() == regularseat_num)
			return false;
		for (auto i = regularseat.begin(); i < regularseat.end(); i++)
		{
			if (seat->GetRow() == (*i)->GetRow() && seat->GetCol() == (*i)->GetCol())
				return false;
		}
		regularseat.push_back(seat);
		return true;
	}
	else
	{
		if ((int)vipseat.size() == vipseat_num)
			return false;
		for (auto i = vipseat.begin(); i < vipseat.end(); i++)
		{
			if (seat->GetRow() == (*i)->GetRow() && seat->GetCol() == (*i)->GetCol())
				return false;
		}
		vipseat.push_back(seat);
		return true;
	}
}

bool Gym::DeleteSeat(Seat* seat, int type)
{
	if (type == 0)
	{
		for (auto i = regularseat.begin(); i < regularseat.end(); i++)
		{
			if (seat->GetRow() == (*i)->GetRow() && seat->GetCol() == (*i)->GetCol())
			{
				i = regularseat.erase(i);
				return true;
			}
		}
		return false;
	}
	else
	{
		for (auto i = vipseat.begin(); i < vipseat.end(); i++)
		{
			if (seat->GetRow() == (*i)->GetRow() && seat->GetCol() == (*i)->GetCol())
			{
				i = vipseat.erase(i);
				return true;
			}
		}
		return false;
	}
}

Seat* Gym::Buy(int row, int col)
{
	for (auto i = regularseat.begin(); i < regularseat.end(); i++)
	{
		if (row == (*i)->GetRow() && col == (*i)->GetCol())
		{
			if ((*i)->buy_flag == true)
				return NULL;
			(*i)->buy_flag = true;
			income += (*i)->_price;
			return *i;
		}
	}
	for (auto i = vipseat.begin(); i < vipseat.end(); i++)
	{
		if (row == (*i)->GetRow() && col == (*i)->GetCol())
		{
			if ((*i)->buy_flag == true)
				return NULL;
			(*i)->buy_flag = true;
			income += (*i)->_price;
			return *i;
		}
	}
	return NULL;
}

Seat* Gym::Refund(int row, int col)
{
	for (auto i = regularseat.begin(); i < regularseat.end(); i++)
	{
		if (row == (*i)->GetRow() && col == (*i)->GetCol())
		{
			if ((*i)->buy_flag == false)
				return NULL;
			(*i)->buy_flag = false;
			income -= (*i)->_price;
			return *i;
		}
	}
	for (auto i = vipseat.begin(); i < vipseat.end(); i++)
	{
		if (row == (*i)->GetRow() && col == (*i)->GetCol())
		{
			if ((*i)->buy_flag == false)
				return NULL;
			(*i)->buy_flag = false;
			income -= (*i)->_price;
			return *i;
		}
	}
	return NULL;
}

int Gym::Income()
{
	return income;
}