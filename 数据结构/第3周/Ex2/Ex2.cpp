#include <iostream>
using namespace std;

struct Node
{
	int pre;
	int cur;
	Node* next;
};

Node* list_search(Node* first, int x);

int main()
{
	int n;
	cin >> n;
	Node* head = NULL, * tail = NULL;//创建链表
	for (int i = 0; i < n; i++)
	{
		Node* p = new Node;
		cin >> p->cur;
		cin >> p->pre;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	Node* first = new Node;//创建头节点
	first->pre = -1;
	first->cur = -1;
	first->next = head;
	int id_pre = 0;
	while (first->next != NULL)
	{
		Node* node_pre = list_search(first, id_pre);
		cout << node_pre->next->cur << ' ';
		id_pre = node_pre->next->cur;
		Node* node_cur = node_pre->next;
		node_pre->next = node_cur->next;
		delete node_cur;
	}
	return 0;
}

Node* list_search(Node* first, int x)//链表检索，返回前一个结点
{
	while (first->next != NULL)
	{
		if (first->next->pre == x)
			return first;
		first = first->next;
	}
}