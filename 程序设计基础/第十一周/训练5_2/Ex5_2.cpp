#include <iostream>
using namespace std;
#define N 5
void InverseSelSort(int x[],int n)
{
	for (int i = n; i > 1; i--)
	{
		int min = 0;
		for (int j = 1; j < i; j++)
			if (x[j] < x[min])
				min = j;
		int temp = x[min];
		x[min] = x[i-1];
		x[i-1] = temp;
	}
}
int main()
{
	int x[N];
	for (int i = 0; i < N; i++)
		cin >> x[i];
	InverseSelSort(x, N);
	for (int j = 0; j < N; j++)
		cout << x[j] << " ";
	return 0;
}