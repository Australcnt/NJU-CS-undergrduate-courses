#include <iostream>
using namespace std;
struct Node
{
	char a;
	Node *next;
};
Node *AppCreate(char str[])
{
	Node *head = NULL, *tail = NULL;
	for (int i = 0; str[i] != '\0';i++)
	{
		Node *p = new Node;
		p->a = str[i];
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		if (str[i + 1] == '\0')
		{
			Node *p = new Node;
			p->a = str[i+1];
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
void Output(Node *head)
{
	if (head == NULL)
		cout << endl;
	else 
		for (int k = 0; head->a != '\0'; k++)
	{
		cout << head->a;
		head = head->next;
		if (head->a == '\0')
			cout << head->a << endl;
	}
}
void Length(Node *head)
{
	if (head == NULL)
		cout << 0 << endl;
	else
		for (int j = 0; head->a != '\0';j++)
	{
		head = head->next;
		if (head->a == '\0')
			cout << j + 1 << endl;
	}
}
int main()
{
	char str[10000];
	cin.getline(str, 10000);
	Node *head = AppCreate(str);
	Output(head);
	Length(head);
	return 0;
}