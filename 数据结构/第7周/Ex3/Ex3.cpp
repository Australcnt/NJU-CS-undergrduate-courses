#include <iostream>

using namespace std;

int matrix[2048][2048];

int main()
{
	int row = 0, column = 0;
	cin >> row;
	cin >> column;
	for (int i = 0; i < row; i++)//�洢����Ԫ��
		for (int j = 0; j < column; j++)
			cin >> matrix[i][j];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (!matrix[i][j])//�������Ի񽱣�����������ǣ���������޷��񽱵�С����������Ϊ-1��ʵ��������Ϊ0��
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
	for (int i = 0; i < row; i++)//�������Ԫ��
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