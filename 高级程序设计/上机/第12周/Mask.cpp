#include "Mask.h"

Mask::Mask(const string& name, int price, int number)
{
	this->name = name;
	this->price = price;
	this->number = number;
	this->bound = -1;
}

string Mask::GetName()
{
	return name;
}

int Mask::GetPrice()
{
	return price;
}

int Mask::GetNumber()
{
	return number;
}

int Mask::GetCost()
{
	return price * number;
}