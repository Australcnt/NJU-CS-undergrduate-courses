#include <iostream>
using namespace std;
int CountDigit(int n) //����CountDigit������������n��λ��;
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
int KthDigit(int n, int k) //����KthDigit����������n�ĵ�kλ��;
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
	m = CountDigit(n);//����CountDigit������n��λ��;
	k = m / 2;
	y = KthDigit(n, k);//����KthDigit����������n�ĵ�kλ��;
	cout << y;
	return 0;
}
