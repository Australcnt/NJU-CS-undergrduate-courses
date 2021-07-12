#include <iostream>
using namespace std;
void A(int x[],int n)
{
	int i = 0;
	while (n!=0)
	{
		x[i] = n % 10;
		n /= 10;
		i++;
	}
}
int main()
{
	int x[100], n, m = 0;
	cin >> n;
	A(x, n);
	while (n!=0)
	{
		n /= 10;
		m++;
	}
	for (int i = m - 1; i >= 0; i--)
			cout << x[i] << " ";
	return 0;
}