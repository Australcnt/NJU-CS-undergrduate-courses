#include <iostream>
using namespace std;
#define N 3
int main()
{
	int x[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> x[i][j];
	for (int i = 0; i < N; i++)
		for (int j = i+1; j < N; j++)
		{
			int temp = x[i][j];
			x[i][j] = x[j][i];
			x[j][i] = temp;
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cout << x[i][j] << " ";
	return 0;
}