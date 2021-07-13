//����ջ���ڱ��ⷨ
#include <iostream>

using namespace std;

struct Node
{
	int height;
	int left_margin;
	int right_margin;
};

int main()
{
	int test_number;//������������
	cin >> test_number;
	long long largest_rectangle[100];
	for (int i = 0; i < test_number; i++)
	{
		int rectangle_number;//�ò��������ľ�������
		cin >> rectangle_number;
		Node* rectangle = new Node[100002];
		int rectangle_store[100002];
		if (rectangle_number == 1)//��������Ϊ1
		{
			cin >> largest_rectangle[i];
			continue;
		}
		else if (rectangle_number == 2)//��������Ϊ2
		{
			cin >> rectangle[0].height >> rectangle[1].height;
			if (rectangle[0].height > rectangle[1].height)
				largest_rectangle[i] = (long long)rectangle[1].height * 2;
			else
				largest_rectangle[i] = (long long)rectangle[0].height * 2;
			continue;
		}
		rectangle[0].height = -2;//�����ڱ�
		rectangle[rectangle_number + 1].height = -1;//�����ڱ�
		int pre = 0, cur = 1, next = 2;
		int largest_area = 0;
		for (int j = 0; j < rectangle_number; j++, pre++, cur++)
		{
			cin >> rectangle[cur].height;
			rectangle_store[cur] = rectangle[cur].height;
			if (rectangle[pre].height <= rectangle[cur].height)
			{
				rectangle[cur].left_margin = pre;
				continue;
			}
			for (int k = pre; rectangle[k].height >= rectangle[cur].height || rectangle[k - 1].height == -3; k--)
			{
				if (rectangle[k].height > rectangle[cur].height)
				{
					rectangle[k].right_margin = cur;
					rectangle[k].height = -3;//ȷ���Ըþ��ε��ұ߽�󣬽��þ��θ߶���Ϊ-3������������ջ

				}
				if (rectangle[k - 1].height < rectangle[cur].height && rectangle[k - 1].height != -3)
					rectangle[cur].left_margin = k - 1;
			}

		}
		for (int k = pre; rectangle[k].height >= rectangle[cur].height || rectangle[k - 1].height == -3; k--)
		{
			if (rectangle[k].height > rectangle[cur].height)
			{
				rectangle[k].right_margin = cur;
				rectangle[k].height = -3;//ȷ���Ըþ��ε��ұ߽�󣬽��þ��θ߶���Ϊ-3������������ջ

			}
			if (rectangle[k - 1].height < rectangle[cur].height && rectangle[k - 1].height != -3)
				rectangle[cur].left_margin = k - 1;
		}
		for (int l = 1; l <= rectangle_number; l++)
		{
			if ((long long)rectangle_store[l] * (long long)(rectangle[l].right_margin - rectangle[l].left_margin - 1) > largest_area)
				largest_area = (long long)rectangle_store[l] * (long long)(rectangle[l].right_margin - rectangle[l].left_margin - 1);
		}
		largest_rectangle[i] = largest_area;
	}
	for (int i = 0; i < test_number; i++)
		cout << largest_rectangle[i] << endl;
	return 0;
}