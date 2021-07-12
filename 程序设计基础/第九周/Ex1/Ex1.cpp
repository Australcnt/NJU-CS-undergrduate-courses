#include <iostream>
#include <iomanip>
using namespace std;
double A(int n)
{
	double sum = 0, a = 0, b = 1;
	for (int i = 1; i <= n; i++)
	{
	    a = b / i;
		if (i % 2 == 1)
			sum = sum + a;
		else
		    sum = sum - a;
	}
	return sum;
}
int main()
{
	int n = 100;
	cout << fixed << setprecision(15) << A(n) << endl;
	return 0;
}