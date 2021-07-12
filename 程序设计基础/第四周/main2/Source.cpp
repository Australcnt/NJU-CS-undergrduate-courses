#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a, b, c;
	cin>>a >> b >> c;
	double d;
	d = b*b - 4 * a*c;
	cout << fixed << setprecision(2);
	cout << d << endl;
	return 0;
}
