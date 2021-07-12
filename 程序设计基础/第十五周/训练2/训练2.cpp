#include <iostream>//未完成代码
using namespace std;
struct Node
{
	char a;
	Node *next;
};
Node *AppCreate()
{
	Node *head = NULL, *tail = NULL;
	for (int i = 0;;i++)
	{
		Node *p = new Node;
		cin >> (p->a);
		if ((p->a) == '\n')
			break;//似乎不能结束循环？
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	return head;
}
void PrintList(Node *head)
{ 
	while (head!=NULL)
	{
		cout << head->a;
	    head = head->next;
	}
	cout << endl;
}
Node *Compress(Node *head)
{
	Node *newhead = NULL, *newtail = NULL;
	while (head != NULL)
	{
		Node *p = new Node;
		p->a = head->a;
		p->next = NULL;
		
			if (newhead == NULL)
				newhead = p;
			else
				newtail->next = p;
			newtail = p;
			for (int i = 1; head->a == head->next->a&&head->next != NULL; i++)
		{
			head = head->next;
			if (head->a != head->next->a)
			{
				Node *q = new Node;
				q->a = i;//需要将i转化为char型
				q->next = NULL;
				newtail->next = q;
				newtail = q;
			}
		}
			head = head->next;
	}
	return newhead;
}
Node *Decompress(Node *head)
{
	Node *newhead = NULL, *newtail = NULL;
	while (head!=NULL)
	{
		Node *p = new Node;
		p->a = head->a;
		p->next = NULL;

		if (newhead == NULL)
			newhead = p;
		else
			newtail->next = p;
		newtail = p;
		int i = 0;
		while (head->next->a >= '0'&&head->next->a <= '9')
		{
			for (int j = -1; head->next->a >= '0';j++)
			{ 
				if (head->next->a == '0')
			{
				j++;
				i = 10 * i + j;
			}
			head->next->a = head->next->a + '0' - '1';
			}
			
			if (head->next->next->a<'0' || head->next->next->a>'9')
				for (; i > 0;i--)
				{
					Node *q = new Node;
					q->a = head->a;
					q->next = NULL;
					newtail->next = q;
					newtail = q;
				}
			head = head->next;
		}
		head = head->next;
	}
	return newhead;
}
int main()
{
	int x;
	cin >> x;
	if (x == 1)
	{
		Node *head = AppCreate();
		head = Compress(head);
		PrintList(head);
	}

	if (x == 2)
	{
		Node *head = AppCreate();
		head = Decompress(head);
		PrintList(head);
	}
	return 0;
}