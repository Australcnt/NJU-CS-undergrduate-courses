#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
Node *InsCreate()
{
	Node *head = NULL;
	int N;
	cin >> N;
	for (int i = 0; i < N;i++)
	{
		Node *p = new Node;
		cin >> p->data;
		p->next = head;
		head = p;
	}
	return head;
}
int SumR(Node *head)
{
	int Sum;
	if (head == NULL)
		Sum = 0;
	else if (head->next != NULL)
	{
		Sum = SumR(head->next) + head->data;
		head = head->next;
	}
	else
		Sum = head->data;
	return Sum;
}
int main()
{
	Node *head = InsCreate();
	cout << SumR(head) << endl;
	return 0;
}
