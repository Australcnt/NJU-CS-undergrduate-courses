#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
int x = 0;
int list_tail_insert(Node* list_head, int var);
Node* list_head_insert(Node* list_head, int var);
Node* list_specific_insert(Node* list_head, int location, int var);
void print_list(Node* list_head);
void reverse_print_list(Node* list_head);
void change_specific_var(Node* list_head, int old_var, int new_var);
Node* del_specific_var(Node* list_head, int del_var);
Node* sort(Node* list_head);
int main()
{
	Node* head = NULL;
	head = list_head_insert(head, 1);
	head = list_head_insert(head, 2);
	head = list_head_insert(head, 2);
	list_tail_insert(head, 5);
	list_tail_insert(head, 6);
	head = list_specific_insert(head, 4, 4);//正常插入
	print_list(head);

	head = list_specific_insert(head, 1, 8);//头位置插入
	print_list(head);

	head = list_specific_insert(head, 8, 9);//尾位置插入
	print_list(head);

	head = sort(head);
	print_list(head);

	reverse_print_list(head);

	change_specific_var(head, 2, 3);
	print_list(head);

	head = del_specific_var(head, 3);
	print_list(head);

	return 0;

}
int list_tail_insert(Node* list_head, int var)
{
	Node* p = new Node;
	p->data = var;
	p->next = NULL;
	if (!list_head)
		return -1;
	else
	{
		while (list_head->next)
			list_head = list_head->next;
		list_head->next = p;
		return 0;
	}
}
Node* list_head_insert(Node* list_head, int var)
{
	Node* p = new Node;
	p->data = var;
	if(!list_head)
	{
		p->next = NULL;
		list_head = p;
	}
	else
	{
		p->next = list_head;
		list_head = p;
	}
	return list_head;
}
Node* list_specific_insert(Node* list_head, int location, int var)
{
	Node* p = new Node;
	p->data = var;
	if (location < 1)
	{
		cout << "The format of location is wrong" << endl;
		return list_head;
	}
	else if (location == 1)
	{
		p->next = list_head;
		list_head = p;
	}
	else if(location == 2)
	{
		p->next = list_head->next;
		list_head->next = p;
	}
	else 
	{
		Node* fakehead = list_head;
		for (int i = 1; i < location - 1 && fakehead->next != NULL; i++)
			fakehead = fakehead->next;
		if (!fakehead->next)
		{
			fakehead->next = p;
			p->next = NULL;
		}
		else
		{
			p->next = fakehead->next;
			fakehead->next = p;
		}
	}
	return list_head;
}
void print_list(Node* list_head)
{
	if (!list_head)
		cout << ' ' << endl;
	else
	{
		while (list_head->next)
		{
			cout << list_head->data << ' ';
			list_head = list_head->next;
		}
		cout << list_head->data << endl;
	}
}
void reverse_print_list(Node* list_head)
{
	if (!list_head)
		cout << ' ' << endl;
	else if (!list_head->next)
		cout << list_head->data << ' ';
	else
	{
		x++;
		reverse_print_list(list_head->next);
		cout << list_head->data << ' ';
		x--;
	}
	if (x == 0)
		cout << endl;
}
void change_specific_var(Node* list_head, int old_var, int new_var)
{
	while (list_head)
	{
		if (list_head->data == old_var)
			list_head->data = new_var;
		list_head = list_head->next;
	}
}
Node* del_specific_var(Node* list_head, int del_var)
{
	if (!list_head)
		return list_head;
	else
	{
		while (list_head && list_head->data == del_var)
			list_head = list_head->next;
		Node* fakehead = list_head;
		while(fakehead && fakehead->next)
		{
			if (fakehead->next->data == del_var)
			{
				Node* cur = fakehead->next;
				fakehead->next = cur->next;
				delete(cur);
			}
			else
			fakehead = fakehead->next;
			if (!fakehead)
				break;
		}
		return list_head;
	}
}
Node* sort(Node* list_head)
{
	if (!list_head || !list_head->next)
		return list_head;
	else
	{
		Node* cur = list_head->next;
		list_head->next = NULL;
		while(cur)
		{
			Node* prev = cur;
			cur = cur->next;
			if (prev->data < list_head->data)
			{
				prev->next = list_head;
				list_head = prev;
			}
			else
			{
				Node* cur2 = list_head;
				Node* prev2 = list_head;
				while (cur2)
				{
					if (prev->data < cur2->data)
						break;
					prev2 = cur2;
					cur2 = cur2->next;
				}
				prev->next = prev2->next;
				prev2->next = prev;
			}
		}
		return list_head;
	}
}
