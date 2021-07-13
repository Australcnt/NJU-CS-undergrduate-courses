#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<string>str_array;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		str_array.push_back(str);
	}
	sort(str_array.begin(), str_array.end());
	int m = (n - 1) / 2;
	int left = m - k;
	int right = m + k;
	for (int i = left; i <= right; i++)
		cout << str_array[i] << " ";
	cout << endl;
	return 0;
}