#include <iostream>

using namespace std;

int building[1000] = { 0 };//�����ĸ�����
int build_number = 0;//������·����Ŀ

int main()
{
	int n = 0;//������Ŀ
	cin >> n;
	for (int i = 1; i <= n; i++)//���ÿ�������ĸ�������Ϊ�Լ�
		building[i] = i;
	int m = 0;//����·����Ŀ
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		while (building[a] != a)//Ѱ�Ҹ�����
		{
			building[a] = building[building[a]];
			a = building[a];
		}
		while (building[b] != b)//Ѱ�Ҹ�����
		{
			building[b] = building[building[b]];
			b = building[b];
		}
		building[b] = a;//���ڶ��������ĸ�������Ϊ��һ������
	}
	for (int i = 1; i <= n; i++)//�õ�������·����Ŀ
		if (building[i] == i)
			build_number++;
	build_number--;
	cout << build_number << endl;//�����Ҫ������·����Ŀ
	return 0;
}