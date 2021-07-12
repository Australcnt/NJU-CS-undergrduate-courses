#include <iostream>
#include <string>
using namespace std;
int Squeeze(char s1[], const char s2[])
{
	int n = 0;
	for (int j = 0; s2[j] != '\0'; j++)
		for (int i = 0; s1[i] != '\0'; i++)
			if (s1[i] == s2[j])
			{
				n++;
				for (int a = i; s1[a] != '\0'; a++)
					s1[a] = s1[a + 1];
					i--;
			}
	return n;
}
int main()
{
	int n;
	char s1[99], s2[99];
	cin.getline(s1, 99);
	cin.getline(s2, 99);
	n = Squeeze(s1, s2);
	cout << s1 << endl;
	cout << n << endl;
	return 0;
}