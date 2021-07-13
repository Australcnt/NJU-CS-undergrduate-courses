#include <iostream>
using namespace std;

int divide(int x, int y)
{
	if (y == 0) throw 0;
	return x / y;
}


void f() //其中用到两个数相除操作
{
	int a, b;
	while (1)
	{
		try
		{
			cout << "请输入两个数：";
			cin >> a >> b;
			int r = divide(a, b);
			cout << a << "除以" << b << "的商为：" << r << endl;
			break;
		}
		catch (int)
		{
			cout << "除数不能为0，请重新输入两个数：" << endl;
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
		cout << "请重新运行本程序！" << endl;
	}
	return 0;
}
