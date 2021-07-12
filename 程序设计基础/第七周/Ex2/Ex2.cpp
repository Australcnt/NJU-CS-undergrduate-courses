#include <iostream>
using namespace std;
int CountDigit(int n) //定义CountDigit函数计算整数n的位数;
{
	int m = 0, x = 1;
	x = n;
	while (x >= 1)
	{	
		x = x / 10;
		m++;
	}
	return m;
}
int KthDigit(int n, int k) //定义KthDigit函数求整数n的第k位数;
{
	int y, m = CountDigit(n);
	y = n;
	for (int i = 1; i < k; i++)
		y = y / 10;
	y = y % 10;
		return y;
}
int main()
{
	int n, k, m, y;
	cin >> n;
	m = CountDigit(n);//调用CountDigit函数求n的位数;
	k = m / 2;
	y = KthDigit(n, k);//调用KthDigit函数求整数n的第k位数;
	cout << y;
	return 0;
}
