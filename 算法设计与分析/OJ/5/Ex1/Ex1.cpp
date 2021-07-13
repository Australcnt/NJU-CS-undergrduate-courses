#include <iostream>
#include <algorithm>

using namespace std;

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int n;
	cin >> n;
	int sum;
	cin >> sum;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	qsort(array, n, sizeof(int), cmp);
	int count = 0;
	int left = 0, median = 0, right = 0;
	for (; left < n - 2; left++)
	{
		median = left + 1;
		right = n - 1;
		while (median < right)
		{
			if (array[left] + array[median] + array[right] == sum)
			{
				count++;
				median++;
				right--;
			}
			else if (array[left] + array[median] + array[right] < sum)
				median++;
			else
				right--;
		}
	}
	cout << count << endl;
	return 0;
}