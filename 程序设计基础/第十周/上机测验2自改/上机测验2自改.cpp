#include <iostream>
using namespace std;
int ping(int p, int m)
{
	int a = 0, b = 0, sum = 0;
	a = m / p;
	b = a;
	sum = b;
	while (a >= 5)
	{
		a = a / 5;
		sum = sum + a;
		a = b - 5 * a + a;
		b = a;
	}
	return sum;
}
int main()
{
	int p, m;
	cin >> p >> m;
	cout << ping(p, m) << endl;
	return 0;
}