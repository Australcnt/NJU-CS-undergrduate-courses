#include <iostream>

using namespace std;

int cmax, n, sp, m;//������� cmax(<=100)��Ժ¥������ n(<=500)������Ժ¥��� sp��Ժ¥��·������ m
int bike[501];//���������г���Ŀ
int matrix[501][501];//�������ڽӾ������
int dist[501];//���·������
int path[501];//���·���ϸý���ǰһ�����
bool check[501];//���·������
int min_cost = INT32_MAX;//���·���ĳ���
int final_need_bike = INT32_MAX;//��ȥ�����г���
int final_back_bike = INT32_MAX;//���ص����г���
int final_route[501];//���·����·��
int final_building_count = 0;//���·���Ľ����
int max_delete_count = 0;//��sp�ڽӵı���
int delete_count = 0;//��ɾ������sp�ڽӵı���

int dist_min();//Ѱ��dist�е����·�����Ҳ������·��������

int main()
{
	cin >> cmax >> n >> sp >> m;//������� cmax(<=100)��Ժ¥������ n(<=500)������Ժ¥��� sp��Ժ¥��·������ m
	for (int i = 1; i <= n; i++)//�洢���������г���Ŀ
		cin >> bike[i];
	for (int i = 0; i <= n; i++)//��ʼ���������ڽӾ���
		for (int j = i + 1; j <= n; j++)
			matrix[i][j] = INT32_MAX;
	int a = 0;
	int b = 0;
	int temp = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (b < a)
		{
			temp = a;
			a = b;
			b = temp;
		}
		cin >> matrix[a][b];
		if (a == sp || b == sp)//��¼��sp�ڽӵı���
			max_delete_count++;
	}
	while (1)
	{
		for (int i = 1; i <= n; i++)//��ʼ�����·������
			dist[i] = matrix[0][i];
		for (int i = 0; i <= n; i++)//��ʼ�����·������
			check[i] = false;
		for (int i = 1; i <= n; i++)//��ʼ������������·���ϵ�ǰһ�����
		{
			if (dist[i] < INT32_MAX)
				path[i] = 0;
			else
				path[i] = -1;
		}
		check[0] = true;//��ʼ��������Ϣ
		dist[0] = INT32_MAX;//��ʼ��������Ϣ
		int check_count = 0;//���·�������еĽ����
		int min = dist_min();//Ѱ��dist�е����·�����Ҳ������·��������
		int temp_i = 0;
		int temp_min = 0;
		int length1 = 0;//·��һ
		int length2 = 0;//·����
		while (check_count < n)//������С·��
		{
			for (int i = 1; i <= n; i++)
			{
				if (i == min)//��i��min��ȣ��������޸����·��������
					continue;
				length1 = dist[i];
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
				length2 = dist[min] + matrix[temp_i][temp_min];
				if (length1 <= length2 || matrix[temp_i][temp_min] == INT32_MAX)//��length1<length2����i����min���ޱߣ��������޸����·��
					dist[i] = length1;
				else
				{
					dist[i] = length2;
					path[i] = min;
				}
			}
			check[min] = true;//���ñ߹�����С·������
			check_count++;//��С·�����ϵı�����һ
			min = dist_min();//Ѱ��dist����С��·�����Ҳ�����С·��������
		}
		if (dist[sp] > min_cost)//����ǰͼ�����·������ԭͼ���·���������ѭ��
			break;
		min_cost = dist[sp];
		int need_bike = 0;
		int need_bike_max = 0;//��ȥ�����г���
		int back_bike = 0;//���ص����г���
		int building_count = 0;//���·���Ľ����
		int route[501];//��ǰ·����·��
		int building = sp;
		while (building != 0)//��¼��ǰ·����·��
		{
			route[building_count] = building;
			building = path[building];
			building_count++;
		}
		route[building_count] = 0;
		for (int i = building_count - 1; i >= 0; i--)//�����ȥ�����г����������ĳ������������
		{
			need_bike = need_bike + cmax / 2 - bike[route[i]];
			if (need_bike > need_bike_max)
				need_bike_max = need_bike;
		}
		back_bike = need_bike_max;
		for (int i = building_count - 1; i >= 0; i--)//������ص����г����������ĳ������������
		{
			back_bike = back_bike - cmax / 2 + bike[route[i]];
		}
		if ((need_bike_max < final_need_bike) || ((need_bike_max == final_need_bike) && (back_bike < final_back_bike)))//����ȥ�������ٻ��ȥ������ͬ�����س������٣���������·��
		{
			final_need_bike = need_bike_max;
			final_back_bike = back_bike;
			final_building_count = building_count;
			for (int i = 0; i < final_building_count; i++)
				final_route[i] = route[i];
		}
		if (path[sp] < sp)//ɾȥ�����·����sp�ڽӵı�
			matrix[path[sp]][sp] = INT32_MAX;
		else
			matrix[sp][path[sp]] = INT32_MAX;
		delete_count++;
		if (delete_count == max_delete_count)//���ѽ�sp���ڽӱ�ȫ��ɾ���������ѭ��
			break;
	}
	cout << final_need_bike << ' ';
	cout << final_route[final_building_count];
	for (int i = final_building_count - 1; i >= 0; i--)
		cout << "->" << final_route[i];
	cout << ' ' << final_back_bike << endl;
	return 0;
}

int dist_min()//Ѱ��dist�е����·�����Ҳ������·��������
{
	int min = 0;
	for (int i = 1; i <= n; i++)
		if (check[i] == false && dist[i] < dist[min])
			min = i;
	return min;
}