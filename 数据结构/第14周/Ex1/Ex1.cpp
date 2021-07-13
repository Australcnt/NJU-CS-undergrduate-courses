#include <iostream>

using namespace std;

int* parent;//�����
int* left_hole;//����ͨ����ʣ���δ��Ķ�����
int* entry_hole;//����ͨ����ʣ���δ��Ķ���

int Find(int x);//Ѱ�Ҹ����
void WeightedUnion(int Root1, int Root2);//�ϲ�������ͨ����

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
		if (root1 != root2)//���������Ѳ���ͬһ��ͨ����
		{
			WeightedUnion(root1, root2);//�ϲ�������ͨ����
		}
	}
	int hole = 0;//δ��Ķ���
	int opt_hole = 3000;//��Ҫ��ס�Ķ���
	for (int i = 0; i < n; i++)
	{
		cin >> hole;
		left_hole[Find(hole)]++;//���¸���ͨ����ʣ���δ��Ķ�����
		entry_hole[Find(hole)] = hole;//���¸���ͨ����ʣ���δ��Ķ���
		if (hole < opt_hole)//opt_hole��ʼ��Ϊ����δ��Ķ����������С���Ǹ�
			opt_hole = hole;
	}
	int root = 0;
	int max_group = 0;
	for (int i = 0; i < m; i++)//ѡ��ʹ���ӻ��Χ��С���Ķ���
	{
		root = Find(i);
		if ((left_hole[root] == 1) && (-parent[root] > max_group))//������ͨ����ֻʣһ������δ�⣬��������Ŀ���ڵ�ǰѡ�����ͨ����
		{
			max_group = -parent[root];
			opt_hole = entry_hole[root];
		}
	}
	cout << opt_hole << endl;
	return 0;
}

int Find(int x)//Ѱ�Ҹ����
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

void WeightedUnion(int Root1, int Root2)//�ϲ�������ͨ����������������Ŀ��
{
	Root1 = Find(Root1);
	Root2 = Find(Root2);
	int temp = parent[Root1] + parent[Root2];
	if (parent[Root2] < parent[Root1]) 
	{
		parent[Root1] = Root2;     //Root2�н������
		parent[Root2] = temp;      //Root1ָ��Root2
	}
	else 
	{
		parent[Root2] = Root1;     //Root1�н������
		parent[Root1] = temp;      //Root2ָ��Root1
	}
}