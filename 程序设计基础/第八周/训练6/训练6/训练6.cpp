#include <iostream>
using namespace std;
int CountDigit(int);
void intRevs(int);
int main()
{
	int n;
	cin >> n;
	intRevs(n);
	return 0;
}

int CountDigit(int n)
{
	int m = 0, x = 1;
	x = n;
	while (x >= 1)
	{
		x = x / 10;
		m++;
	}
	return m;
}

void intRevs(int n)
{
	int x, a;
	x = CountDigit(n);
	for (int i = 1; i <= x;i++)
	{
		a = n % 10;
		n = n / 10;
		if (a == 0 && i == 1)
			continue;
		cout << a;
	}
}