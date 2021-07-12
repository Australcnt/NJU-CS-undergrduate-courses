#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int FindReplaceStr(char str[], const char find_str[], const char replace_str[])
{
	int a, b, c;
	int n = 0;
	a = strlen(find_str);
	b = strlen(replace_str);
	c = strlen(str);
	for (int i = 0; str[i] != '\0'; i++)
		for (int j = 0; j < a; j++)
		{
			if (str[i + j] == find_str[j])
			{
				if (j == a - 1)
				{
					if (a >= b)
					{
						for (int k = 0; k < b; k++)
							str[i + k] = replace_str[k];
						for (int l = b; str[i + l] != '\0'; l++)
							str[i + l] = str[i + l + a - b];
						i = i + b - 1;
					}
					if (a<b)
					{
						for (int p = c; p >= i; p--)
							str[p - a + b] = str[p];
						for (int q = 0; q < b; q++)
							str[i + q] = replace_str[q];
						c = c - a + b;
						i = i + b - 1;
					}
					n++;
				}
			}
			else
				break;
		}
	return n;
}
int main()
{
	int n;
	char str[10000], find_str[10000], replace_str[10000];
	cin.getline(str, 10000);
	cin.getline(find_str, 10000);
	cin.getline(replace_str, 10000);
	n = FindReplaceStr(str, find_str, replace_str);
	cout << str << endl;
	cout << n << endl;
	return 0;
}