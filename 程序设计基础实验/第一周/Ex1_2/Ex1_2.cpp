#include <iostream>
using namespace std;
char Search(char str[], int x, int k);
void Delete(char str[], char ch);
void Deletek(char str[], int k);
int main()
{
	char str[10000];
	cin.getline(str, 10000);
	int k;
	cin >> k;
	Deletek(str, k);
	return 0;
}
char Search(char str[], int x, int k)
{
	char ch = str[0];
	int n = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		int m = 0;
		for (int j = 0; str[j] != '\0'; j++)
		{
			if (str[i] == str[j])
				m++;
		}
		if (m > n || (m == n && str[i] > ch))
		{
			n = m;
			ch = str[i];
		}
	}
	if(x==k-1)
	cout << ch << ' ' << n << endl;
	return ch;
}
void Delete(char str[], char ch)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ch)
			for (int j = i; str[j] != '\0'; j++)
				str[j] = str[j + 1];
}
void Deletek(char str[], int k)
{
	char ch;
	for (int x = 0; x < k; x++)
	{
		if(str[x]=='\0')
		{
			cout << "输入的k不合法" << endl;
			break;
		}
		ch = Search(str, x, k);
		Delete(str, ch);
	}
}