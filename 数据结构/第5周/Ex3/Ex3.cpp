//单调栈加哨兵解法
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
	int height;
	int location;//真实下标
};

void push(int height, int location);//单调栈压栈
void pop();//单调栈出栈
void empty(int rectangle_number);//清空单调栈

Node rectangle[100002];//单调栈
int top;//单调栈栈顶下标
int height[100002];//柱子高度
int left_margin[100002];//左边界
int right_margin[100002];//右边界

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
		rectangle[0].location = 0;
		height[0] = -2;
		rectangle[1].height = -1;//设置哨兵
		rectangle[1].location = rectangle_number + 1;
		height[rectangle_number + 1] = -1;
		top = 0;//单调栈栈顶下标初始为0
		long long largest_area = 0;
		for (int j = 1; j < rectangle_number + 1; j++)
		{
			scanf("%d", &height[j]);
			while (rectangle[top].height >= height[j] && top != 0)
			{
				right_margin[rectangle[top].location] = j;
				pop();
			}
			left_margin[j] = rectangle[top].location;
			push(height[j], j);
		}
		while (rectangle[top].height >= height[rectangle_number + 1])
		{
			right_margin[rectangle[top].location] = rectangle_number + 1;
			pop();
		}
		/*
		empty(rectangle_number);//清空单调栈
		//从右向左遍历
		rectangle[0].height = -2;//设置哨兵
		rectangle[0].location = rectangle_number + 1;
		height[rectangle_number + 1] = -2;
		rectangle[1].height = -1;//设置哨兵
		rectangle[1].location = 0;
		height[0] = -1;
		top = 0;//单调栈栈顶下标初始为0
		for (int k = rectangle_number; k > 0; k--)
		{
			while (rectangle[top].height >= height[k] && top != 0)
			{
				pop();
			}
			right_margin[k] = rectangle[top].location;
			push(height[k], k);
		}
		*/
		for (int l = 1; l <= rectangle_number; l++)//通过左右边界和高度，计算出每个柱子对应的最大矩形面积，选取这些矩形面积中的最大值
		{
			long long area = (long long)height[l] * ((long long)right_margin[l] - (long long)left_margin[l] - 1);
			if (area > largest_area)
				largest_area = area;
		}
		largest_rectangle[i] = largest_area;
		empty(rectangle_number);//清空单调栈
	}
	for (int i = 0; i < test_number; i++)//逐个输出每个测试样例的最大矩形面积
		printf("%lld\n", largest_rectangle[i]);
	return 0;
}

void push(int height, int location)//单调栈压栈
{
	rectangle[top + 2].height = rectangle[top + 1].height;//更新哨兵
	rectangle[top + 2].location = rectangle[top + 1].location;
	rectangle[top + 1].height = height;
	rectangle[top + 1].location = location;
	top++;
}

void pop()//单调栈出栈
{
	
	rectangle[top].height = rectangle[top + 1].height;//更新哨兵
	rectangle[top].location = rectangle[top + 1].location;
	rectangle[top + 1].height = 0;
	rectangle[top + 1].location = 0;
	top--;
}

void empty(int rectangle_number)//清空单调栈
{
	for (int i = 0; i <= rectangle_number + 1; i++)
	{
		rectangle[i].height = 0;
		rectangle[i].location = 0;
	}
}