#include <iostream>
using namespace std;
void T(double a, double b, double c)
{
	if (a == b&&b == c)
		cout << "等边三角形" << endl;
	else if (a == b || b == c || a == c)
	{
		if (a*a + b*b != c*c&&b*b + c*c != a*a&&a*a + c*c != b*b)
			cout << "等腰非等边非直角三角形" << endl;
	}
	else if (a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b)
		cout << "非等腰直角三角形" << endl;
	else if (a + b > c || b + c > a || a + c > b)
		cout << "其他三角形" << endl;
	else
		cout << "不是三角形" << endl;

}