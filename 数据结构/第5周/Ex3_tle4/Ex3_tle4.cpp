//单调栈加哨兵解法
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
	int height;
	//int height2;
	int height3;//保存原始的输入高度
	int left_margin;
	int right_margin;
};

Node rectangle[100002];

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
		rectangle[0].height = -2;//设置哨兵
		rectangle[rectangle_number + 1].height = -1;//设置哨兵
		int pre = 0, cur = 1;
		long long largest_area = 0;
		for (int j = 0; j < rectangle_number; j++, pre++, cur++)
		{
			scanf("%d", &rectangle[cur].height);
			//rectangle[cur].height2 = rectangle[cur].height;
			rectangle[cur].height3 = rectangle[cur].height;
			if (rectangle[pre].height < rectangle[cur].height)//rectangle[pre].height < rectangle[cur].height时，pre是cur的左边界
			{
				rectangle[cur].left_margin = pre;//确定左边界
				continue;
			}
			else//rectangle[pre].height >= rectangle[cur].height时，逐个弹出不低于cur的柱子，最后将第一个低于cur的柱子设置为cur的左边界
			{
				int k = 0;
				for (k = pre; rectangle[k].height == -3 || rectangle[k].height >= rectangle[cur].height; k--)
				{
					if(rectangle[k].height >= rectangle[cur].height)
					rectangle[k].right_margin = cur;//确定右边界（高于cur的柱子的右边界设置为cur）
					rectangle[k].height = -3;//将不矮于该矩形的矩形高度置为-3，即弹出单调栈
				}
				rectangle[cur].left_margin = k;//确定左边界
			}
		}
		for (int k = pre; rectangle[k].height == -3 || rectangle[k].height >= rectangle[cur].height; k--)
		{
			if (rectangle[k].height >= rectangle[cur].height)
				rectangle[k].right_margin = cur;//确定右边界（高于cur的柱子的右边界设置为cur）
			rectangle[k].height = -3;//将不矮于该矩形的矩形高度置为-3，即弹出单调栈
		}
		/*
		//从右向左遍历
		rectangle[0].height2 = -1;//设置哨兵
		rectangle[rectangle_number + 1].height2 = -2;//设置哨兵
		pre = rectangle_number + 1;
		cur = rectangle_number;
		for (int m = rectangle_number + 1; m > 1; m--, pre--, cur--)
		{
			if (rectangle[pre].height2 < rectangle[cur].height2)
				rectangle[cur].right_margin = pre;
			else
			{
				int n = 0;
				for (n = pre; rectangle[n].height2 >= rectangle[cur].height2 || rectangle[n].height2 == -3; n++)
					rectangle[n].height2 = -3;//将不矮于该矩形的矩形高度置为-3，即弹出单调栈
				rectangle[cur].right_margin = n;
			}

		}*/
		for (int l = 1; l <= rectangle_number; l++)//通过左右边界和高度，计算出每个柱子对应的最大矩形面积，选取这些矩形面积中的最大值
		{
			long long area = (long long)rectangle[l].height3 * ((long long)rectangle[l].right_margin - (long long)rectangle[l].left_margin - 1);
			if (area > largest_area)
				largest_area = area;
		}
		largest_rectangle[i] = largest_area;
	}
	for (int i = 0; i < test_number; i++)//逐个输出每个测试样例的最大矩形面积
		printf("%I64d\n", largest_rectangle[i]);
	return 0;
}