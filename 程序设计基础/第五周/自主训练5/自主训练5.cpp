#include <iostream>
using namespace std;
int main()
{
	int a, sum = 0;
	cin >> a;
	while (a!=-1)
	{
		if (a > 0)
		{
			sum += a;
			cin >> a;
		}
		else
			cin >> a;
	}
	cout << sum << endl;
	if (a = -1)
		return 0;

}