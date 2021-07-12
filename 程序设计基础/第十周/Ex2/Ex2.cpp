#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (n%i == 0)
		for (int j = 0; ; j++)
		{
			if (n%i == 0)
				n = n / i;
			else
			{
				cout << i << "(" << j << ")";
				break;
			}
		}
	}
	return 0;
}