//����ջ���ڱ��ⷨ
#include <iostream>

using namespace std;

int main()
{
	int test_number;//������������
	cin >> test_number;
	long long largest_rectangle[100];
	for (int i = 0; i < test_number; i++)
	{
		int rectangle_number;//�ò��������ľ�������
		cin >> rectangle_number;
		int rectangle[100002];
		if (rectangle_number == 1)//��������Ϊ1
		{
			cin >> largest_rectangle[i];
			continue;
		}
		else if (rectangle_number == 2)//��������Ϊ2
		{
			cin >> rectangle[0] >> rectangle[1];
			if (rectangle[0] > rectangle[1])
				largest_rectangle[i] = rectangle[1] * 2;
			else
				largest_rectangle[i] = rectangle[0] * 2;
			continue;
		}
		rectangle[0] = 0;//�����ڱ�
		rectangle[rectangle_number + 1] = 0;//�����ڱ�
		int pre = 0, cur = 1, next = 2;
		int largest_area = 0;
		for (int j = 0; j < rectangle_number; j++, pre++, cur++)
		{
			cin >> rectangle[cur];
			if (rectangle[pre] <= rectangle[cur])
				continue;
			for (int k = pre; rectangle[k] > rectangle[cur]; k--)
			{
				int search_back = k - 1;
				while (rectangle[search_back] == -1 || rectangle[search_back] >= rectangle[k])
					search_back--;
				long long area = (cur - search_back - 1) * rectangle[k];
				if (area > largest_area)
					largest_area = area;
				rectangle[k] = -1;//ȷ���Ըþ���Ϊ���߶ȵľ�������󣬽��þ��θ߶���Ϊ-1������������ջ
			}
		}
		for (int k = pre; rectangle[k] > rectangle[cur]; k--)
		{
			int search_back = k - 1;
			while (rectangle[search_back] == -1 || rectangle[search_back] >= rectangle[k])
				search_back--;
			long long area = (cur - search_back - 1) * rectangle[k];
			if (area > largest_area)
				largest_area = area;
			rectangle[k] = -1;
		}
		largest_rectangle[i] = largest_area;
	}
	for (int i = 0; i < test_number; i++)
		cout << largest_rectangle[i] << endl;
	return 0;
}