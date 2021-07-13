#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, new_s = "";
	cin >> s;
	int times[26] = { 0 };
	int flag[26] = { 0 };
	for (int i = 0, index = 0; i < s.size(); i++)
	{
		index = s[i] - 'a';
		times[index]++;
	}
	for (int j = 0; j < s.size(); j++)
	{
		if (flag[s[j] - 'a'])
		{
			times[s[j] - 'a']--;
			continue;
		}
		while (new_s.size() > 0 && s[j] < new_s.back() && times[new_s.back() - 'a'])
		{
			flag[new_s.back() - 'a'] = 0;
			new_s.pop_back();
		}
		flag[s[j] - 'a'] = 1;
		times[s[j] - 'a']--;
		new_s += s[j];
	}
	cout << new_s << endl;
	return 0;
}