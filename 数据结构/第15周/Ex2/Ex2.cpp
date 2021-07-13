#include <iostream>

using namespace std;

int m, n;
int matrix[500][500] = { 0 };//猫咪数目
int traversal_flag[500][500] = { 0 };//是否遍历过
int max_matrix[500][500] = { 0 };//从该结点进入可遍历的结点数
int max_num = 0;//可遍历的最大结点数

void traversal(int x, int y);//遍历
int max(int num1, int num2, int num3, int num4);//最大值

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
			if (!traversal_flag[i][j])//若未遍历过该结点，则遍历
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
	if (x != 0)//不为第一行
	{
		if (matrix[x][y] < matrix[x - 1][y])
		{
			if (!traversal_flag[x - 1][y])
				traversal(x - 1, y);
			num1 = max_matrix[x - 1][y];
		}
	}
	if (x != m - 1)//不为最后一行
	{
		if (matrix[x][y] < matrix[x + 1][y])
		{
			if (!traversal_flag[x + 1][y])
				traversal(x + 1, y);
			num2 = max_matrix[x + 1][y];
		}
	}
	if (y != 0)//不为第一列
	{
		if (matrix[x][y] < matrix[x][y - 1])
		{
			if (!traversal_flag[x][y - 1])
				traversal(x, y - 1);
			num3 = max_matrix[x][y - 1];
		}
	}
	if (y != n - 1)//不为最后一列
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