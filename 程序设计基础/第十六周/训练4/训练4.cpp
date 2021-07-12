#include <iostream>
using namespace std;
struct Node
{
	char word[20];
	Node *next;
};
Node *AppCreate()
{
	Node *head = NULL, *tail = NULL;
	for (;;)
	{
		Node *p = new Node;
		cin >> p->word;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		for (int i = 0; p->word[i]!='\0'; i++)
		{
			if (p->word[i] == '.')
			{
				p->word[i] = '\0';
				return head;
			}
		}
	}
}
Node *Transfer(Node *head)
{
	Node *fakehead = head;
	while (fakehead)
	{
		for (int i = 0; fakehead->word[i] != '\0'; i++)
		{
			if (fakehead->word[i] >= 'A'&&fakehead->word[i] <= 'Z')
				fakehead->word[i] = fakehead->word[i] + 'a' - 'A';
		}
		fakehead = fakehead->next;
	}
	return head;
}
Node *SortWord(Node *head)
{
	Node *newhead = NULL, *newtail = NULL;
	for (;;)
	{
		Node *fakehead = head;
		Node *min = fakehead;
		while (fakehead->next)
		{
			for (int i = 0;; i++)
			{
				if (min->word[i] > fakehead->next->word[i] || (fakehead->next->word[i] == '\0'&&min->word[i] != '\0'))
				{
					Node *current = new Node;
					for (int i = 0;; i++)
					{
						current->word[i] = min->word[i];
						if (min->word[i] == '\0')
							break;
					}
					for (int i = 0;; i++)
					{
						min->word[i] = fakehead->next->word[i];
						if (fakehead->next->word[i] == '\0')
							break;
					}
					for (int i = 0;; i++)
					{
						fakehead->next->word[i] = current->word[i];
						if (current->word[i] == '\0')
							break;
					}
					delete(current);
					break;
				}
				if (min->word[i] < fakehead->next->word[i] || min->word[i] == '\0')
					break;
			}
			fakehead = fakehead->next;
		}
		Node *fakenewhead = newhead;
		while (fakenewhead)
		{
			for (int i = 0; fakenewhead->word[i] == min->word[i]; i++)
			{
				if (fakenewhead->word[i] == '\0'&&min->word[i] == '\0')
					goto A;
			}
			fakenewhead = fakenewhead->next;
		}
			Node *p = new Node;
			for (int i = 0;; i++)
			{
				p->word[i] = min->word[i];
				if (min->word[i] == '\0')
					break;
			}
			p->next = NULL;
			if (newhead == NULL)
				newhead = p;
			else
				newtail->next = p;
			newtail = p;
		A:
			if (!head->next)
				break;
			if (min->next)
			{
				head = head->next;
				delete(min);
			}
	}
	return newhead;
}
void PrintList(Node *head)
{
	if (head == NULL)
		cout << NULL;
	else
	{ 
		while (head)
		{
			for (int i = 0;head->word[i]!='\0'; i++)
			cout << head->word[i];
			cout << ' ';
			head = head->next;
		}
	}
	cout << endl;
}
int main()
{
	Node *head = AppCreate();
	head = Transfer(head);
	head = SortWord(head);
	PrintList(head);
	return 0;
}