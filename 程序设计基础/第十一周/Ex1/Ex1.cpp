#include <iostream>
using namespace std;
int kmax(int x[], int n, int k)
{
	int j;
	for (int a = 1; a <= k; a++)
	{
		j = 0;
		for (int i = 1; i < n; i++)
		{
			if (x[i] > x[j])
				j = i;
		}
		if (a == k)
			return j;
		x[j] = x[n - 1];
		n--;
	}
}
int main()
{
	int n, k, nk;
	cin >> n >> k;
	int A[100];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	nk = kmax(A, n, k);
	cout << A[nk] << endl;
	return 0;
}