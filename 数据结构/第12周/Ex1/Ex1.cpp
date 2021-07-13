#include <iostream>
#include <string.h>

using namespace std;

int dec2bin(int n, char s2[]);
bool check(char s[], int length);

int main()
{
	int n;
	cin >> n;
	n++;
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	while (1)
	{
		char s[10] = { 0 }, s2[30] = { 0 };
		int n2 = n;
		int length = 0;
		while (n2 != 0)
		{
			n2 = n2 / 10;
			length++;
		}
		n2 = n;
		for (int i = length - 1; i >= 0; i--)
		{
			s[i] = (char)(n2 % 10);
			n2 = n2 / 10;
		}
		s[length] = '\0';
		int length2 = dec2bin(n, s2);
		if (check(s, length) && check(s2, length2))
		{
			cout << n << endl;
			return 0;
		}
		n++;
	}
}

int dec2bin(int n, char s2[])
{
	int i;
	for (i = 0; n != 0; i++)
	{
		s2[i] = (char)(n % 2);
		n = n / 2;
	}
	s2[i] = '\0';
	return i;
}

bool check(char s[], int length)
{
	for (int i = 0; i <= (length - 1) / 2; i++)
	{
		if (s[i] != s[length - 1 - i])
			return false;
	}
	return true;
}