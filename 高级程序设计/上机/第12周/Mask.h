#pragma once
#include <iostream>
#include <string>

using namespace std;

class Mask
{
private:
public:
	string name;
	int price;
	int number;
	int bound;
public:
	Mask(const string& name, int price, int number);
	string GetName();
	int GetPrice();
	int GetNumber();
	int GetCost();
};