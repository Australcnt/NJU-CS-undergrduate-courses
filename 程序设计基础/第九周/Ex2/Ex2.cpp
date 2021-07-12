#include <iostream>
using namespace std;
int B(int a)
{
	int sum = 0;
	for (int i = 1; i <= a-1; i++)
	{
		if (a%i == 0)
			sum = sum + i;
	}
	return sum;
}
int main()
{
	int n;
	cin >> n;
	for (int a = 1; a <= n;a++)
	{
		if (a == B(a))
			cout << a << " ";
	}
	return 0;
}