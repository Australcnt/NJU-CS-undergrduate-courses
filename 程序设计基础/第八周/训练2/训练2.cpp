#include <iostream>
#include<iomanip>
using namespace std;
int YangHui(int i, int j, int n)
{
	if (i == 1)
	{
		if (j == n)
			return 1;
		else
			return 0;
	}
	else
		return YangHui(i - 1, j - 1, n) + YangHui(i - 1, j + 1, n);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2*n+1; j++)
		{
			int a = YangHui(i, j, n);
			if (a == 0)
				cout << setw(3)<<" ";
			else
				cout << setw(3)<<a;
		}
		cout << endl;
	}
	return 0;
}