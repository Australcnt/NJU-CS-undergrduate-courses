//����ջ���ڱ��ⷨ
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
	int height;
	//int height2;
	int height3;//����ԭʼ������߶�
	int left_margin;
	int right_margin;
};

Node rectangle[100002];

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
		rectangle[rectangle_number + 1].height = -1;//�����ڱ�
		int pre = 0, cur = 1;
		long long largest_area = 0;
		for (int j = 0; j < rectangle_number; j++, pre++, cur++)
		{
			scanf("%d", &rectangle[cur].height);
			//rectangle[cur].height2 = rectangle[cur].height;
			rectangle[cur].height3 = rectangle[cur].height;
			if (rectangle[pre].height < rectangle[cur].height)//rectangle[pre].height < rectangle[cur].heightʱ��pre��cur����߽�
			{
				rectangle[cur].left_margin = pre;//ȷ����߽�
				continue;
			}
			else//rectangle[pre].height >= rectangle[cur].heightʱ���������������cur�����ӣ���󽫵�һ������cur����������Ϊcur����߽�
			{
				int k = 0;
				for (k = pre; rectangle[k].height == -3 || rectangle[k].height >= rectangle[cur].height; k--)
				{
					if(rectangle[k].height >= rectangle[cur].height)
					rectangle[k].right_margin = cur;//ȷ���ұ߽磨����cur�����ӵ��ұ߽�����Ϊcur��
					rectangle[k].height = -3;//�������ڸþ��εľ��θ߶���Ϊ-3������������ջ
				}
				rectangle[cur].left_margin = k;//ȷ����߽�
			}
		}
		for (int k = pre; rectangle[k].height == -3 || rectangle[k].height >= rectangle[cur].height; k--)
		{
			if (rectangle[k].height >= rectangle[cur].height)
				rectangle[k].right_margin = cur;//ȷ���ұ߽磨����cur�����ӵ��ұ߽�����Ϊcur��
			rectangle[k].height = -3;//�������ڸþ��εľ��θ߶���Ϊ-3������������ջ
		}
		/*
		//�����������
		rectangle[0].height2 = -1;//�����ڱ�
		rectangle[rectangle_number + 1].height2 = -2;//�����ڱ�
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
					rectangle[n].height2 = -3;//�������ڸþ��εľ��θ߶���Ϊ-3������������ջ
				rectangle[cur].right_margin = n;
			}

		}*/
		for (int l = 1; l <= rectangle_number; l++)//ͨ�����ұ߽�͸߶ȣ������ÿ�����Ӷ�Ӧ�������������ѡȡ��Щ��������е����ֵ
		{
			long long area = (long long)rectangle[l].height3 * ((long long)rectangle[l].right_margin - (long long)rectangle[l].left_margin - 1);
			if (area > largest_area)
				largest_area = area;
		}
		largest_rectangle[i] = largest_area;
	}
	for (int i = 0; i < test_number; i++)//������ÿ���������������������
		printf("%I64d\n", largest_rectangle[i]);
	return 0;
}