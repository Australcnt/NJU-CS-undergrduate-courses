#include <iostream>
using namespace std;
int factorial(int x)
{
	int f;
	for (f = 1; x >= 2; x--)
		f *= x;
	return f;
}
int main()
{
	int n, r, c;
	cin >> n >> r;
	if (n <= 12)
	{
		c = factorial(n) / (factorial(n - r)*factorial(r));
		cout << c << endl;
	}
	return 0;
}