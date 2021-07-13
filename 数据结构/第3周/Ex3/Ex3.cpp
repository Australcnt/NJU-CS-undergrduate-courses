#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

void number_reverse(char number[], int length);
void zero_fill(char number[], int len);
void bit_minus(char a[], char b[], int loc, int len);

int main()
{
	char a[301], b[301], c[301] = "0", temp[301];
	cin >> a;
	cin >> b;
	int flag = 0;
	if (strlen(a) < strlen(b) || (strlen(a) == strlen(b) && strcmp(a, b) < 0))
	{
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
		flag = 1;
	}
	int length_a = strlen(a);
	int length_b = strlen(b);
	number_reverse(a, length_a);
	number_reverse(b, length_b);
	zero_fill(a, length_a);
	zero_fill(b, length_b);
	a[300] = '\0';
	b[300] = '\0';
	for (int i = 0; i < length_a; i++)
	{
		if (a[i] >= b[i])
			c[i] = a[i] - b[i] + 48;
		else
		{
			c[i] = 10 - (b[i] - a[i]) + 48;
			bit_minus(a, b, i + 1, length_a);
		}
	}
	int length_c = strlen(c);
	zero_fill(c, length_c);
	for (int j = 299; j >= 0; j--)
	{
		if (c[j] != '0' || (j == 0 && c[j] == '0'))
		{
			length_c = j + 1;
			c[length_c] = '\0';
			break;
		}
	}
	number_reverse(c, length_c);
	if (flag)
		cout << "-";
	cout << c << endl;
	return 0;
}

void number_reverse(char number[], int length)
{
	for (int i = 0; i < (length + 1) / 2; i++)
	{
		char temp;
		temp = number[i];
		number[i] = number[length - i - 1];
		number[length - i - 1] = temp;
	}
}

void zero_fill(char number[], int len)
{
	for (int i = len; i < 300; i++)
		number[i] = '0';
}

void bit_minus(char a[], char b[], int loc, int len)
{
	if (a[loc] == '0')
	{
		a[loc] = '9';
		bit_minus(a, b, loc + 1, len);
	}
	else
		a[loc] = a[loc] - 1;
}