#include <iostream>

using namespace std;

int path[1000][1000] = { 0 };
int n = 0;
int build_number = 0;

void path_predefinition();//路径初始化，对角线元素置为1
void indirect_connect(int i, int j);//间接相连的路径置为1
void path_build(int id);//从当前建筑向其他建筑修路，直至所有建筑连通

int main()
{
	cin >> n;
	int m = 0;
	cin >> m;
	int a = 0, b = 0;
	int temp_a = 0, temp_b = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		path[a][b] = 1;
		path[b][a] = 1;
		temp_a = a;
		temp_b = b;
	}
	path_predefinition();//路径初始化，对角线元素置为1
	indirect_connect(temp_a, temp_b);//间接相连的路径置为1
	path_build(1);//从第一个建筑向其他建筑修路，直至所有建筑连通
	cout << build_number << endl;
	return 0;
}

void path_predefinition()//路径初始化，对角线元素置为1
{
	for (int i = 1; i <= n; i++)
		path[i][i] = 1;
}

void indirect_connect(int i, int j)//间接相连的路径置为1
{
	for (int k = 1; k <= n; k++)
	{
		if (path[k][i] == 1 && path[k][j] != 1)
		{
			path[k][j] = 1;
			path[j][k] = 1;
			indirect_connect(k, j);
		}
		if (path[k][j] == 1 && path[k][i] != 1)
		{
			path[k][i] = 1;
			path[i][k] = 1;
			indirect_connect(i, k);
		}
	}
}

void path_build(int id)////从当前建筑向其他建筑修路，直至所有建筑连通
{
	int i = 1;
	for (; i <= n; i++)
		if (path[id][i] == 0)
		{
			path[id][i] = 1;
			path[i][id] = 1;
			build_number++;//修路数目加一
			break;
		}

	if (i != n + 1)
	{
		indirect_connect(id, i);//间接相连的路径置为1
		path_build(i);//从下一个建筑向其他建筑修路，直至所有建筑连通
	}
}