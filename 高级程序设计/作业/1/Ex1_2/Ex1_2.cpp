#include <iostream>

using namespace std;

const int QUEUE_SIZE = 100;

class Queue
{
public: // 对外的接口（外部可使用的内容）
	Queue(); // 构造函数
	void enQueue(int i); // 入队列
	void deQueue(int& i); // 出队列
	void printAll(); // 打印队列内所有元素
private: // 隐藏的内容，外部不可使用
	int size;
	int head;
	int tail;
	int *buffer;
	int count;
};

Queue::Queue()
{
	size = 10;//队列容量
	head = 0;
	tail = -1;
	buffer = new int[10];
	count = 0;//元素个数
}

void Queue::enQueue(int i)
{
	if (tail != -1 && (tail + 1) % QUEUE_SIZE == head && count != 0)
	{
		cout << "Queue is overflow.\n";
		exit(-1);
	}
	else
	{
		if (tail != -1 && (tail + 1) % size == head && count != 0)
		{
			int* newbuffer = new int[size + 10];//每次扩容10个元素
			for (int i = 0; i < size; i++)
				newbuffer[i] = buffer[(head + i) % size];
			int* temp = buffer;
			buffer = newbuffer;
			delete[]temp;//释放原队列空间
			head = 0;
			tail = size - 1;
			size = size + 10;
		}
		tail = (tail + 1) % size;
		buffer[tail] = i;
		count++;
		return;
	}
}
void Queue::deQueue(int& i)
{
	if ((tail + 1) % QUEUE_SIZE == head && count == 0)
	{
		cout << "Queue is empty.\n";
		exit(-1);
	}
	else
	{
		i = buffer[head];
		head = (head + 1) % size;
		count--;
		return;
	}
}

void Queue::printAll()
{
	for (int i = 0 ; i < count; i++)
		cout << buffer[(head + i) % size] << endl;
}
int main()
{
	Queue queue;
	int i = 0;
	printf("i=%d\n", i);
	queue.enQueue(1);
	queue.enQueue(2);
	queue.deQueue(i);
	queue.enQueue(3);
	printf("i=%d\n", i);
	queue.printAll();
	return 0;
}