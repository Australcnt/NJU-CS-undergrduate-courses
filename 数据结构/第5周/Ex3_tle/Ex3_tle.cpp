#include <iostream>

using namespace std;

int widest_rectangle_search(int rectangle[], int rectangle_number);//最大宽度矩形搜索
int lowest_rectangle_search(int rectangle[], int rectangle_number);//最矮矩形搜索，除0

int main()
{
	int test_number;
	cin >> test_number;
	long long int largest_rectangle[100];
	for (int i = 0; i < test_number; i++)
	{
		int rectangle_number;
		cin >> rectangle_number;
		int rectangle[100000];
		int highest_rectangle = 0;
		for (int j = 0; j < rectangle_number; j++)
		{
			cin >> rectangle[j];
			if (rectangle[j] > highest_rectangle)
				highest_rectangle = rectangle[j];
		}
		int width = 0, height = 1;
		long long int area = 0, largest_area = 0;
		while (height <= highest_rectangle)
		{
			width = widest_rectangle_search(rectangle, rectangle_number);
			area = (long long int)width * (long long int)height;
			if (area > largest_area)
				largest_area = area;
			if (height == highest_rectangle)
				break;
			do//消去最底层
			{
				for (int k = 0; k < rectangle_number; k++)
					if (rectangle[k] != 0)
						rectangle[k]--;
				height++;
			} while (lowest_rectangle_search(rectangle, rectangle_number) > 1);
		}
		largest_rectangle[i] = largest_area;
	}
	for (int i = 0; i < test_number; i++)
		cout << largest_rectangle[i] << endl;
	return 0;
}

int widest_rectangle_search(int rectangle[], int rectangle_number)
{
	int width = 0, longest_width = 0;
	for (int i = 0; i < rectangle_number; i++)
	{
		if (rectangle[i] > 0)
		{
			width++;
			if (width > longest_width)
				longest_width = width;

		}
		else
			width = 0;
	}
	return longest_width;
}

int lowest_rectangle_search(int rectangle[], int rectangle_number)
{
	int lowest_height = 1000000000;
	for (int i = 0; i < rectangle_number; i++)
	{
		if (rectangle[i] > 0 && rectangle[i] < lowest_height)
			lowest_height = rectangle[i];
	}
	return lowest_height;
}