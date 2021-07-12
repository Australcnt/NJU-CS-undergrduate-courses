#include <iostream>
#include <iomanip>
using namespace std;
double ItrNewton(double a, double b, double c, double d)
{
	double x = 0;
	int i = 1;
	while (i=1)
	{
		double f = a*x*x*x + b*x*x + c*x + d;
		double fd = 3 * a*x*x + 2 * b*x + c;
		x = x - f / fd;
		if ((f / fd) < 1e-6&&(f/fd)>-1e-6)
			return x + f / fd;
	} 
}
int main()
{
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << fixed << setprecision(5) << ItrNewton(a, b, c, d) << endl;
	return 0;
}