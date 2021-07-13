#include <iostream>
#include <math.h>

using namespace std;

int* id;//���ݴ洢
int* parent;//�����洢
int* friend_count;//ÿ������Ȧ��������Ŀ�洢

int Find(int x);//Ѱ�Ҹ����
int Union(int root1, int root2);//�ϲ���������Ȧ

int main()
{
	int n = 0;
	cin >> n;
	id = new int[n];
	int max_id = 0;//�������
	for (int i = 0; i < n; i++)
	{
		cin >> id[i];
		if (id[i] > max_id)
			max_id = id[i];
	}
	parent = new int[max_id + 1];
	for (int i = 0; i <= max_id; i++)//������ʼ��Ϊ�Լ�
		parent[i] = -1;
	for (int i = 0; i < n; i++)
	{
		for (int k = 2; k <= sqrt(id[i]); k++)
		{
			if (id[i] % k == 0)//�ϲ�����������
			{
				if (Find(id[i]) != Find(k))//������ͬһ����Ȧ
				    Union(id[i], k);
				if (Find(id[i]) != Find(id[i] / k) && Find(k) != Find(id[i] / k))//������ͬһ����Ȧ�Ҳ���������ͬ
				    Union(id[i], id[i] / k);
			}
		}
	}
	int max_friend = 0;
	friend_count = new int[max_id + 1];
	for (int i = 0; i <= max_id; i++)
		friend_count[i] = 0;
	for (int i = 0; i < n; i++)//����ÿһ������Ȧ��������Ŀ���������������Ȧ��������Ŀ
	{
		friend_count[Find(id[i])]++;
		if (friend_count[Find(id[i])] > max_friend)
			max_friend = friend_count[Find(id[i])];
	}
	cout << max_friend << endl;
	return 0;
}

int Find(int x)//Ѱ�Ҹ����
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

int Union(int root1, int root2)//�ϲ���������Ȧ
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