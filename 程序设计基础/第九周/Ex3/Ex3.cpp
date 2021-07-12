#include <iostream>
using namespace std;
int C(int a,int b,int c)
{
	int med = 0;
	if (a >= b)
	{
		med = a;
		if (med >= c)
			if (c >= b)
				med = c;
			else
				med = b;
	}
	else
	{
		med = b;
		if (med >= c)
			if (c >= a)
				med = c;
			else
				med = a;
	}
	return med;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << C(a, b, c) << endl;
	return 0;
}