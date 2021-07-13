#include "Vaccine.h"

// 构造函数
Vaccine::Vaccine(const string & name, int price, int number, int bound)
{
	this->name = name;
	this->price = price;
	this->number = number;
	this->bound = bound;
}

// 成员函数，返回疫苗类型名称
string Vaccine::GetName()
{
	return name;
}

// 成员函数，返回疫苗单价
int Vaccine::GetPrice()
{
	return price;
}

// 成员函数，返回订单购买该疫苗的数量
int Vaccine::GetNumber()
{
	return number;
}

// 成员函数，返回该疫苗的库存总量
int Vaccine::GetBound()
{
	return bound;
}

// 成员函数，返回订单总价（单价✖数量）
int Vaccine::GetCost()
{
	return price * number;
}