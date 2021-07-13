#include <iostream>

using namespace std;

int cmax, n, sp, m;//最大容量 cmax(<=100)，院楼的数量 n(<=500)，问题院楼编号 sp，院楼间路的数量 m
int bike[501];//各结点的自行车数目
int matrix[501][501];//上三角邻接矩阵矩阵
int dist[501];//最短路径数组
int path[501];//最短路径上该结点的前一个结点
bool check[501];//最短路径集合
int min_cost = INT32_MAX;//最短路径的长度
int final_need_bike = INT32_MAX;//带去的自行车数
int final_back_bike = INT32_MAX;//带回的自行车数
int final_route[501];//最短路径的路线
int final_building_count = 0;//最短路径的结点数
int max_delete_count = 0;//与sp邻接的边数
int delete_count = 0;//已删除的与sp邻接的边数

int dist_min();//寻找dist中的最短路径，且不在最短路径集合中

int main()
{
	cin >> cmax >> n >> sp >> m;//最大容量 cmax(<=100)，院楼的数量 n(<=500)，问题院楼编号 sp，院楼间路的数量 m
	for (int i = 1; i <= n; i++)//存储各结点的自行车数目
		cin >> bike[i];
	for (int i = 0; i <= n; i++)//初始化上三角邻接矩阵
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
		if (a == sp || b == sp)//记录与sp邻接的边数
			max_delete_count++;
	}
	while (1)
	{
		for (int i = 1; i <= n; i++)//初始化最短路径数组
			dist[i] = matrix[0][i];
		for (int i = 0; i <= n; i++)//初始化最短路径集合
			check[i] = false;
		for (int i = 1; i <= n; i++)//初始化各结点在最短路径上的前一个结点
		{
			if (dist[i] < INT32_MAX)
				path[i] = 0;
			else
				path[i] = -1;
		}
		check[0] = true;//初始化管理处信息
		dist[0] = INT32_MAX;//初始化管理处信息
		int check_count = 0;//最短路径集合中的结点数
		int min = dist_min();//寻找dist中的最短路径，且不在最短路径集合中
		int temp_i = 0;
		int temp_min = 0;
		int length1 = 0;//路径一
		int length2 = 0;//路径二
		while (check_count < n)//计算最小路径
		{
			for (int i = 1; i <= n; i++)
			{
				if (i == min)//若i与min相等，则无需修改最短路径，跳过
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
				if (length1 <= length2 || matrix[temp_i][temp_min] == INT32_MAX)//若length1<length2或结点i与结点min间无边，则无需修改最短路径
					dist[i] = length1;
				else
				{
					dist[i] = length2;
					path[i] = min;
				}
			}
			check[min] = true;//将该边归入最小路径集合
			check_count++;//最小路径集合的边数加一
			min = dist_min();//寻找dist中最小的路径，且不在最小路径集合中
		}
		if (dist[sp] > min_cost)//若当前图的最短路径大于原图最短路径，则结束循环
			break;
		min_cost = dist[sp];
		int need_bike = 0;
		int need_bike_max = 0;//带去的自行车数
		int back_bike = 0;//带回的自行车数
		int building_count = 0;//最短路径的结点数
		int route[501];//当前路径的路线
		int building = sp;
		while (building != 0)//记录当前路径的路线
		{
			route[building_count] = building;
			building = path[building];
			building_count++;
		}
		route[building_count] = 0;
		for (int i = building_count - 1; i >= 0; i--)//计算带去的自行车数，管理处的车数不纳入计算
		{
			need_bike = need_bike + cmax / 2 - bike[route[i]];
			if (need_bike > need_bike_max)
				need_bike_max = need_bike;
		}
		back_bike = need_bike_max;
		for (int i = building_count - 1; i >= 0; i--)//计算带回的自行车数，管理处的车数不纳入计算
		{
			back_bike = back_bike - cmax / 2 + bike[route[i]];
		}
		if ((need_bike_max < final_need_bike) || ((need_bike_max == final_need_bike) && (back_bike < final_back_bike)))//若带去车数更少或带去车数相同但带回车数更少，则更新最短路径
		{
			final_need_bike = need_bike_max;
			final_back_bike = back_bike;
			final_building_count = building_count;
			for (int i = 0; i < final_building_count; i++)
				final_route[i] = route[i];
		}
		if (path[sp] < sp)//删去该最短路径与sp邻接的边
			matrix[path[sp]][sp] = INT32_MAX;
		else
			matrix[sp][path[sp]] = INT32_MAX;
		delete_count++;
		if (delete_count == max_delete_count)//若已将sp的邻接边全部删除，则结束循环
			break;
	}
	cout << final_need_bike << ' ';
	cout << final_route[final_building_count];
	for (int i = final_building_count - 1; i >= 0; i--)
		cout << "->" << final_route[i];
	cout << ' ' << final_back_bike << endl;
	return 0;
}

int dist_min()//寻找dist中的最短路径，且不在最短路径集合中
{
	int min = 0;
	for (int i = 1; i <= n; i++)
		if (check[i] == false && dist[i] < dist[min])
			min = i;
	return min;
}