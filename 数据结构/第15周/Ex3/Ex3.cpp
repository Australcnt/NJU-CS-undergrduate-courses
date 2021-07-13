//�˻ʺ�����
#include <iostream>

using namespace std;

int n, m;//�����ͻ�ˮ��
int num = 0;//վλ������Ŀ
int column[13] = { 0 };//�м�¼
int diagonal_left[25] = { 0 };//��б�߼�¼
int diagonal_right[25] = { 0 };//��б�߼�¼
int puddle[13][13] = { 0 };//��ˮ��¼

void traceback(int row);//���ݷ�
bool check(int x, int y);//��λ���Ƿ����վ��

int main()
{
	cin >> n >> m;
	int x = 0, y = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		puddle[y][x] = 1;
	}
	traceback(1);
	cout << num << endl;
	return 0;
}

void traceback(int row)//���ݷ�
{
	if (row == n + 1)
		num++;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!check(i, row))
				continue;
			column[i] = 1;
			diagonal_left[i - row + n] = 1;
			diagonal_right[i + row - 1] = 1;
			traceback(row + 1);
			column[i] = 0;
			diagonal_left[i - row + n] = 0;
			diagonal_right[i + row - 1] = 0;
		}
	}
}

bool check(int x, int y)//��λ���Ƿ����վ��
{
	if (column[x] || diagonal_left[x - y + n] || diagonal_right[x + y - 1] || puddle[y][x])
		return false;
	else
		return true;
}