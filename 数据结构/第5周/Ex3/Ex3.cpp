//����ջ���ڱ��ⷨ
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
	int height;
	int location;//��ʵ�±�
};

void push(int height, int location);//����ջѹջ
void pop();//����ջ��ջ
void empty(int rectangle_number);//��յ���ջ

Node rectangle[100002];//����ջ
int top;//����ջջ���±�
int height[100002];//���Ӹ߶�
int left_margin[100002];//��߽�
int right_margin[100002];//�ұ߽�

int main()
{
	int test_number;//������������
	scanf("%d", &test_number);
	long long largest_rectangle[100];
	for (int i = 0; i < test_number; i++)
	{
		int rectangle_number;//�ò��������ľ�������
		scanf("%d", &rectangle_number);
		//�������ұ���
		rectangle[0].height = -2;//�����ڱ�
		rectangle[0].location = 0;
		height[0] = -2;
		rectangle[1].height = -1;//�����ڱ�
		rectangle[1].location = rectangle_number + 1;
		height[rectangle_number + 1] = -1;
		top = 0;//����ջջ���±��ʼΪ0
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
		empty(rectangle_number);//��յ���ջ
		//�����������
		rectangle[0].height = -2;//�����ڱ�
		rectangle[0].location = rectangle_number + 1;
		height[rectangle_number + 1] = -2;
		rectangle[1].height = -1;//�����ڱ�
		rectangle[1].location = 0;
		height[0] = -1;
		top = 0;//����ջջ���±��ʼΪ0
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
		for (int l = 1; l <= rectangle_number; l++)//ͨ�����ұ߽�͸߶ȣ������ÿ�����Ӷ�Ӧ�������������ѡȡ��Щ��������е����ֵ
		{
			long long area = (long long)height[l] * ((long long)right_margin[l] - (long long)left_margin[l] - 1);
			if (area > largest_area)
				largest_area = area;
		}
		largest_rectangle[i] = largest_area;
		empty(rectangle_number);//��յ���ջ
	}
	for (int i = 0; i < test_number; i++)//������ÿ���������������������
		printf("%lld\n", largest_rectangle[i]);
	return 0;
}

void push(int height, int location)//����ջѹջ
{
	rectangle[top + 2].height = rectangle[top + 1].height;//�����ڱ�
	rectangle[top + 2].location = rectangle[top + 1].location;
	rectangle[top + 1].height = height;
	rectangle[top + 1].location = location;
	top++;
}

void pop()//����ջ��ջ
{
	
	rectangle[top].height = rectangle[top + 1].height;//�����ڱ�
	rectangle[top].location = rectangle[top + 1].location;
	rectangle[top + 1].height = 0;
	rectangle[top + 1].location = 0;
	top--;
}

void empty(int rectangle_number)//��յ���ջ
{
	for (int i = 0; i <= rectangle_number + 1; i++)
	{
		rectangle[i].height = 0;
		rectangle[i].location = 0;
	}
}