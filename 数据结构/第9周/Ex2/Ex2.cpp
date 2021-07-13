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
	get_next(search_str, search_length, next);//����next��������
	if (fast_find(str, search_str, 0, next) == -1)//��str���ҵ�search_str�Ŀ�ʼλ�ã�û�ҵ������-1
		cout << "-1" << endl;
	else
		cout << endl;
	return 0;
}

void get_next(char str[], int length, int next[])//����next��������
{
	int j = 0;
	int k = -1;
	next[0] = -1;
	while (j < length)//����next[j]
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

//��k��ʼѰ��search_str��str����ƥ���λ�á����ҵ�����������search_str��str���п�ʼλ�ã�����������-1
int fast_find(char str[], char search_str[], int k, int next[])
{
	int length = strlen(str);
	int search_length = strlen(search_str);
	int position_str = k;//ɨ��ָ��
	int position_search_str = 0;//ɨ��ָ��
	while (position_str < length && position_search_str < search_length)
	{
		if (position_search_str == -1 || str[position_str] == search_str[position_search_str])//�ַ��Ƿ�ƥ��
		{
			position_str++;
			position_search_str++;
		}
		else
			position_search_str = next[position_search_str];//������search_str�ıȽ�λ��
	}
	if (position_search_str < search_length)//ƥ��ʧ��
		return -1;
	else//ƥ��ɹ�
	{
		cout << position_str - search_length << ' ';
		fast_find(str, search_str, position_str - search_length + 1, next);
		return 0;
	}
}