#include <iostream>
using namespace std;
int main()
{
	int n, num = 0;
	cout << "��������Ʒ�ܼۣ�";
	cin >> n;
	cout << "1Ԫ��2Ԫ��5Ԫ�Ļ��Ҹ����ֱ�Ϊ��" << endl;
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
	cout << "��" << num << "��֧����ʽ" << endl;
	return 0;
}