#include <iostream>
using namespace std;
#define N 5
void InverseBubbleSort(int x[],int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i;j++)
			if (x[j]<x[j+1])
			{
				int temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
}
int main()
{
	int x[N];
	for (int i = 0; i < N; i++)
		cin >> x[i];
	InverseBubbleSort(x, N);
	for (int i = 0; i < N; i++)
		cout << x[i] << " ";
	return 0;
}