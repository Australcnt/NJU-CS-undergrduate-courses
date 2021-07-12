#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[20] = "%%\t\n\x1a\092i\234s";
	cout << 20 << endl;
	cout << strlen(str) << endl;
	return 0;
}