#include <iostream>
using namespace std;
#define N 10
#define M 5
struct Node
{
	char a;
	Node *next;
};
Node *AppCreate()
{
	Node *head = NULL, *tail = NULL;
	for (int i = 0; i < N;i++)
	{
		Node *p = new Node;
		cin >> p->a;
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
		cout << NULL;
	while (head)
	{
		cout << head->a;
		head = head->next;
	}
	cout << endl;
}
bool HasLoop(Node *head)
{
	Node *fakehead1 = head;
	while (fakehead1!=NULL)
	{
		Node *fakehead2 = head;
		while (fakehead2!=fakehead1->next)
		{
			if (fakehead1->next == fakehead2)
				return true;
			fakehead2 = fakehead2->next;
		}
		fakehead1 = fakehead1->next;
	}
	return false;
}
void CreateLoop(Node *&head,int m)
{
	Node *fakehead3 = head;
	Node *fakehead4 = head;
	while (fakehead3->next)
		fakehead3 = fakehead3->next;
	for (int i = 1; i < m; i++)
		fakehead4 = fakehead4->next;
	fakehead3->next = fakehead4;
}
int main()
{
	Node *head = AppCreate();
	if (!HasLoop(head))
		CreateLoop(head, M);
	PrintList(head);
	return 0;
}