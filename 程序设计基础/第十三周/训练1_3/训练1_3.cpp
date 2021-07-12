#include <iostream>
using namespace std;
int main()
{
	char str[10];
	cin.getline(str, 10);
	cout << (int)str[7];
	return 0;
}