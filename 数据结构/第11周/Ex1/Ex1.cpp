#include <iostream>

using namespace std;

int building[1000] = { 0 };//建筑的根建筑
int build_number = 0;//修筑的路径数目

int main()
{
	int n = 0;//建筑数目
	cin >> n;
	for (int i = 1; i <= n; i++)//起初每个建筑的根建筑置为自己
		building[i] = i;
	int m = 0;//已有路径数目
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		while (building[a] != a)//寻找根建筑
		{
			building[a] = building[building[a]];
			a = building[a];
		}
		while (building[b] != b)//寻找根建筑
		{
			building[b] = building[building[b]];
			b = building[b];
		}
		building[b] = a;//将第二个建筑的根建筑置为第一个建筑
	}
	for (int i = 1; i <= n; i++)//得到修筑的路径数目
		if (building[i] == i)
			build_number++;
	build_number--;
	cout << build_number << endl;//输出需要修筑的路径数目
	return 0;
}