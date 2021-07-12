#include <iostream>
using namespace std;
int H(int n, int x)
{
	if (n == 0)
		return 1;
	else if (n == 1)
	    return 2 * x;
	else
		return 2 * x * H(n - 1,x) - 2 * (n - 1) * H(n - 2,x);

}
int main()
{
	int n, x,Hn ;
	cin >> n >> x;
	Hn = H(n, x);
	cout << Hn << endl;
	return 0;

}