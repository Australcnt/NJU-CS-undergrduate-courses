#include <iostream>
using namespace std;
int main()
{
	int n, num = 0;
	cout << "请输入商品总价：";
	cin >> n;
	cout << "1元、2元和5元的货币个数分别为：" << endl;
	for (int i = 0; i * 5 <= n; i++)
		for (int j = 0; i * 5 + j * 2 <= n; j++)
			for (int k = 0; i * 5 + j * 2 + k * 1 <= n;k++)
			{
				if (i * 5 + j * 2 + k * 1 == n)
				{
					num++;
					cout << k << ' ' << j << ' ' << i << endl;
				}
			}
	cout << "共" << num << "种支付方式" << endl;
	return 0;
}