#include <iostream>
using namespace std;
int main()
{
	char str[100];
	cin.getline(str, 100);
	int m = 0, n = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
			m++;
		if (str[i] == ')')
			n++;
		if (m < n)
		{
			cout << "不配对" << endl;
			return 0;
		}
	}
	if (m == n)
		cout << "配对" << endl;
	else
		cout << "不配对" << endl;
	return 0;
}