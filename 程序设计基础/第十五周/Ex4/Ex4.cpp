#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
Node *AppCreate1()
{
	Node *head = NULL, *tail = NULL;
	for (int i = 0;;i++)
	{
		Node *p = new Node;
		cin >> p->data;
		if (p->data == -1)
		{
			p = NULL;
			tail->next = p;
			tail = p;
			break;
		}
		else
		{
			p->next = NULL;
			if (head == NULL)
				head = p;
			else
				tail->next = p;
			tail = p;
		}
	}
	return head;
}
Node *AppCreate2()
{
	Node *head = NULL, *tail = NULL;
	for (int j = 0; j < 100; j++)
	{
		Node *p = new Node;
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
	if (head == NULL)
		cout << -1 << endl;
	else
	{
		while (head != NULL)
		{
			cout << head->data << ' ';
			head = head->next;
		}
		cout << -1 << endl;
	}
}
void Intersection(Node *head1,Node *head2)
{
	Node *head = NULL, *tail = NULL;
	if (head1 != NULL&&head2 != NULL)
	{
		while (head1 != NULL)
		{
			Node *fakehead2 = head2;
			while (fakehead2 != NULL)
			{
				if (head1->data == fakehead2->data)
				{
					Node *p = new Node;
					p->next = NULL;
					p->data = head1->data;
					if (head == NULL)
						head = p;
					else
						tail->next = p;
					tail = p;
				}
				fakehead2 = fakehead2->next;
			}
			head1 = head1->next;
		}
	}
	PrintList(head);
}
void Complementaryset(Node *head1, Node *head2)
{
	Node *head = NULL, *tail = NULL;
	if (head1 != NULL&&head2 != NULL)
	{
		Node *fakehead1 = head1;
		while (fakehead1 != NULL)
		{
			Node *fakehead2 = head2;
			while (fakehead2 != NULL)
			{
				if (fakehead1->data == fakehead2->data)
				{
					Node *p = new Node;
					p->next = NULL;
					p->data = fakehead1->data;
					if (head == NULL)
						head = p;
					else
						tail->next = p;
					tail = p;
				}
				fakehead2 = fakehead2->next;
			}
			fakehead1 = fakehead1->next;
		}
		
		Node *fakehead11 = head1;
		while (fakehead11 != NULL)
		{
			Node *fakehead22 = head2;
			while (fakehead22 != NULL&&fakehead11->data != fakehead22->data)
				fakehead22 = fakehead22->next;
			if (fakehead22 == NULL)
			{
				Node *p = new Node;
				p->next = NULL;
				p->data = fakehead11->data;
				
				if (head == NULL)
					head = p;
				else
					tail->next = p;
				tail = p;
				
			}
			fakehead11 = fakehead11->next;
		}
		Node *fakehead222 = head2;
		while (fakehead222 != NULL)
		{
			Node *fakehead111 = head1;
			while (fakehead111 != NULL&&fakehead222->data != fakehead111->data)
				fakehead111 = fakehead111->next;
			if (fakehead111 == NULL)
			{
				Node *p = new Node;
				p->next = NULL;
				p->data = fakehead222->data;
				tail->next = p;
				tail = p;
			}
			fakehead222 = fakehead222->next;
		}
	}
	else if (head1 != NULL&&head2 == NULL)
		head = head1;
	else if (head1 == NULL&&head2 != NULL)
		head = head2;
	PrintList(head);
}
void Differenceset(Node *head1, Node *head2)
{
	Node *head = NULL, *tail = NULL;
	if (head1 != NULL&&head2 != NULL)
	{
		while (head1 != NULL)
		{
			Node *fakehead2 = head2;
			while (fakehead2 != NULL&&head1->data != fakehead2->data)
				fakehead2 = fakehead2->next;
			if (fakehead2 == NULL)
			{
				Node *p = new Node;
				p->next = NULL;
				p->data = head1->data;
				if (head == NULL)
					head = p;
				else
					tail->next = p;
				tail = p;
			}
			head1 = head1->next;
		}
	}
	if (head1 != NULL&&head2 == NULL)
		head = head1;
	PrintList(head);
}
int main()
{
	Node *head1 = AppCreate1();
	Node *head2 = AppCreate1();
	Intersection(head1, head2);
	Complementaryset(head1, head2);
	Differenceset(head1, head2);
	return 0;
}