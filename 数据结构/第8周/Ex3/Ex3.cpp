#include <iostream>

using namespace std;

int up[1000000], down[1000000];

int main()
{
	int num = 0;
	cin >> num;
	int station = 0;
    int up_station = 0, down_station = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> up_station >> down_station;
		up[up_station]++;
		down[down_station]++;
		if (up_station > station)
			station = up_station;
		if (down_station > station)
			station = down_station;
	}
	int max = 0, cur = 0;
	for (int j = 1; j <= station; j++)
	{
		cur = cur + up[j] - down[j];
		if (cur > max)
			max = cur;
	}
	cout << max;
	return 0;
}