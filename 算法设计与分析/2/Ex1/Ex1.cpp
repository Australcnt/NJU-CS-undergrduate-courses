#include <iostream>

using namespace std;

void BubbleSort(int array[], int length);

int main()
{
	int k = 0;
	int length = 0;
	int array[10000];
	cin >> k >> length;
	for (int i = 0; i < length; i++)
		cin >> array[i];
	BubbleSort(array, length);
	int i = 0;
	for (i=length / 2 - 1 - k; i < length / 2 - 1 + k; i++)
		cout << array[i] << " ";
	cout << array[i] << endl;
	return 0;
}

void BubbleSort(int array[],int length)
{
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}