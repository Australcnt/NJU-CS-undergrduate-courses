#include <iostream>
using namespace std;
int Peach(int n)
{
	if (n == 1)
		return 2;
	else
		return 2 * (Peach(n - 1) + 1);
}
int main()
{
	int n=10, sum;
	sum = Peach(n);
	cout << sum << endl;
	return 0;
}