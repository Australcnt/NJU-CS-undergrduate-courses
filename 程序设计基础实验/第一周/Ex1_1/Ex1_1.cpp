#include <iostream>
using namespace std;
void Search(char str[]);
int main()
{
	char str[10000];
	cin.getline(str, 10000);
	Search(str);
	return 0;
}
void Search(char str[])
{
	char ch = str[0];
	int n = 0;
	for(int i=0;str[i]!='\0';i++)
	{
		int m = 0;
		for (int j = 0; str[j] != '\0'; j++)
		{
			if (str[i] == str[j])
				m++;
		}
		if(m>n||(m==n&&str[i]>ch))
		{
			n = m;
			ch = str[i];
		}
	}
	cout << ch << ' ' << n << endl;
}