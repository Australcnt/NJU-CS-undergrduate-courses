#include <iostream>
#include "Binary.h"
#include <string.h>
using namespace std;
/*
int main()
{
	char str1[100], str2[100];
	cin >> str1 >> str2;
	sum_len(str1, str2);
	merge(str1, str2);
	return 0;
}*/

void sum_len(char* str1, char* str2)
{
	cout << strlen(str1) + strlen(str2) << endl;
}
void merge(char* str1, char* str2)
{
	char str3[1000] = { 0 };
	char temp1;
	for (int i = 0; i < strlen(str1); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (str1[j] < str1[j - 1])
			{
				temp1 = str1[j];
				str1[j] = str1[j - 1];
				str1[j - 1] = temp1;
			}
		}
	}
	char temp2;
	for (int i = 0; i < strlen(str2); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (str2[j] < str2[j - 1])
			{
				temp2 = str2[j];
				str2[j] = str2[j - 1];
				str2[j - 1] = temp2;
			}
		}
	}
	int it1 = 0, it2 = 0;
	for (int i = 0; i < strlen(str1) + strlen(str2); i++)
	{
		if (str1[it1] != '\0' && (str2[it2] == '\0' || str1[it1] < str2[it2]))
		{
			str3[i] = str1[it1];
			it1++;
		}
		else
		{
			str3[i] = str2[it2];
			it2++;
		}
	}
	cout << str3 << endl;
}