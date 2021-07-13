#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

char** str_array = NULL;

void str_exchange(char str1[], char str2[]);
long reverse_count(int left, int right);

int main()
{
	int number;
	cin >> number;
	str_array = new char* [number];
	for (int i = 0; i < number; i++)
	{
		str_array[i] = new char[11];
		cin >> str_array[i];
	}
	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	long reverse_number = reverse_count(0, number - 1);
	cout << reverse_number << endl;
	return 0;
}

void str_exchange(char str1[], char str2[])
{
	char temp[11];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

long reverse_count(int left,int right)
{
	if (left >= right)
		return 0;
	if (left + 1 == right)
	{
		if (strcmp(str_array[left], str_array[right]) > 0)
		{
			str_exchange(str_array[left], str_array[right]);
			return 1;
		}
		else
			return 0;
	}
	int middle = (left + right) / 2;
	long reverse_number_left = reverse_count(left, middle);
	long reverse_number_right = reverse_count(middle + 1, right);
	long reverse_number_middle = 0;
	char** str_array1, ** str_array2;
	str_array1 = new char* [middle - left + 1];
	str_array2 = new char* [right - middle];
	for (int i = 0; i < middle - left + 1; i++)
	{
		str_array1[i] = new char[11];
		strcpy(str_array1[i], str_array[left + i]);
	}
	for (int j = 0; j < right - middle; j++)
	{
		str_array2[j] = new char[11];
		strcpy(str_array2[j], str_array[middle + 1 + j]);
	}
	for (int k = left, i = 0, j = 0; k <= right; k++)
	{
		if (i == (middle - left + 1))
		{
			strcpy(str_array[k], str_array2[j]);
			j++;
		}
		else if (j == (right - middle))
		{
			strcpy(str_array[k], str_array1[i]);
			i++;
		}
		else
		{
			if(strcmp(str_array1[i],str_array2[j]) > 0)
			{
				strcpy(str_array[k], str_array2[j]);
				reverse_number_middle += (middle - left - i + 1);
				j++;
			}
			else
			{
				strcpy(str_array[k], str_array1[i]);
				i++;
			}
		}
	}
	return reverse_number_left + reverse_number_middle + reverse_number_right;
}