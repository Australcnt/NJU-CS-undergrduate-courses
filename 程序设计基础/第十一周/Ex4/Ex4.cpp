#include <iostream>
using namespace std;
void su(int x[],int n)
{
	for (int i = 0; i < n; i++)
		x[i] = i;
	x[1] = 0;
	for(int j = 2;j<n;j++)
	if (x[j]!=0)
		for (int k = 2; k*j < n; k++)
			x[k*j] = 0;
}
int main()
{
	int x[10001];
	su(x, 10001);
	for (int i = 0; i < 10001; i++)
		if (x[i] != 0)
			cout << x[i] << " ";
	return 0;
}