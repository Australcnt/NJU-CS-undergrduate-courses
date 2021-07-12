#include <iostream>
using namespace std;
int main()
{
	int n, a, d,i,sum;
	cin >> n >> a >> d;
	while (a>0)
	{
		for (i = 1, sum = 0; i <= n; i++)
		{
			sum = sum + a;
			a = a + d;
		}
		cout << sum << endl;
		return 0;
	}
	if (a <= 0)
		return 0;
}