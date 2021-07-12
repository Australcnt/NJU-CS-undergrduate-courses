#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n = 0;
	char str[100];
	cin.getline(str, 100);
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '-'&&str[i + 1] == '>')
			n++;
	cout << n << endl;
	return 0;
}