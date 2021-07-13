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
	water_collect += water_calculate(column, 0, column_number - 1);//������ˮ��
	cout << water_collect << endl;
	return 0;
}

long int water_calculate(int column[], int head, int tail)//��������ˮ��
{
	long int water = 0;
	int left_wall = head;//�������
	int right_wall = head + 1;//�����ұ�
	int column_number = tail - head + 1;
	if (column_number != 1 && column_number != 2)//����Ϊ1��2ʱ����ˮ��Ϊ0
	{
		while (right_wall != tail)
		{
			while (column[left_wall] > column[right_wall] && right_wall != tail)//ֱ���ұڴ��ڵ�����ڻ��ұڵ�ĩβʱͣ��
				right_wall++;
			if (right_wall == left_wall + 1)//��ں��ұ����Ϊ1ʱ���޷�������������ͬʱ����ƶ�һλ���ټ�������
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

long int partial_water_calculate(int column[], int left_wall, int right_wall)//���㵥��������ˮ��
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
	else//�ұ�С�����ʱ����Ҫ��ת������
	{
		reverse(column, left_wall, right_wall);
		water += water_calculate(column, left_wall, right_wall);
	}
	return water;
}

void reverse(int column[], int left_wall, int right_wall)//������ת
{
	int temp = 0;
	for (int i = left_wall; i <= (left_wall + right_wall) / 2; i++)
	{
		temp = column[i];
		column[i] = column[right_wall + left_wall - i];
		column[right_wall + left_wall - i] = temp;
	}
}