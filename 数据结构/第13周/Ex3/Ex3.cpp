#include <iostream>

using namespace std;

int matrix[512][512];//����洢
int parent[262144];//�����洢
int star = 0;//������Ŀ

int Find(int x);//Ѱ�Ҹ����
int Union(int root1, int root2);//��������½��

int main()
{
	int row = 0, col = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j])
				star++;
		}
	}
	for (int i = 0; i < row * col; i++)//������ʼ��Ϊ�Լ�
		parent[i] = -1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)//��Ϊ�󺣣�������
				continue;
			int location = i * col + j;
			if (j != col - 1 && matrix[i][j + 1] && Find(location) != Find(location + 1))//�����ұߵ�½��
				Union(location, location + 1);
			if (i != row - 1 && matrix[i + 1][j] && Find(location) != Find(location + col))//���������½��
				Union(location, location + col);
		}
	}
	cout << star << endl;
	return 0;
}

int Find(int x)//Ѱ�Ҹ����
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

int Union(int root1, int root2)//��������½�أ����ݽ������
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
	star--;
	return temp;
}