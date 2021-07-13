#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int>max_heap;
	vector<int>min_heap;
	int num = 0;
	while (cin >> num)
	{
		if (max_heap.size() == min_heap.size())
		{
			if (max_heap.empty())
			{
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end(), less<int>());
			}
			else
			{
				if (num < min_heap[0])
				{
					max_heap.push_back(num);
					push_heap(max_heap.begin(), max_heap.end(), less<int>());
				}
				else
				{
					min_heap.push_back(num);
					push_heap(min_heap.begin(), min_heap.end(), greater<int>());
					num = min_heap[0];
					pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
					min_heap.pop_back();
					max_heap.push_back(num);
					push_heap(max_heap.begin(), max_heap.end(), less<int>());
				}
			}
		}
		else
		{
			if (num > max_heap[0])
			{
				min_heap.push_back(num);
				push_heap(min_heap.begin(), min_heap.end(), greater<int>());
			}
			else
			{
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end(), less<int>());
				num = max_heap[0];
				pop_heap(max_heap.begin(), max_heap.end(), less<int>());
				max_heap.pop_back();
				min_heap.push_back(num);
				push_heap(min_heap.begin(), min_heap.end(), greater<int>());
			}

		}
		cout << max_heap[0] << " ";
	}
	cout << endl;
	return 0;
}