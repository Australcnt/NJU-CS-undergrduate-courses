#include <iostream>

using namespace std;

int mahjong[900000];//�齫��������
int location[900000];//�齫λ������
int exchange_times = 0;//��������

int main()
{
	int n = 0;//�齫��Ŀ
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> mahjong[i];//�洢�齫����
		location[mahjong[i]] = i;//�洢�齫λ��
	}
	for (int i = 0; i < n; i += 2)
	{
		if (mahjong[i] / 2 == mahjong[i + 1] / 2)//�������齫Ϊһ���ƣ������轻������
			continue;
		if (mahjong[i] % 2 == 0)//���齫Ϊż��
		{
			int temp = 0, temp_loc = 0;
			temp = mahjong[i + 1];//�����齫����һ������һ���齫����
			mahjong[i + 1] = mahjong[location[mahjong[i] + 1]];
			mahjong[location[mahjong[i] + 1]] = temp;
			temp_loc = location[mahjong[location[mahjong[i] + 1]]];//�����齫����һ���λ������һ���齫��λ�ý���
			location[mahjong[location[mahjong[i] + 1]]] = location[mahjong[i + 1]];
			location[mahjong[i + 1]] = temp_loc;
			exchange_times++;
		}
		else//���齫Ϊ����
		{
			int temp = 0, temp_loc = 0;
			temp = mahjong[i + 1];//�����齫����һ������һ���齫����
			mahjong[i + 1] = mahjong[location[mahjong[i] - 1]];
			mahjong[location[mahjong[i] - 1]] = temp;
			temp_loc = location[mahjong[location[mahjong[i] - 1]]];//�����齫����һ���λ������һ���齫��λ�ý���
			location[mahjong[location[mahjong[i] - 1]]] = location[mahjong[i + 1]];
			location[mahjong[i + 1]] = temp_loc;
			exchange_times++;
		}
	}
	cout << exchange_times << endl;//�����������
	return 0;
}