#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n > 2 && n % 2 == 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i <= (n+1)/2)
				{
					if (i + j >= (n + 3) / 2 && j - i <= (n - 1) / 2)
						cout << "*";
					else
						cout << " ";
				}
				else
				{
					if (j - i >= (1 - n) / 2 && i + j <= (3 * n + 1) / 2)
						cout << "*";
					else
						cout << " ";
				}
				
			}
			cout << endl;
		}
		return 0;
	}
	return 0;
}