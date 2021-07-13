#include <iostream>
#include <string.h>

using namespace std;

void get_next(char str[], int length, int next[]);
int fast_find(char str[], char search_str[], int k, int next[]);

int main()
{
	char str[10000];
	char search_str[1000];
	cin >> str;
	cin >> search_str;
	int length = strlen(str);
	int search_length = strlen(search_str);
	int next[10000];
	get_next(search_str, search_length, next);//计算next特征向量
	if (fast_find(str, search_str, 0, next) == -1)//在str中找到search_str的开始位置，没找到则输出-1
		cout << "-1" << endl;
	else
		cout << endl;
	return 0;
}

void get_next(char str[], int length, int next[])//计算next特征向量
{
	int j = 0;
	int k = -1;
	next[0] = -1;
	while (j < length)//计算next[j]
	{
		if (k == -1 || str[j] == str[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}

//从k开始寻找search_str在str串中匹配的位置。若找到，函数返回search_str在str串中开始位置，否则函数返回-1
int fast_find(char str[], char search_str[], int k, int next[])
{
	int length = strlen(str);
	int search_length = strlen(search_str);
	int position_str = k;//扫描指针
	int position_search_str = 0;//扫描指针
	while (position_str < length && position_search_str < search_length)
	{
		if (position_search_str == -1 || str[position_str] == search_str[position_search_str])//字符是否匹配
		{
			position_str++;
			position_search_str++;
		}
		else
			position_search_str = next[position_search_str];//求下趟search_str的比较位置
	}
	if (position_search_str < search_length)//匹配失败
		return -1;
	else//匹配成功
	{
		cout << position_str - search_length << ' ';
		fast_find(str, search_str, position_str - search_length + 1, next);
		return 0;
	}
}