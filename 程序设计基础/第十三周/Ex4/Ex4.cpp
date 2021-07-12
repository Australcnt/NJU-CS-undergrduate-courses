#include <iostream>//错误代码，未考虑10个以上数字的情况
#include <string>
#include <string.h>
using namespace std;
int main()
{
	char swi[2];
	cin.getline(swi, 2);
	char str[100];
		cin.getline(str, 100);
		int m = strlen(str);
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
					break;
				else
				{
					str[j + 1] = '0';
					for (int l = 1; l <= n; l++)
						str[j + 1] = str[j + 1] + '2' - '1';
					for (int k = 0; k <= m - j - n; k++)
						str[j + 2 + k] = str[j + n + k];
					m = m + 2 - n;
					j++;
					break;
				}
			}
		}
	}
	if (swi[0] == '2')
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i + 1] >= '0'&&str[i + 1] <= '9')
			{
				for (n = 0; str[i + 1] != '0'; n++)
					str[i + 1] = str[i + 1] - '2' + '1';
				for (int j = m; j >= i + 2; j--)
					str[j + n - 2] = str[j];
				for (int k = 1; k < n; k++)
					str[i + k] = str[i];
				m = m + n - 2;
				i++;
			}
		}
	}
	cout << str << endl;
	return 0;
}