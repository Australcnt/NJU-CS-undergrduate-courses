#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main()
{
	int number;
	cin >> number;
	vector<string>str_array;
	vector<string>str_array_copy;
	for (int i = 0; i < number; i++)
	{
		string temp;
		cin >> temp;
		str_array_copy.push_back(temp);
		sort(temp.begin(),temp.end()); // 内部排序
		str_array.push_back(temp);
	}
	map<string,string> anagram_pair;
	for (int i = 0; i < number; i++) // 保存原词和变位词的对应关系
	{
		map<string,string>::iterator iter = anagram_pair.find(str_array[i]);
		if (iter == anagram_pair.end() || iter->second > str_array_copy[i])
		{
			anagram_pair.erase(str_array[i]);
			anagram_pair.insert(pair<string,string>(str_array[i], str_array_copy[i]));
		}
	}
	for (int i = 0; i < number; i++) //外部排序
	{
		int min = i;
		str_array[min] = str_array[i];
		for (int j = i; j < number; j++)
		{
			if (str_array[j] < str_array[min])
				min = j;
		}
		string temp;
		temp = str_array[i];
		str_array[i] = str_array[min];
		str_array[min] = temp;
	}
	int anagram_number = 0;
	vector<string>anagram_array;
	for (int left = 0, right = left + 1; right < number; ) // 查找变位词
	{
		if(str_array[left] != str_array[right])
		{
			left = right;
			right++;
		}
		else
		{
			if (right == number - 1 || str_array[left] != str_array[right + 1])
			{
				anagram_array.push_back(str_array[left]);
				anagram_number++;
			}
			right++;
		}
	}
	for (int i = 0; i < anagram_number; i++) // 对所有变位词进行排序，以便输出
		anagram_array[i] = anagram_pair.find(anagram_array[i])->second;
	sort(anagram_array.begin(), anagram_array.end());
	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	cout << anagram_number << endl;
	for (int i = 0; i < anagram_number; i++)
		cout << anagram_array[i] << endl;
	return 0;
}