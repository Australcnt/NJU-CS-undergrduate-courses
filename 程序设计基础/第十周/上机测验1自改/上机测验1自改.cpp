#include <iostream>
#include <iomanip>
using namespace std;
double fang(double x, int i)
{
	double xs = 1.0;
	for (int n = 1; n <= i; n++)
		xs = xs*x;
	return xs;
}
double jie(int i)
{
	double is = 1.0;
	for (int n = 1; n <= i; n++)
		is = is*n;
	return is;
}
double mySin(double x)
{
	double sin = 0.0;
	for (int i = 1; i >= 1; i = i + 2)
	{
		double a = fang(x, i) / jie(i);
		if (i % 4 == 1)
			sin = sin + a;
		else
			sin = sin - a;
		if (a < 0)
			a = -a;
		if (a < 0.0000001)
			break;
	}
	return sin;

}
int main()
{
	double x;
	cin >> x;
	cout << fixed << setprecision(7) << mySin(x) << endl;
	return 0;
}