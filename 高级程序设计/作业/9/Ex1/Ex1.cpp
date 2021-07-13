#include <iostream>

using namespace std;

template<class Type>
class MaxHeap {
private:
	Type* Data;
	int Size; //��ǰ��С
	int Capacity; //������
	void SiftDown(int start, int m); //�� start �� m �»�������Ϊ����
	void SiftUp(int start); //�� start �� 0 �ϻ�������Ϊ����
public:
	MaxHeap(); //Ĭ�Ϲ��캯��������Ϊ10
	MaxHeap(int Capacity);
	~MaxHeap();
	bool Insert(Type element); //����һ��Ԫ��
	Type DeleteMax(); //�ҳ�����Ԫ�ط��أ�������ɾ��
	bool IsFull(); //�Ƿ�Ϊ��
	bool IsEmpty(); //�Ƿ�Ϊ��
	void Print(); //��ӡ
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
	cout << "******* int�� *******" << endl << endl;
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
	cout << "******* double�� *******" << endl << endl;
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