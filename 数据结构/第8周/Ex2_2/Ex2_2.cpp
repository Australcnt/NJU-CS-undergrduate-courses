#include <iostream>

using namespace std;

int id[1000000];

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> id[i];
	for (int i = 0; i < num - 2; i++)
	{
		for (int j = i + 2; j < num; j++)
		{
			if (id[i] >= id[j])
				continue;
			for (int k = i + 1; k <= j; k++)
			{
				if (id[k] > id[j])
				{
					cout << "True" << endl;
					return 0;
				}
			}
		}
	}
	cout << "False" << endl;
	return 0;
}