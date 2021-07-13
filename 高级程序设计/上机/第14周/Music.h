#pragma once
#include <iostream>
#include <string>

using namespace std;

class Music
{
public:
	string name;
	string singer;
	int count;
	string date;
	string nation;
public:
	Music(string name, string singer, int count, string date, string nation);
	string getName();
	string getSinger();
	int getCount();
	string getDate();
	string getNation();

	friend ostream& operator << (ostream& out, const Music& music);
};