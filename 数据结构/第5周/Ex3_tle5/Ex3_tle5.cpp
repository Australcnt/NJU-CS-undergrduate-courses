//单调栈加哨兵解法
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

int rectangle[100002];
int height[100002];
int left_margin[100002];
int right_margin[100002];

int main()
{
	int test_number;//测试样例数量
	scanf("%d", &test_number);
	long long largest_rectangle[100];
	for (int i = 0; i < test_number; i++)
	{
		int rectangle_number;//该测试样例的矩形数量
		scanf("%d", &rectangle_number);
		//从左向右遍历
		rectangle[0] = -2;//设置哨兵
		rectangle[rectangle_number + 1] = -1;//设置哨兵
		int pre = 0, cur = 1, pop_number = 0;
		long long largest_area = 0;
		for (int j = 0; j < rectangle_number; j++, pre++, cur++)
		{
			scanf("%d", &rectangle[cur]);
			height[cur + pop_number] = rectangle[cur];
			int k = 0;
			for (k = pre; rectangle[k] >= rectangle[cur]; k--)
			{
				right_margin[k] = cur + pop_number;//确定右边界（高于cur的柱子的右边界设置为cur）
				pre--; cur--; pop_number++;//将不矮于该矩形的矩形弹出单调栈
				for (int m = k; rectangle[m] != -1; m++)
					rectangle[m] = rectangle[m + 1];
			}
			left_margin[cur + pop_number] = k;//确定左边界
		}
		for (int k = pre + pop_number, n = pre; rectangle[n] >= rectangle[cur]; k--, n--)
		{
			right_margin[k] = cur + pop_number;//确定右边界（高于cur的柱子的右边界设置为cur）
			pre--; cur--; pop_number++;//将不矮于该矩形的矩形弹出单调栈
			for (int m = n; rectangle[m] != -1; m++)
				rectangle[m] = rectangle[m + 1];
		}
		for (int l = 1; l <= rectangle_number; l++)//通过左右边界和高度，计算出每个柱子对应的最大矩形面积，选取这些矩形面积中的最大值
		{
			long long area = (long long)height[l] * ((long long)right_margin[l] - (long long)left_margin[l] - 1);
			if (area > largest_area)
				largest_area = area;
		}
		largest_rectangle[i] = largest_area;
	}
	for (int i = 0; i < test_number; i++)//逐个输出每个测试样例的最大矩形面积
		printf("%I64d\n", largest_rectangle[i]);
	return 0;
}