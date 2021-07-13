#include <iostream>
#include <math.h>

using namespace std;

int* id;//数据存储
int* parent;//根结点存储
int* friend_count;//每个朋友圈的朋友数目存储

int Find(int x);//寻找根结点
int Union(int root1, int root2);//合并两个朋友圈

int main()
{
	int n = 0;
	cin >> n;
	id = new int[n];
	int max_id = 0;//最大数据
	for (int i = 0; i < n; i++)
	{
		cin >> id[i];
		if (id[i] > max_id)
			max_id = id[i];
	}
	parent = new int[max_id + 1];
	for (int i = 0; i <= max_id; i++)//根结点初始化为自己
		parent[i] = -1;
	for (int i = 0; i < n; i++)
	{
		for (int k = 2; k <= sqrt(id[i]); k++)
		{
			if (id[i] % k == 0)//合并该数的因数
			{
				if (Find(id[i]) != Find(k))//若不在同一朋友圈
				    Union(id[i], k);
				if (Find(id[i]) != Find(id[i] / k) && Find(k) != Find(id[i] / k))//若不在同一朋友圈且不与上数相同
				    Union(id[i], id[i] / k);
			}
		}
	}
	int max_friend = 0;
	friend_count = new int[max_id + 1];
	for (int i = 0; i <= max_id; i++)
		friend_count[i] = 0;
	for (int i = 0; i < n; i++)//计算每一个朋友圈的朋友数目，并更新最大朋友圈的朋友数目
	{
		friend_count[Find(id[i])]++;
		if (friend_count[Find(id[i])] > max_friend)
			max_friend = friend_count[Find(id[i])];
	}
	cout << max_friend << endl;
	return 0;
}

int Find(int x)//寻找根结点
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

int Union(int root1, int root2)//合并两个朋友圈
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