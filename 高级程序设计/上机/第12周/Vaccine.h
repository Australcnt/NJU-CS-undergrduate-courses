#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vaccine
{
private:
public:
	string name;
	int price;
	int number;
	int bound;
public:
	Vaccine(const string& name, int price, int number, int bound);
	string GetName();
	int GetPrice();
	int GetNumber();
	int GetBound();
	int GetCost();
};