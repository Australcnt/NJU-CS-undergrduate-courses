#include <iostream>

using namespace std;

struct Node
{
	int computer1;//�����1
	int computer2;//�����2
	long long cost;//�����ӵ��޽�����
};

Node* node_store;
int* parent;
long long cost_sum = 0;
int build_count = 0;

void QuickSort(int first, int last);//��������
int Split(int first, int last);//Ѱ�ҷָ��
int Find(int x);//Ѱ�Ҹ����
int Union(int root1, int root2);//�ϲ���������

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	node_store = new Node[m];
	parent = new int[n + 1];
	for (int i = 0; i <= n; i++)//������ʼ��Ϊ�Լ�
		parent[i] = -1;
	for (int i = 0; i < m; i++)//�洢�����ӵ����
	{
		cin >> node_store[i].computer1;
		cin >> node_store[i].computer2;
		cin >> node_store[i].cost;
	}
	QuickSort(0, m - 1);//��������
	for (int i = 0; build_count < n - 1; i++)//���޽�����Ϊ n-1 ʱ����ѭ��
	{
		if (Find(node_store[i].computer1) != Find(node_store[i].computer2))//��δ��ͨ����̨���������
		{
			Union(node_store[i].computer1, node_store[i].computer2);
			cost_sum += node_store[i].cost;//���������ӷ���
			build_count++;//�����޽�����
		}
	}
	cout << cost_sum << endl;//��������ӷ���
	return 0;
}

void QuickSort(int first, int last)//��������
{
	if (first < last)
	{
		int split_point= Split(first, last);//Ѱ�ҷָ��
		QuickSort(first, split_point - 1);//�Էָ������Ĳ��ֽ�������
		QuickSort(split_point + 1, last);//�Էָ�����ҵĲ��ֽ�������
	}
}

int Split(int first, int last)//Ѱ�ҷָ��
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

int Find(int x)//Ѱ�Ҹ����
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

int Union(int root1, int root2)//�ϲ��������ϣ����ݽ����Ŀ��
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