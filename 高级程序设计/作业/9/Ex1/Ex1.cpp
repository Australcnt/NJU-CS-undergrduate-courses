#include <iostream>

using namespace std;

template<class Type>
class MaxHeap {
private:
	Type* Data;
	int Size; //当前大小
	int Capacity; //总容量
	void SiftDown(int start, int m); //从 start 到 m 下滑调整成为最大堆
	void SiftUp(int start); //从 start 到 0 上滑调整成为最大堆
public:
	MaxHeap(); //默认构造函数，容量为10
	MaxHeap(int Capacity);
	~MaxHeap();
	bool Insert(Type element); //插入一个元素
	Type DeleteMax(); //找出最大的元素返回，并进行删除
	bool IsFull(); //是否为满
	bool IsEmpty(); //是否为空
	void Print(); //打印
};

template<class Type>
void MaxHeap <Type>::SiftDown(int start, int m)
{
	int i = start, j = 2 * i + 1;
	Type temp = Data[i];
	while (j <= m)
	{
		if (j < m && Data[j] < Data[j + 1])
			j++;
		if (temp >= Data[j])
			break;
		else
		{
			Data[i] = Data[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	Data[i] = temp;
}

template<class Type>
void MaxHeap <Type>::SiftUp(int start)
{
	int j = start, i = (j - 1) / 2;
	Type temp = Data[j];
	while (j > 0)
	{
		if (Data[i] >= temp)
			break;
		else
		{
			Data[j] = Data[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	Data[j] = temp;
}

template<class Type>
MaxHeap <Type>::MaxHeap()
{
	Capacity = 10;
	Data = new Type[Capacity];
	Size = 0;
}

template<class Type>
MaxHeap <Type>::MaxHeap(int Capacity)
{
	this->Capacity = Capacity;
	Data = new Type[Capacity];
	Size = 0;
}

template<class Type>
MaxHeap <Type>::~MaxHeap()
{
	Capacity = 0;
	delete[]Data;
	Data = NULL;
	Size = 0;
}

template<class Type>
bool MaxHeap <Type>::Insert(Type element)
{
	if(IsFull())
	{
		cout << "Heap Full" << endl;
		return false;
	}
	Data[Size] = element;
	SiftUp(Size);
	Size++;
	return true;
}

template<class Type>
Type MaxHeap <Type>::DeleteMax()
{
	if(IsEmpty())
	{
		cout << "Heap Empty" << endl;
		return false;
	}
	Type element;
	element = Data[0];
	Data[0] = Data[Size - 1];
	Size--;
	SiftDown(0, Size - 1);
	return true;
}

template<class Type>
bool MaxHeap <Type>::IsFull()
{
	return Size == Capacity;
}

template<class Type>
bool MaxHeap <Type>::IsEmpty()
{
	return Size == 0;
}

template<class Type>
void MaxHeap <Type>::Print()
{
	for (int i = 0; i < Size; i++)
		cout << Data[i] << " ";
	cout << endl;
}

int main()
{
	cout << "******* int型 *******" << endl << endl;
	MaxHeap<int> heap1;
	if (heap1.IsEmpty())
		cout << "Heap Empty" << endl;
	heap1.DeleteMax();
	heap1.Print();
	heap1.Insert(1);
	heap1.Print();
	if (heap1.IsEmpty())
		cout << "Heap Empty" << endl;
	heap1.Insert(6);
	heap1.Print();
	heap1.Insert(4);
	heap1.Print();
	heap1.Insert(3);
	heap1.Print();
	heap1.Insert(7);
	heap1.Print();
	heap1.Insert(9);
	heap1.Print();
	heap1.Insert(2);
	heap1.Print();
	heap1.Insert(8);
	heap1.Print();
	heap1.Insert(5);
	heap1.Print();
	if (heap1.IsFull())
		cout << "Heap Full" << endl;
	heap1.Insert(10);
	heap1.Print();
	if (heap1.IsFull())
		cout << "Heap Full" << endl;
	heap1.Insert(10);
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	heap1.Print();
	heap1.DeleteMax();
	cout << endl;
	cout << "******* double型 *******" << endl << endl;
	MaxHeap<double> heap2;
	if (heap2.IsEmpty())
		cout << "Heap Empty" << endl;
	heap2.DeleteMax();
	heap2.Print();
	heap2.Insert(1.2);
	heap2.Print();
	if (heap2.IsEmpty())
		cout << "Heap Empty" << endl;
	heap2.Insert(6.5);
	heap2.Print();
	heap2.Insert(4.7);
	heap2.Print();
	heap2.Insert(3.1);
	heap2.Print();
	heap2.Insert(7.8);
	heap2.Print();
	heap2.Insert(9.9);
	heap2.Print();
	heap2.Insert(2.3);
	heap2.Print();
	heap2.Insert(8.4);
	heap2.Print();
	heap2.Insert(5.7);
	heap2.Print();
	if (heap2.IsFull())
		cout << "Heap Full" << endl;
	heap2.Insert(10.6);
	heap2.Print();
	if (heap2.IsFull())
		cout << "Heap Full" << endl;
	heap2.Insert(10.2);
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	heap2.Print();
	heap2.DeleteMax();
	return 0;
}