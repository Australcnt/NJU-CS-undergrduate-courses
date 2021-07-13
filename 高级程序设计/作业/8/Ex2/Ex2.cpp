#include <iostream>
using namespace std;

// 比较double类型数据大小
int double_compare(const void* p1, const void* p2)
{
	if (*(double*)p1 < *(double*)p2)
		return -1;
	else if (*(double*)p1 > * (double*)p2)
		return 1;
	else
		return 0;
}

/*
通用归并排序算法（从小到大）
参数：
	base：需要排序的数据内存首地址
	count：数据元素个数
	element_size：一个数据元素所占内存大小
	cmp：比较两个元素的函数
*/
void merge_sort(void* base, unsigned int count, unsigned int element_size, int (*cmp)(const void*, const void*))
{
	if (count <= 1)
		return;
	merge_sort(base, count / 2, element_size, cmp);
	merge_sort((void*)((char*)base + count / 2 * element_size), count - count / 2, element_size, cmp);
	int i = 0, j = 0, k = 0;
	char* temp = new char[count * element_size];
	while (i < count / 2 && j < count - count / 2)
	{
		char* p1 = (char*)base + i * element_size;
		char* p2 = (char*)base + count / 2 * element_size + j * element_size;
		if (cmp(p1, p2) < 0)
		{
			for (int t = 0; t < element_size; t++)
				temp[k * element_size + t] = p1[t];
			i++;
		}
		else
		{
			for (int t = 0; t < element_size; t++)
				temp[k * element_size + t] = p2[t];
			j++;
		}
		k++;
	}
	while (i < count / 2)
	{
		char* p1 = (char*)base + i * element_size;
		for (int t = 0; t < element_size; t++)
			temp[k * element_size + t] = p1[t];
		i++;
		k++;
	}
	while (j < count - count / 2)
	{
		char* p2 = (char*)base + count / 2 * element_size + j * element_size;
		for (int t = 0; t < element_size; t++)
			temp[k * element_size + t] = p2[t];
		j++;
		k++;
	}
	for (int m = 0; m < count; m++)
	{
		char* p1 = (char*)base + m * element_size;
		char* p2 = (char*)temp + m * element_size;
		for (int n = 0; n < element_size; n++)
			p1[n] = p2[n];
	}
}

// 调用示例
int main()
{
	int num;
	cin >> num;
	double* array = new double[num];
	for (int i = 0; i < num; i++)
		cin >> array[i];
	merge_sort(array, num, sizeof(double), double_compare);
	for (int i = 0; i < num; i++)
		cout << array[i] << " ";
	return 0;
}