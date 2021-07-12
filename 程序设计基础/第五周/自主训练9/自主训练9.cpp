#include <iostream>
using namespace std;
int main()
{
	int d1, d2, d3;
start:
	cin >> d1;
	if (d1 != 0)
		cin>> d2 >> d3;
	else
		return 0;
		while (d1 > 0&&d2 > 0&&d3 != 0)
		{
			int a = 0;
			if (d1 >= d2)
			{
				a = d1;
				d1 = d2;
				d2 = a;
			}
			for (; d1 <= d2; d1++)
			{
				if (d1%d3 != 0)
					cout << d1 << " ";
			}
			cin >> d1;
			if (d1 != 0)
				cin >> d2 >> d3;
			else
				return 0;
		}
	
	goto start;
}
