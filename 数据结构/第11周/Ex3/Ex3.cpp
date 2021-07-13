#include <iostream>

using namespace std;

int mahjong[900000];//麻将序列数组
int location[900000];//麻将位置数组
int exchange_times = 0;//交换次数

int main()
{
	int n = 0;//麻将数目
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> mahjong[i];//存储麻将序列
		location[mahjong[i]] = i;//存储麻将位置
	}
	for (int i = 0; i < n; i += 2)
	{
		if (mahjong[i] / 2 == mahjong[i + 1] / 2)//若两个麻将为一对牌，则无需交换操作
			continue;
		if (mahjong[i] % 2 == 0)//该麻将为偶数
		{
			int temp = 0, temp_loc = 0;
			temp = mahjong[i + 1];//将该麻将的另一半与下一个麻将交换
			mahjong[i + 1] = mahjong[location[mahjong[i] + 1]];
			mahjong[location[mahjong[i] + 1]] = temp;
			temp_loc = location[mahjong[location[mahjong[i] + 1]]];//将该麻将的另一半的位置与下一个麻将的位置交换
			location[mahjong[location[mahjong[i] + 1]]] = location[mahjong[i + 1]];
			location[mahjong[i + 1]] = temp_loc;
			exchange_times++;
		}
		else//该麻将为奇数
		{
			int temp = 0, temp_loc = 0;
			temp = mahjong[i + 1];//将该麻将的另一半与下一个麻将交换
			mahjong[i + 1] = mahjong[location[mahjong[i] - 1]];
			mahjong[location[mahjong[i] - 1]] = temp;
			temp_loc = location[mahjong[location[mahjong[i] - 1]]];//将该麻将的另一半的位置与下一个麻将的位置交换
			location[mahjong[location[mahjong[i] - 1]]] = location[mahjong[i + 1]];
			location[mahjong[i + 1]] = temp_loc;
			exchange_times++;
		}
	}
	cout << exchange_times << endl;//输出交换次数
	return 0;
}