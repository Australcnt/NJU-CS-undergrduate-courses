#include <iostream>
#include <string>
using namespace std;
int main()
{
	char swi[2];
	cin.getline(swi, 2);
	char str[100];
	cin.getline(str, 100);
	int n;
	if (swi[0] == '1')
	{
		for (int j = 0; str[j] != '\0'; j++)
		{
			n = 1;
			for (int i = j; str[i] != '\0'; i++)
			{
				if (str[i] == str[i + 1])
					n++;
				else if (n == 1)
				{
					cout << str[j];
					break;
				}
				else
				{
					cout << str[j] << n;
					j = j + n - 1;
					break;
				}
			}
		}
	}
	if (swi[0] == '2')
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
				continue;
			cout << str[i];
			n = 0;
			for (int j = 0; str[i + 1 + j] >= '0'&&str[i + 1 + j] <= '9'; j++)
			{
				n = n * 10;
				for (; str[i + 1 + j] != '0'; n++)
					str[i + 1 + j] = str[i + 1 + j] - '2' + '1';
			}
			if (n != 0)
			{
				for (; n > 1; n--)
					cout << str[i];
			}
		}
	}
	return 0;
}