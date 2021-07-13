#include <iostream>

using namespace std;

long int partial_water_calculate(int column[], int left_wall, int right_wall);
long int water_calculate(int column[], int head, int tail);
void reverse(int column[], int left_wall, int right_wall);

int main()
{
	int column_number;
	cin >> column_number;
	int column[100000];
	for (int i = 0; i < column_number; i++)
		cin >> column[i];
	int left_wall = 0, right_wall = 1;
	long int water_collect = 0;
	water_collect += water_calculate(column, 0, column_number - 1);//计算雨水量
	cout << water_collect << endl;
	return 0;
}

long int water_calculate(int column[], int head, int tail)//计算总雨水量
{
	long int water = 0;
	int left_wall = head;//容器左壁
	int right_wall = head + 1;//容器右壁
	int column_number = tail - head + 1;
	if (column_number != 1 && column_number != 2)//柱子为1或2时，雨水量为0
	{
		while (right_wall != tail)
		{
			while (column[left_wall] > column[right_wall] && right_wall != tail)//直到右壁大于等于左壁或右壁到末尾时停下
				right_wall++;
			if (right_wall == left_wall + 1)//左壁和右壁相差为1时，无法构成容器，需同时向后移动一位，再继续操作
			{
				if (right_wall == tail)
					break;
				left_wall++;
				right_wall++;
				continue;
			}
			water += partial_water_calculate(column, left_wall, right_wall);
			if (right_wall == tail)
				break;
			left_wall = right_wall;
			right_wall++;
		}
	}
	return water;
}

long int partial_water_calculate(int column[], int left_wall, int right_wall)//计算单个容器雨水量
{
	int capacity = 0;
	long int water = 0;
	if (column[left_wall] <= column[right_wall])
	{
		capacity = column[left_wall];
		for (int i = left_wall + 1; i < right_wall; i++)
		{
			if (column[i] < capacity)
				water += (capacity - column[i]);
		}
	}
	else//右壁小于左壁时，需要反转该容器
	{
		reverse(column, left_wall, right_wall);
		water += water_calculate(column, left_wall, right_wall);
	}
	return water;
}

void reverse(int column[], int left_wall, int right_wall)//容器反转
{
	int temp = 0;
	for (int i = left_wall; i <= (left_wall + right_wall) / 2; i++)
	{
		temp = column[i];
		column[i] = column[right_wall + left_wall - i];
		column[right_wall + left_wall - i] = temp;
	}
}