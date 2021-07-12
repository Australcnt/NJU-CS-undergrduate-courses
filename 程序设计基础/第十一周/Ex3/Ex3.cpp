#include <iostream>
using namespace std;
int equal(int x[], int n)
{
	int sum1 = 0, sum2 = 0, m = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 += x[i];
		for (int j = n - 1; j >= 0; j--)
		{
			sum2 += x[j];
			if (sum1 == sum2)
				m++;
		}
		sum2 = 0;
	}
	return m;
}

int main()
{
	int x[20];
	for (int a = 0; a < 20; a++)
		cin >> x[a];
	cout << equal(x, 20) << endl;
	return 0;
}