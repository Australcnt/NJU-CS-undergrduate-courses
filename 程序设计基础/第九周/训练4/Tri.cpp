#include <iostream>
using namespace std;
void T(double a, double b, double c)
{
	if (a == b&&b == c)
		cout << "�ȱ�������" << endl;
	else if (a == b || b == c || a == c)
	{
		if (a*a + b*b != c*c&&b*b + c*c != a*a&&a*a + c*c != b*b)
			cout << "�����ǵȱ߷�ֱ��������" << endl;
	}
	else if (a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b)
		cout << "�ǵ���ֱ��������" << endl;
	else if (a + b > c || b + c > a || a + c > b)
		cout << "����������" << endl;
	else
		cout << "����������" << endl;

}