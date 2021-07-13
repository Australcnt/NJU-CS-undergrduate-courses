#include <iostream>

using namespace std;

struct Node
{
	int computer1;//计算机1
	int computer2;//计算机2
	long long cost;//该连接的修建费用
};

Node* node_store;
int* parent;
long long cost_sum = 0;
int build_count = 0;

void QuickSort(int first, int last);//快速排序
int Split(int first, int last);//寻找分割点
int Find(int x);//寻找根结点
int Union(int root1, int root2);//合并两个集合

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	node_store = new Node[m];
	parent = new int[n + 1];
	for (int i = 0; i <= n; i++)//根结点初始化为自己
		parent[i] = -1;
	for (int i = 0; i < m; i++)//存储可连接的情况
	{
		cin >> node_store[i].computer1;
		cin >> node_store[i].computer2;
		cin >> node_store[i].cost;
	}
	QuickSort(0, m - 1);//快速排序
	for (int i = 0; build_count < n - 1; i++)//当修建条数为 n-1 时结束循环
	{
		if (Find(node_store[i].computer1) != Find(node_store[i].computer2))//将未连通的两台计算机相连
		{
			Union(node_store[i].computer1, node_store[i].computer2);
			cost_sum += node_store[i].cost;//计算总连接费用
			build_count++;//更新修建条数
		}
	}
	cout << cost_sum << endl;//输出总连接费用
	return 0;
}

void QuickSort(int first, int last)//快速排序
{
	if (first < last)
	{
		int split_point= Split(first, last);//寻找分割点
		QuickSort(first, split_point - 1);//对分割点以左的部分进行排序
		QuickSort(split_point + 1, last);//对分割点以右的部分进行排序
	}
}

int Split(int first, int last)//寻找分割点
{
	int split_point = first;
	long long pivot = node_store[first].cost;
	for (int unknown = first + 1; unknown <= last; unknown++)
	{
		if (node_store[unknown].cost < pivot)
		{
			split_point++;
			Node t = node_store[split_point];
			node_store[split_point] = node_store[unknown];
			node_store[unknown] = t;
		}
	}
	Node p = node_store[first];
	node_store[first] = node_store[split_point];
	node_store[split_point] = p;
	return split_point;
}

int Find(int x)//寻找根结点
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

int Union(int root1, int root2)//合并两个集合（根据结点数目）
{
	root1 = Find(root1);
	root2 = Find(root2);
	int temp = parent[root1] + parent[root2];
	if (parent[root1] < parent[root2])
	{
		parent[root2] = root1;
		parent[root1] = temp;
	}
	else
	{
		parent[root1] = root2;
		parent[root2] = temp;
	}
	return temp;
}