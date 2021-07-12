#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin >> n;
	m = 1 - n;
	if (m > 0)
		cout << "|1-" << n << "|>" << n << "-1";
	else if (m==0)
		cout << "|1-" << n << "|==" << n << "-1";
	else
		cout << "|1-" << n << "|<" << n << "-1";
	return 0;
}