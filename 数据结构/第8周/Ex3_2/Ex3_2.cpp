#include <iostream>

using namespace std;

int bus_count[1000000] = { 0 };

int main()
{
	int num = 0;
	cin >> num;
	int station = 0;
	int up_station = 0, down_station = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> up_station >> down_station;
		for (int k = up_station; k <= down_station; k++)
			bus_count[k]++;
		if (up_station > station)
			station = up_station;
		if (down_station > station)
			station = down_station;
	}
	int max = 0;
	for (int j = 1; j <= station; j++)
	{
		if (bus_count[j] > max)
			max = bus_count[j];
	}
	cout << max << endl;
	return 0;
}