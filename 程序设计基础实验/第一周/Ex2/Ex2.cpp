#include <iostream>
using namespace std;
void to_lower(char *s);
bool str_equal(char *s1, char *s2);
int strlength(char str[]);
void transform(char *s, char *s2);
int main()
{
	char s[1000], s2[1000];
	cin.getline(s2, 1000);
	cin.getline(s, 1000);
	transform(s, s2);
	cout << s << endl;
}
void to_lower(char *s)
{
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			 s[i] = s[i] + 'a' - 'A';
}
bool str_equal(char *s1, char *s2)
{
	for (int i = 0, j = 0; (s1[0] != '\0' && s2[0] != '\0') || (s1[i - 1] != '\0' && s2[j - 1] != '\0'); i++, j++)
	{
		for (; s1[i] == '-'; i++);
		for (; s2[j] == '-'; j++);
		if (s1[i] != s2[j])
			break;
		if ((s1[i] == '\0' && (s2[j] == '\0' || s2[j] == '-')) || ((s1[i] == '\0' || s1[i] == '-')&& s2[j] == '\0' ))
			return true;
	}
	return false;
}
int strlength(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{ 
		if (str[i + 1] == '\0')
			return i + 1;
	}
	
}
void transform(char *s, char *s2)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		char s1[1000];
		for (int j = 0; (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '\''; j++)
		{
			s1[j] = s[i];
			i++;
			if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '\''))
				s1[j + 1] = '\0';
		}
		to_lower(s1);
		to_lower(s2);
		if(str_equal(s1,s2))
		{
			int l = strlength(s1);
			if(l>=4)
				for (int m = i; s[m - 1] != '\0'; m++)
					s[m - l + 4] = s[m];
			if (l < 4)
			{
				int n;
				for (n = i; s[n] != '\0'; n++)
					;
				for (; n >= i; n--)
					s[n - l + 4] = s[n];
			}
			i = i - l + 4;
			for (int k = 0; k < 4; k++)
			{
				if (k % 2 == 0)
					s[i - 4 + k] = '2';
				else
					s[i - 4 + k] = '0';
			}
		}
	}
}