#include <iostream>
using namespace std;
char Ten(int n)
{
	char str[100];
	for (int i = 0; n != 0;i++)
	{
		str[i] = n % 10 - '0'; 
		n = n/10;
		str[i + 1] = '\0';
	}
	char *ph = str, *pt = ph;
	for (; (*pt) != '\0'; pt++);
	for (pt--; ph < pt;ph++,pt--)
	{
		char temp = *pt;
		*pt = *ph;
		*ph = temp;
	}
	return str[100];
}
int main()
{
	int n;
	cin >> n;
	cout << Ten(n);
	return 0;
}