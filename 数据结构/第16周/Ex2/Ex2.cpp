#include <iostream>

using namespace std;

int n, a, b;//地区数量，入口，出口
int path[201][201];//道路长度
bool visit[201][201];//是否访问过
int dist[201];//最小路径

int get_min(int row);//未访问过的最近的邻结点
void dijkstra(int cur);

int main()
{
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)//道路长度初始化
			path[i][j] = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)//访问初始化
			visit[i][j] = false;
	for (int i = 1; i <= n; i++)//最短路径初始化
		dist[i] = INT32_MAX;
	int k = 0;
	int col = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> col;
		path[i][0] = col;
		for (int j = 1; j <= col; j++)
		{
			cin >> k;
			if (j == 1)
			{
				path[i][k] = 0;//无妖怪
			}
			else
			{
				path[i][k] = 1;//有妖怪
			}
		}
	}
	int cur = a;
	dist[cur] = 0;
	dijkstra(cur);
	if (dist[b] == INT32_MAX)
		cout << "-1" << endl;
	else
		cout << dist[b] << endl;
	return 0;
}

int get_min(int row)
{
	int j = 1;
	int j_min = 0;
	for (; j <= n; j++)
	{
		if (visit[row][j] == true || path[row][j] == -1 || row == j)//访问过，没有边，自环
			continue;
		if (j_min == 0 || path[row][j] < path[row][j_min])//更新最短路径
			j_min = j;
	}
	if (j_min == 0)
		return 0;
	else
		return j_min;
}

void dijkstra(int cur)
{
	for (int i = 0; i < path[cur][0]; i++)//遍历当前结点的所有邻接点及其邻结点
	{
		int next = get_min(cur);
		if (next != 0)
		{
			visit[cur][next] = true;
			if (dist[next] > dist[cur] + path[cur][next])
				dist[next] = dist[cur] + path[cur][next];
			dijkstra(next);
		}
	}
}