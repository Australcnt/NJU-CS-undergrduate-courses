#include <iostream>

using namespace std;

int matrix[2048][2048];

int main()
{
	int row = 0, column = 0;
	cin >> row;
	cin >> column;
	for (int i = 0; i < row; i++)//存储矩阵元素
		for (int j = 0; j < column; j++)
			cin >> matrix[i][j];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (!matrix[i][j])//将本可以获奖，但被其他人牵连，导致无法获奖的小蓝鲸分数置为-1（实质上是置为0）
			{
				for (int m = 0; m < row; m++)
				{
					if (matrix[m][j])
						matrix[m][j] = -1;
				}
				for (int n = 0; n < column; n++)
				{
					if (matrix[i][n])
						matrix[i][n] = -1;
				}
			}
		}
	}
	for (int i = 0; i < row; i++)//输出矩阵元素
	{
		for (int j = 0; j < column; j++)
		{
			if (matrix[i][j] == -1)
				cout << "0 ";
			else
				cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}