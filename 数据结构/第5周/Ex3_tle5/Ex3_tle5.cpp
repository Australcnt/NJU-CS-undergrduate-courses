//����ջ���ڱ��ⷨ
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
	int test_number;//������������
	scanf("%d", &test_number);
	long long largest_rectangle[100];
	for (int i = 0; i < test_number; i++)
	{
		int rectangle_number;//�ò��������ľ�������
		scanf("%d", &rectangle_number);
		//�������ұ���
		rectangle[0] = -2;//�����ڱ�
		rectangle[rectangle_number + 1] = -1;//�����ڱ�
		int pre = 0, cur = 1, pop_number = 0;
		long long largest_area = 0;
		for (int j = 0; j < rectangle_number; j++, pre++, cur++)
		{
			scanf("%d", &rectangle[cur]);
			height[cur + pop_number] = rectangle[cur];
			int k = 0;
			for (k = pre; rectangle[k] >= rectangle[cur]; k--)
			{
				right_margin[k] = cur + pop_number;//ȷ���ұ߽磨����cur�����ӵ��ұ߽�����Ϊcur��
				pre--; cur--; pop_number++;//�������ڸþ��εľ��ε�������ջ
				for (int m = k; rectangle[m] != -1; m++)
					rectangle[m] = rectangle[m + 1];
			}
			left_margin[cur + pop_number] = k;//ȷ����߽�
		}
		for (int k = pre + pop_number, n = pre; rectangle[n] >= rectangle[cur]; k--, n--)
		{
			right_margin[k] = cur + pop_number;//ȷ���ұ߽磨����cur�����ӵ��ұ߽�����Ϊcur��
			pre--; cur--; pop_number++;//�������ڸþ��εľ��ε�������ջ
			for (int m = n; rectangle[m] != -1; m++)
				rectangle[m] = rectangle[m + 1];
		}
		for (int l = 1; l <= rectangle_number; l++)//ͨ�����ұ߽�͸߶ȣ������ÿ�����Ӷ�Ӧ�������������ѡȡ��Щ��������е����ֵ
		{
			long long area = (long long)height[l] * ((long long)right_margin[l] - (long long)left_margin[l] - 1);
			if (area > largest_area)
				largest_area = area;
		}
		largest_rectangle[i] = largest_area;
	}
	for (int i = 0; i < test_number; i++)//������ÿ���������������������
		printf("%I64d\n", largest_rectangle[i]);
	return 0;
}