#include <iostream>

using namespace std;

int m, n;
int matrix[500][500] = { 0 };//è����Ŀ
int traversal_flag[500][500] = { 0 };//�Ƿ������
int max_matrix[500][500] = { 0 };//�Ӹý�����ɱ����Ľ����
int max_num = 0;//�ɱ������������

void traversal(int x, int y);//����
int max(int num1, int num2, int num3, int num4);//���ֵ

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!traversal_flag[i][j])//��δ�������ý�㣬�����
				traversal(i, j);
		}
	}
	cout << max_num << endl;
	return 0;
}

void traversal(int x, int y)
{
	traversal_flag[x][y] = 1;
	int num = 0;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	if (x != 0)//��Ϊ��һ��
	{
		if (matrix[x][y] < matrix[x - 1][y])
		{
			if (!traversal_flag[x - 1][y])
				traversal(x - 1, y);
			num1 = max_matrix[x - 1][y];
		}
	}
	if (x != m - 1)//��Ϊ���һ��
	{
		if (matrix[x][y] < matrix[x + 1][y])
		{
			if (!traversal_flag[x + 1][y])
				traversal(x + 1, y);
			num2 = max_matrix[x + 1][y];
		}
	}
	if (y != 0)//��Ϊ��һ��
	{
		if (matrix[x][y] < matrix[x][y - 1])
		{
			if (!traversal_flag[x][y - 1])
				traversal(x, y - 1);
			num3 = max_matrix[x][y - 1];
		}
	}
	if (y != n - 1)//��Ϊ���һ��
	{
		if (matrix[x][y] < matrix[x][y + 1])
		{
			if (!traversal_flag[x][y + 1])
				traversal(x, y + 1);
			num4 = max_matrix[x][y + 1];
		}
	}
	num = max(num1, num2, num3, num4);
	num++;
	max_matrix[x][y] = num;
	if (num > max_num)
		max_num = num;
}

int max(int num1, int num2, int num3, int num4)
{
	if (num1 < num2)
		num1 = num2;
	if (num1 < num3)
		num1 = num3;
	if (num1 < num4)
		num1 = num4;
	return num1;
}