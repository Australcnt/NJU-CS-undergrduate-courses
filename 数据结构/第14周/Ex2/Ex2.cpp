#include <iostream>
#include <stdlib.h>

using namespace std;

struct Loc//�������
{
	int x;
	int y;
};

int n;//��������Ŀ
int matrix[1000][1000];//�����Ǿ���
Loc location[1000];//�������洢��������㡢�յ�ʹ����ţ�
int dist[1000];//��С·������
bool dist_check[1000];//�Ƿ�����С·��������

int dist_min();

int main()
{
	
	cin >> n;
	cin >> location[0].x >> location[0].y;
	cin >> location[2 * n + 1].x >> location[2 * n + 1].y;
	for (int i = 1; i <= n; i++)
	{
		cin >> location[2 * i - 1].x >> location[2 * i - 1].y;
		cin >> location[2 * i].x >> location[2 * i].y;
	}
	for (int i = 0; i <= 2 * n + 1; i++)//�ڽӾ�����ȫͼ��
	{
		for (int j = i + 1; j <= 2 * n + 1; j++)
		{
			if ((i + 1) / 2 == (j + 1) / 2)//�ж��Ƿ�Ϊͬһ�Դ�����
			{
				matrix[i][j] = 10;
			}
			else
			{
				matrix[i][j] = abs(location[i].x - location[j].x) + abs(location[i].y - location[j].y);
			}
		}
	}
	for (int i = 1; i <= 2 * n + 1; i++)
		dist[i]= abs(location[i].x - location[0].x) + abs(location[i].y - location[0].y);
	dist[0] = INT32_MAX;
	for (int i = 0; i <= 2 * n + 1; i++)
		dist_check[i] = false;
	int check_count = 0;//��С·�����ϵı���
	int min = dist_min();//Ѱ��dist����С��·�����Ҳ�����С·��������
	int temp_i = 0;
	int temp_min = 0;
	int length1 = 0;
	int length2 = 0;
	while (check_count <= 2 * n + 1)
	{
		for (int i = 1; i <= 2 * n + 1; i++)
		{
			if (i == min)
				continue;
			length1 = matrix[0][i];
			if (i < min)
			{
				temp_i = i;
				temp_min = min;
			}
			else
			{
				temp_i = min;
				temp_min = i;
			}
			length2 = matrix[0][min] + matrix[temp_i][temp_min];
			if (length1 < length2)
				dist[i] = length1;
			else
			{
				dist[i] = length2;
				matrix[0][i] = length2;
			}
		}
		dist_check[min] = true;//���ñ߹�����С·������
		check_count++;//��С·�����ϵı�����һ
		min = dist_min();//Ѱ��dist����С��·�����Ҳ�����С·��������
	}
	cout << dist[2 * n + 1] << endl;//������յ����С·������
	return 0;
}

int dist_min()//Ѱ��dist����С��·�����Ҳ�����С·��������
{
	int min = 0;
	for (int i = 1; i <= 2 * n + 1; i++)
		if (dist_check[i] == false && dist[i] < dist[min])
			min = i;
	return min;
}