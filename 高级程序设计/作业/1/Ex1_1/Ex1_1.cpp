#include <iostream>

using namespace std;

const int QUEUE_SIZE = 100;

class Queue
{
public: //对外的接口（外部可使用的内容）
	Queue(); // 构造函数
	void enQueue(int i); // ⼊队列
	void deQueue(int& i); // 出队列
	void printAll(); // 打印队列内所有元素
private: //隐藏的内容，外部不可使用
	int count;
	struct Node
	{
		int content;
		Node* next;
	}*head, * tail;
};

Queue::Queue()
{
	count = 0;
	head = NULL;
	tail = head;
}

void Queue::enQueue(int i)
{
	Node* p = new Node;
	if (count == QUEUE_SIZE - 1)
	{
		cout << "Queue is overflow.\n";
		exit(-1);
	}
	else
	{

		p->content = i;
		p->next = NULL;
		if (tail == NULL)
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
		count++;
		return;
	}
}
void Queue::deQueue(int& i)
{
	if (count == 0)
	{
		cout << "Queue is empty.\n";
		exit(-1);
	}
	else
	{
		Node* p = head;
		head = head->next;
		i = p->content;
		delete p;
		count--;
		return;
	}
}

void Queue::printAll()
{
	Node* p = head;
	while (p != NULL)
	{
		cout << p->content << endl;
		p = p->next;
	}
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