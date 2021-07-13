#include <iostream>

using namespace std;

int* parent;//根结点
int* left_hole;//该连通分量剩余的未封的洞口数
int* entry_hole;//该连通分量剩余的未封的洞口

int Find(int x);//寻找根结点
void WeightedUnion(int Root1, int Root2);//合并两个连通分量

int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	parent = new int[m];
	left_hole = new int[m];
	entry_hole = new int[m];
	for (int i = 0; i < m; i++)
		parent[i] = -1;
	for (int i = 0; i < m; i++)
		left_hole[i] = 0;
	for (int i = 0; i < m; i++)
		entry_hole[i] = 0;
	int root1 = 0, root2 = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> root1 >> root2;
		root1 = Find(root1);
		root2 = Find(root2);
		if (root1 != root2)//若两个兔窝不在同一连通分量
		{
			WeightedUnion(root1, root2);//合并两个连通分量
		}
	}
	int hole = 0;//未封的洞口
	int opt_hole = 3000;//想要封住的洞口
	for (int i = 0; i < n; i++)
	{
		cin >> hole;
		left_hole[Find(hole)]++;//更新该连通分量剩余的未封的洞口数
		entry_hole[Find(hole)] = hole;//更新该连通分量剩余的未封的洞口
		if (hole < opt_hole)//opt_hole初始化为所有未封的洞口中序号最小的那个
			opt_hole = hole;
	}
	int root = 0;
	int max_group = 0;
	for (int i = 0; i < m; i++)//选择使兔子活动范围减小最多的洞口
	{
		root = Find(i);
		if ((left_hole[root] == 1) && (-parent[root] > max_group))//若该连通分量只剩一个洞口未封，且兔窝数目大于当前选择的连通分量
		{
			max_group = -parent[root];
			opt_hole = entry_hole[root];
		}
	}
	cout << opt_hole << endl;
	return 0;
}

int Find(int x)//寻找根结点
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

void WeightedUnion(int Root1, int Root2)//合并两个连通分量（根据兔窝数目）
{
	Root1 = Find(Root1);
	Root2 = Find(Root2);
	int temp = parent[Root1] + parent[Root2];
	if (parent[Root2] < parent[Root1]) 
	{
		parent[Root1] = Root2;     //Root2中结点数多
		parent[Root2] = temp;      //Root1指向Root2
	}
	else 
	{
		parent[Root2] = Root1;     //Root1中结点数多
		parent[Root1] = temp;      //Root2指向Root1
	}
}