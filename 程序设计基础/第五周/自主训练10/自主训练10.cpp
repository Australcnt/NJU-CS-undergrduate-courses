#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	double x, x1 = 1.0, x2 = 1.0, eps = 1e-6;
	cin >> x;
	do
	{   
		x1 = x2;
		x2 = (2 * x1 + x / (x1 * x1)) / 3;/*" ^ "的左操作数不能是double类型（不能是x1^2,只能用x1*x1），
												表达式必须具有整数或未区分范围的枚举类型*/
	} while (fabs(x2 - x1) >= eps);
	cout << fixed << setprecision(2) << x2 << endl;
	return 0;
}
