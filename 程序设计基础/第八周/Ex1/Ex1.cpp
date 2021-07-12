#include <iostream>
using namespace std;
int Hannoi(int n)
{
	int sum = 0;
	if (n == 1)
		sum = 1;
	else
		sum = 2 * Hannoi(n - 1) + 1;
	return sum;

}
int main()
{
	int n, sum = 0;
	cin >> n;
	sum = Hannoi(n);
	cout << sum << endl;
	return 0;
}