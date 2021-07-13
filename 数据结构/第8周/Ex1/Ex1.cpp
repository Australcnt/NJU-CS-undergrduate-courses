#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int count = 1;
	if (s.size() == 0)
		cout << "";
	for (int cur = 0, next = 1; cur < s.size(); cur++, next++)
	{
		if (next == s.size() - 1)
		{
			if (s[cur] == s[next])
			{
				count++;
				cout << count << s[cur];
			}
			else if (count != 1)
			{
				cout << count << s[cur] << s[next] << endl;
			}
			else
			{
				cout << s[cur] << s[next] << endl;
			}
			break;
		}
		if (s[cur] == s[next])
		{
			count++;
			continue;
		}
		else
		{
			if (count != 1)
			{
				cout << count << s[cur];
				count = 1;
			}
			else
				cout << s[cur];
		}
	}
	return 0;
}