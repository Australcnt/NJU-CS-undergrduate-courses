#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
	int data;
	int cur_addr;
	int pre_addr;
	int next_addr;
	Node* next;
	Node* rLink;
	Node* lLink;
};

Node* list_search(Node* first, int addr);

int main()
{
	int first_addr;
	int data_number;
	cin >> first_addr;
	cin >> data_number;
	Node* head = NULL, * tail = NULL;
	Node* first = NULL, * last = NULL;
	for (int i = 0; i < data_number; i++)
	{
		Node* p = new Node;
		cin >> p->cur_addr;
		cin >> p->data;
		cin >> p->next_addr;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		if (p->cur_addr == first_addr)
		{
			first = p;
			first->lLink = NULL;
			first->pre_addr = -1;
		}
		if (p->next_addr == -1)
		{
			last = p;
			last->rLink = NULL;
		}
	}
	Node* fakefirst = first;
	while (fakefirst->next_addr != -1)
	{
		fakefirst->rLink = list_search(head, fakefirst->next_addr);
		fakefirst = fakefirst->rLink;
	}
	if (first->next_addr == -1)//长度为1
		;
	else if (first->rLink->next_addr == -1)
		first->rLink->lLink = first;//长度为2
	else//长度大于2
	{
		Node* pre_Node = first;
		Node* cur_Node = first->rLink;
		Node* next_Node = first->rLink->rLink;
		while (1)
		{
			cur_Node->lLink = pre_Node;
			next_Node->lLink = cur_Node;
			cur_Node->pre_addr = pre_Node->cur_addr;
			next_Node->pre_addr = cur_Node->cur_addr;
			pre_Node = next_Node;
			cur_Node = pre_Node->rLink;
			if (cur_Node == NULL)
				break;
			next_Node = cur_Node->rLink;
			if (next_Node == NULL)
				break;
		}
		if (next_Node == NULL)
		{
			cur_Node->lLink = pre_Node;
			cur_Node->pre_addr == pre_Node->cur_addr;
		}
	}
	Node* fakelast = last;
	while (fakelast != NULL)
	{
		if (fakelast->pre_addr == -1)
			cout << setfill('0') << setw(5) << fakelast->cur_addr << ' ' << fakelast->data << ' ' << "-1" << endl;
		else
			cout << setfill('0') << setw(5) << fakelast->cur_addr << ' ' << fakelast->data << ' ' << setfill('0') << setw(5) << fakelast->pre_addr << endl;
		fakelast = fakelast->lLink;
	}
}

Node* list_search(Node* head, int addr)
{
	while (head->cur_addr != addr)
		head = head->next;
	return head;
}