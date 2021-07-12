#include <iostream>
using namespace std;
#define N 5
	
int main()
{
	int a[N];
	cout << "请分别输入五张扑克牌的数字：" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		if (a[i] < 1 && a[i]>13 && a[i] != 0)
		{
			cout << "输入的扑克牌数字不符合规定" << endl;
			return 0;
		}
	}
	for (int i = N; i > 1; i--)
	{
		int max = 0, king = -1;
		for (int j = 0; j < i; j++)
		{
			if (a[max] < a[j])
				max = j;
			if (a[j] == 0)
				king = j;
		}
		if (i < N)
		{
			if (a[max] == a[i] - 1)
			{
				int temp = a[i - 1];
				a[i - 1] = a[max];
				a[max] = temp;
			}
			else if (king != -1)
			{
				a[king] = a[i] - 1;
				int temp = a[i - 1];
				a[i - 1] = a[king];
				a[king] = temp;
			}
			else
			{
				cout << "No" << endl;
				return 0;
			}
		}
		else
		{
			int temp = a[i - 1];
			a[i - 1] = a[max];
			a[max] = temp;
		}
	}
	cout << "Yes" << endl;
	return 0;
}