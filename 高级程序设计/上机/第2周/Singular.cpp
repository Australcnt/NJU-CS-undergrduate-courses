#include <iostream>
#include "Singular.h"
#include <string.h>
using namespace std;

/*
int main()
{
	char str1[10], str2[10];
	cin >> str1 >> str2;
	get_min_asc(str1);
	reorder(str2);
	return 0;
}*/

void get_min_asc(char* str)
{
	char min = 'z';
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] < min)
			min = str[i];
	}
	cout << min << endl;
}

void reorder(char* str)
{
	char temp;
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (str[j] < str[j - 1])
			{
				temp = str[j];
				str[j] = str[j - 1];
				str[j - 1] = temp;
			}
		}
	}
	cout << str << endl;
}