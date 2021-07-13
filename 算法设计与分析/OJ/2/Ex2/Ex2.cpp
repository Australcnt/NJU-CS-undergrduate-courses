#include <iostream>

using namespace std;

int main()
{
	int length = 0;
	int arr[10000];
	int c = 0;
	cin >> length;
	for (int i = 0; i < length; i++)
		cin >> arr[i];
	cin >> c;
	int a = 0, b = 0;
	int end = length;
	for (int i = 0; i < end; i++)
	{
		a = arr[i];
		b = c - a;
		if (b == a)
			continue;
		for (int j = 0; j < length; j++)
		{
			if (arr[j] == b)
			{
				cout << a << " " << b << endl;
				end = j;
			}
		}
	}
	return 0;
}