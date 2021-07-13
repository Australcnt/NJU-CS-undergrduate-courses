#include <iostream>

using namespace std;

int n, a, b;//������������ڣ�����
int path[201][201];//��·����
bool visit[201][201];//�Ƿ���ʹ�
int dist[201];//��С·��

int get_min(int row);//δ���ʹ���������ڽ��
void dijkstra(int cur);

int main()
{
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)//��·���ȳ�ʼ��
			path[i][j] = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)//���ʳ�ʼ��
			visit[i][j] = false;
	for (int i = 1; i <= n; i++)//���·����ʼ��
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
				path[i][k] = 0;//������
			}
			else
			{
				path[i][k] = 1;//������
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
		if (visit[row][j] == true || path[row][j] == -1 || row == j)//���ʹ���û�бߣ��Ի�
			continue;
		if (j_min == 0 || path[row][j] < path[row][j_min])//�������·��
			j_min = j;
	}
	if (j_min == 0)
		return 0;
	else
		return j_min;
}

void dijkstra(int cur)
{
	for (int i = 0; i < path[cur][0]; i++)//������ǰ���������ڽӵ㼰���ڽ��
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