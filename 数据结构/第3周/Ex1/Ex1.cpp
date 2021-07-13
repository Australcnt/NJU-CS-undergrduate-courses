#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

void list_delete(Node* head);

int main()
{
	Node* head = NULL, * tail = NULL;
	for (int i = 0; i < 40000; i++)
	{
		Node* p = new Node;
		p->data = i + 2;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	Node* first = new Node;
	first->data = 0;
	first->next = head;
	Node* fakehead = head;
	while (fakehead != NULL)
	{
		list_delete(fakehead);
		fakehead = fakehead->next;
	}
	int n;
	cin >> n;
	int lucky_number[3000];
	int lucky_count = 0;
	while (n != 0)
	{
		Node* cur = first;
		for (int i = 0; i < n; i++)
			cur = cur->next;
		lucky_number[lucky_count] = cur->data;
		lucky_count++;
		cin >> n;
	}
	for (int i = 0; i < lucky_count; i++)
		cout << lucky_number[i] << endl;
	return 0;
}

void list_delete(Node* head)
{
	int k = head->data;
	while (head != NULL)
	{
		for (int i = 0; i < k - 1; i++)
		{
			head = head->next;
			if (head == NULL)
				return;
		}
		if (head->next == NULL)
			return;
		Node* cur = head->next;
		head->next = cur->next;
		delete cur;
	}
}