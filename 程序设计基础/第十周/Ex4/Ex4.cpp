#include <iostream>
using namespace std;
int su(int n)
{
	int i = 2;
	while (i <= n&&n%i != 0||i==n)
	{
		if (i == n)
			return 1;
		++i;
		if (i == n)
			return 1;
	} 
	return 0;
}
int main()
{
	int n, a = 2;
	cin >> n;
	while (n > 2 && n % 2 == 0)
	{
		if (su(a) == 1 && su(n - a) == 1)
		{
			cout << a << " " << n-a << endl;
			return 0;
		}
		a++;
	}

}