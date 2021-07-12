#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (; n >= 1 && n < 1000;n--)
	{
		int a = n*n*n;
		if (a >= 111)
		{
			if (a % 10 == 1)
			{
				a = a / 10;
				if (a % 10 == 1)
				{
					a = a / 10;
					if (a % 10 == 1)
					{
						cout << "yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "no" << endl;
	return 0;

}