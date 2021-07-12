#include <iostream>
using namespace std;
int main()
{
	char str[100];
	cin.getline(str, 100);
	for (int i = 0; str[i] != '#';i++)
	{ 
		if (str[i] == 'q')
		{
			cout << i + 1 << endl;
			break;
		}
		else if (str[i + 1] == '#')
		{
			cout << -1 << endl;
			break;
		}
	}
	return 0;
}