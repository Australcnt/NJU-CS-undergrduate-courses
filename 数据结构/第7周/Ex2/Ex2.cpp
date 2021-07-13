#include <iostream>

using namespace std;

struct element//三元组
{
	int row;
	int column;
	int value;
};

struct matrix//矩阵
{
	element* sparse_matrix;//三元组表
	int rows;
	int columns;
}A, B, C;

int main()
{
	cin >> A.rows;
	cin >> A.columns;
	B.rows = A.columns;
	cin >> B.columns;
	A.sparse_matrix = new element[1000000];
	B.sparse_matrix = new element[1000000];
	C.sparse_matrix = new element[1000000];
	int count_A = 0, count_B = 0;
	for (int i = 0; i < A.rows; i++)//创建矩阵A的三元组表
	{
		for (int j = 0; j < A.columns; j++)
		{
			int value;
			cin >> value;
			if(value)
			{
				A.sparse_matrix[count_A].row = i;
				A.sparse_matrix[count_A].column = j;
				A.sparse_matrix[count_A].value = value;
				count_A++;
			}
		}
	}
	for (int i = 0; i < B.rows; i++)//创建矩阵B的三元组表
	{
		for (int j = 0; j < B.columns; j++)
		{
			int value;
			cin >> value;
			if (value)
			{
				B.sparse_matrix[count_B].row = i;
				B.sparse_matrix[count_B].column = j;
				B.sparse_matrix[count_B].value = value;
				count_B++;
			}
		}
	}
	int* row_size_B = new int[B.rows];//矩阵B每行非零元素的个数
	int* row_start_B = new int[B.rows + 1];//矩阵B每行非零元素在B的三元组表中开始的位置
	int* temp = new int[B.columns];
	int current_A = 0, count_C = 0;
	int row_A = 0, column_A = 0, column_B = 0;
	for (int i = 0; i < B.rows; i++)//初始化为0
		row_size_B[i] = 0;
	for (int i = 0; i < count_B; i++)//计算矩阵B每行非零元素的个数
		row_size_B[B.sparse_matrix[i].row]++;
	row_start_B[0] = 0;//初始化为0
	for (int i = 1; i < B.rows + 1; i++)//计算矩阵B第i行非零元素在B的三元组表中开始的位置
		row_start_B[i] = row_start_B[i - 1] + row_size_B[i - 1];
	while (current_A < count_A)
	{
		row_A = A.sparse_matrix[current_A].row;
		for (int i = 0; i < B.columns; i++)//初始化为0
			temp[i] = 0;
		while (current_A < count_A && A.sparse_matrix[current_A].row == row_A)
		{
			column_A = A.sparse_matrix[current_A].column;
			for (int i = row_start_B[column_A]; i < row_start_B[column_A + 1]; i++)
			{
				column_B = B.sparse_matrix[i].column;
				temp[column_B] += A.sparse_matrix[current_A].value * B.sparse_matrix[i].value;
			}
			current_A++;
		}
		for (int i = 0; i < B.columns; i++)
		{
			if(temp[i])
			{
				C.sparse_matrix[count_C].row = row_A;
				C.sparse_matrix[count_C].column = i;
				C.sparse_matrix[count_C].value = temp[i];
				count_C++;
			}
		}
	}
	C.rows = A.rows;
	C.columns = B.columns;
	int current_C = 0;
	//输出矩阵C的元素
	for (int i = 0; i < C.rows; i++)
	{
		for (int j = 0; j < C.columns; j++)
		{
			if (current_C < count_C && i == C.sparse_matrix[current_C].row && j == C.sparse_matrix[current_C].column)
			{
				cout << C.sparse_matrix[current_C].value << ' ';
				current_C++;
			}
			else
				cout << "0 ";
		}
		cout << endl;
	}
	return 0;
}