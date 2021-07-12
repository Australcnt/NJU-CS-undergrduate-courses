#include <iostream>
using namespace std;
int DeleteDup(int x[],int n)
{
	int j = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (x[i] == x[i + 1])
		{
			for (int k = i; k < n-1; k++)
				x[k] = x[k + 1];
			j++;
			n--;
			i--;
		}
	}
	return j;
}
int main()
{
	int x[100], n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n-DeleteDup(x,n); i++)
		cout << x[i] << " ";
	return 0;
}