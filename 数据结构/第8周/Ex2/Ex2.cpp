#include <iostream>

using namespace std;

int id[1000000];

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> id[i];
	long long first = 999999999999999, third = -999999999999999;
	for (int j = 0; j < num; j++)
	{
		if (id[j] < first)
			first = id[j];
		if (id[j] > third)
			third = id[j];
		if (first != 999999999999999 && third != -999999999999999 && id[j] > first && id[j] < third)
		{
			cout << "True" << endl;
			return 0;
		}
	}
	cout << "False" << endl;
	return 0;
}