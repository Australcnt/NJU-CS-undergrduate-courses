#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int cost;
	int color;
	int est;
	int eft;
	int critdep;
};

int n;

vector<vector<int>>matrix;
Node* V = { 0 };
int length = 0;

void CriticalPath(int u)
{
	V[u].color = 1;
	V[u].est = 0;
	V[u].critdep = -1;
	for (int i = 0; i < matrix[u].size(); i++)
	{
		int v = matrix[u][i];
		if (V[v].color == 0)
		{
			CriticalPath(v);
			if (V[v].eft >= V[u].est)
			{
				V[u].est = V[v].eft;
				V[u].critdep = v;
			}
		}
		else
		{
			if (V[v].eft >= V[u].est)
			{
				V[u].est = V[v].eft;
				V[u].critdep = v;
			}
		}
	}
	V[u].eft = V[u].est + V[u].cost;
	V[u].color = 2;
}

int main()
{
	cin >> n;

	V = new Node [n + 1];

	for (int i = 0; i < n; i++)
	{
		int index;
		cin >> index;
		cin >> V[index].cost;
	}

	for (int i = 0; i < n + 1; i++)
	{
		vector<int> neighbors;
		matrix.push_back(neighbors);
	}
	int x, y;
	while (cin >> x >> y)
		matrix[x].push_back(y);
	/*for (int k = 0; k < 12; k++)
	{
		cin >> x >> y;
		matrix[x].push_back(y);
	}*/

	for (int i = 1; i <= n; i++)
	{
		if (V[i].color != 0)
			continue;
		CriticalPath(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (V[i].eft > length)
			length = V[i].eft;
	}
	cout << length << endl;

	return 0;
}