#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

class Queue
{
protected:
	Node* head;
	Node* tail;
public:
	Queue() { head = NULL; tail = NULL; }
	~Queue() { while (head) { Node* p = head; head = head->next; delete p; } }
	virtual bool enqueue(int num) = 0; //入列
	virtual bool dequeue(int& num) = 0; //出列
	void display();
};

class Queue1 : public Queue // 先进先出
{
public:
	bool enqueue(int num); //入列
	bool dequeue(int& num); //出列
};

bool Queue1::enqueue(int num) //入列
{
	Node* p = new Node;
	p->value = num;
	p->next = NULL;
	if (head == NULL)
	{
		head = p;
		tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
	return true;
}

bool Queue1::dequeue(int& num) //出列
{
	if (head == NULL)
		return false;
	Node* p = head;
	num = p->value;
	head = head->next;
	delete p;
	return true;
}

class Queue2 : public Queue // 最小元素先出
{
public:
	bool enqueue(int num); //入列
	bool dequeue(int& num); //出列
};

bool Queue2::enqueue(int num) //入列
{
	Node* p = new Node;
	p->value = num;
	p->next = NULL;
	if (head == NULL)
	{
		head = p;
		tail = p;
	}
	else
	{
		Node* cur = head;
		Node* pre = NULL;
		while (cur != NULL && cur->value < num)
		{
		    pre = cur;
			cur = cur->next;
		}
		p->next = cur;
		if (pre != NULL)
			pre->next = p;
		else
			head = p;
		if (p->next == NULL)
			tail = p;
	}
	return true;
}

bool Queue2::dequeue(int& num) //出列
{
	if (head == NULL)
		return false;
	Node* p = head;
	num = p->value;
	head = head->next;
	delete p;
	return true;
}

class Queue3 : public Queue // 最大元素先出
{
public:
	bool enqueue(int num); //入列
	bool dequeue(int& num); //出列
};

bool Queue3::enqueue(int num) //入列
{
	Node* p = new Node;
	p->value = num;
	p->next = NULL;
	if (head == NULL)
	{
		head = p;
		tail = p;
	}
	else
	{
		Node* cur = head;
		Node* pre = NULL;
		while (cur != NULL && cur->value > num)
		{
			pre = cur;
			cur = cur->next;
		}
		p->next = cur;
		if (pre != NULL)
			pre->next = p;
		else
			head = p;
	}
	return true;
}

bool Queue3::dequeue(int& num) //出列
{
	if (head == NULL)
		return false;
	Node* p = head;
	num = p->value;
	head = head->next;
	delete p;
	return true;
}

void Queue::display()
{
	Node* p = head;
	while(p)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int num = 0;
	Queue1 queue1;
	Queue2 queue2;
	Queue3 queue3;

	queue1.enqueue(1);
	queue1.display();
	queue1.dequeue(num);
	queue1.display();
	queue1.enqueue(1);
	queue1.enqueue(2);
	queue1.display();
	queue1.dequeue(num);
	queue1.display();
	queue1.enqueue(3);
	queue1.display();
	cout << endl << endl;

	queue2.enqueue(1);
	queue2.display();
	queue2.dequeue(num);
	queue2.display();
	queue2.enqueue(2);
	queue2.display();
	queue2.enqueue(1);
	queue2.display();
	queue2.dequeue(num);
	queue2.display();
	queue2.enqueue(3);
	queue2.display();
	cout << endl << endl;

	queue3.enqueue(1);
	queue3.display();
	queue3.dequeue(num);
	queue3.display();
	queue3.enqueue(1);
	queue3.enqueue(2);
	queue3.display();
	queue3.dequeue(num);
	queue3.display();
	queue3.enqueue(3);
	queue3.display();
	cout << endl << endl;

	return 0;
}