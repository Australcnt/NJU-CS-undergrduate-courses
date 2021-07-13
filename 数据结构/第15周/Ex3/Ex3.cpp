//八皇后问题
#include <iostream>

using namespace std;

int n, m;//人数和积水数
int num = 0;//站位方法数目
int column[13] = { 0 };//列记录
int diagonal_left[25] = { 0 };//左斜线记录
int diagonal_right[25] = { 0 };//右斜线记录
int puddle[13][13] = { 0 };//积水记录

void traceback(int row);//回溯法
bool check(int x, int y);//该位置是否可以站人

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

void traceback(int row)//回溯法
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

bool check(int x, int y)//该位置是否可以站人
{
	if (column[x] || diagonal_left[x - y + n] || diagonal_right[x + y - 1] || puddle[y][x])
		return false;
	else
		return true;
}