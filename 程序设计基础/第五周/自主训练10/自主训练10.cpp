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
		x2 = (2 * x1 + x / (x1 * x1)) / 3;/*" ^ "���������������double���ͣ�������x1^2,ֻ����x1*x1����
												���ʽ�������������δ���ַ�Χ��ö������*/
	} while (fabs(x2 - x1) >= eps);
	cout << fixed << setprecision(2) << x2 << endl;
	return 0;
}
