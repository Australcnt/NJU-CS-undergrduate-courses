#include <iostream>
using namespace std;

int divide(int x, int y)
{
	if (y == 0) throw 0;
	return x / y;
}


void f() //�����õ��������������
{
	int a, b;
	while (1)
	{
		try
		{
			cout << "��������������";
			cin >> a >> b;
			int r = divide(a, b);
			cout << a << "����" << b << "����Ϊ��" << r << endl;
			break;
		}
		catch (int)
		{
			cout << "��������Ϊ0��������������������" << endl;
		}
	}
}

int main()
{
	try
	{
		f();
	}
	catch (int)
	{
		cout << "���������б�����" << endl;
	}
	return 0;
}
