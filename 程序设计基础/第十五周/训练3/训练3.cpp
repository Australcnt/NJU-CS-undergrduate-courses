#include <iostream>
using namespace std;
#define N 10
struct Node
{
	int data;
	Node *next;
};
Node *AppCreate()
{
	Node *head = NULL, *tail = NULL;
	for (int i=0;i<N;i++)
	{
		Node *p = new Node;
		cin >> p->data;
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
	else
		while (head)
		{
			cout << head->data << ' ';
			head = head->next;
		}
	cout << endl;
}
Node *ListBubbleSort(Node *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	for (int i = 0; i < N - 1; i++)
	{
		Node *fakehead1 = head;
		for (int j = 0; j < N - i - 1; j++)
		{
			Node *fakehead2 = fakehead1;
			if (fakehead2->data >= fakehead2->next->data)
			{
				int temp = fakehead2->data;
				fakehead2->data = fakehead2->next->data;
				fakehead2->next->data = temp;
				fakehead2 = fakehead2->next;
			}
			fakehead1 = fakehead1->next;
		}
	}
	return head;
}
int main()
{
	Node *head = AppCreate();
	head = ListBubbleSort(head);
	PrintList(head);
	return 0;
}