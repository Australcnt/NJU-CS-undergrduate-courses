#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double x, y;
	cin >> x;
	if (x <= 3)
		y = 9 + 1;
	else
		y = 9 + (x - 3)*2.4 + 1;
	cout << fixed << setprecision(1) << y << endl;
	return 0;
}