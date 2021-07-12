#include <iostream>
using namespace std;
void Unlock(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (str[i] >= 'a'&&str[i] <= 'z')
			{
				if (str[i] >= 'a'&&str[i] <= 'e')
					str[i] = str[i] + ('b' - 'a') * 21;
				str[i] = str[i] - 'f' + 'a';
			}
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				if (str[i] >= 'A'&&str[i] <= 'E')
					str[i] = str[i] + ('B' - 'A') * 26;
				str[i] = str[i] - 'F' + 'A';
			}
		}
	}
}
int main()
{
	char str[1000];
	cin.getline(str, 1000);
	Unlock(str);
	cout << str << endl;
	return 0;
}