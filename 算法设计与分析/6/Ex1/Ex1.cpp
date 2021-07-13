#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	int color;
	int back;
	int discovertime;
	int parent;
	Node() { color = 0, back = 0, discovertime = 0, parent = -1; }
};

struct Edge
{
	int u;
	int v;
};

int n;
int root = 0;
int subtree_num = 0;
int timer = 0;

vector<vector<int>>matrix;
Node* V = { 0 };

vector<int>articulation_point;
vector<Edge>bridge;

bool operator == (const Edge& edge1, const Edge& edge2)
{
	return edge1.u == edge2.u && edge1.v == edge2.v;
}

void dfs(int u)
{
	V[u].color = 1;
	timer++;
	V[u].discovertime = timer;
	V[u].back = V[u].discovertime;
	for (int j = 0; j < matrix[u].size(); j++)
	{
		int v = matrix[u][j];
		if (V[v].color == 0)
		{
			V[v].parent = u;
			if (u == root)
				subtree_num++;
			dfs(v);
			if (V[v].back >= V[u].discovertime) // ¸îµã
			{
				if (find(articulation_point.begin(), articulation_point.end(), u) == articulation_point.end())
				{
					if (u != root)
						articulation_point.push_back(u);
				}
			}
			if (V[v].back > V[u].discovertime) // ÇÅ
			{
				Edge edge;
				if (u < v)
				{
					edge.u = u;
					edge.v = v;
				}
				else
				{
					edge.u = v;
					edge.v = u;
				}
				if (find(bridge.begin(), bridge.end(), edge) == bridge.end())
					bridge.push_back(edge);
			}
			if (V[v].back < V[u].back)
				V[u].back = V[v].back;
		}
		else
		{
			if (V[v].color == 1 && v != V[u].parent)
			{
				if (V[v].discovertime < V[u].back)
					V[u].back = V[v].discovertime;
			}
		}
	}
	V[u].color = 2;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int>neighbors;
		matrix.push_back(neighbors);
	}
	V = new Node[n];
	int i, j;
	while (cin >> i >> j)
	{
		matrix[i].push_back(j);
		matrix[j].push_back(i);
	}
	/*for (int k = 0; k < 5; k++)
	{
		cin >> i >> j;
		matrix[i].push_back(j);
		matrix[j].push_back(i);
		root = i;
	}*/

	/*dfs(root);
	if (subtree_num >= 2)
		articulation_point.push_back(root);*/
	for (int i = 0; i < n; i++)
	{
		if (V[i].color != 0)
			continue;
		dfs(i);
		if (subtree_num >= 2)
			articulation_point.push_back(i);
		subtree_num = 0;
	}
	
	sort(articulation_point.begin(), articulation_point.end());
	sort(bridge.begin(), bridge.end(), [](Edge edge1, Edge edge2) {return edge1.u < edge2.u || (edge1.u == edge2.u && edge1.v < edge2.v); });

	for (auto i = articulation_point.begin(); i != articulation_point.end(); i++)
		cout << *i << endl;
	for (auto i = bridge.begin(); i != bridge.end(); i++)
		cout << (*i).u << " " << (*i).v << endl;

	return 0;
}