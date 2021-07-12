#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* r;
	Node* l;
};
int a = 0;
Node* insert(Node* T, int x);
void postorder(Node* T);
int main()
{
	int n;
	cin >> n;
	Node* T = new Node;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		T = insert(T, x);
	}
	postorder(T);
	return 0;
}
Node* insert(Node* T, int x)
{
	if (!a)
	{
		T->data = x;
		T->r = NULL;
		T->l = NULL;
		a++;
	}
	else
	{
		Node* T2 = T;
		while ((x < T2->data && T2->l) || (x > T2->data && T2->r))
		{
			if (x < T2->data)
				T2 = T2->l;
			else 
				T2 = T2->r;
		}
		Node* p = new Node;
		p->data = x;
		p->r = NULL;
		p->l = NULL;
		if (x < T2->data)
			T2->l = p;
		if (x > T2->data)
			T2->r = p;
	}
	return T;
}
void postorder(Node* T)
{
	while(T->l||T->r)
	{
		Node* T2 = T;
		while (T2->l || T2->r)
		{
			if (T2->l)
			{
				if (T2->l->l || T2->l->r)
					T2 = T2->l;
				else
				{
					cout << T2->l->data << ' ';
					Node* cur = T2->l;
					T2->l = NULL;
					delete(cur);
				}
			}
			else 
			{
				if (T2->r->l || T2->r->r)
					T2 = T2->r;
				else
				{
					cout << T2->r->data << ' ';
					Node* cur = T2->r;
					T2->r = NULL;
					delete(cur);
				}
			}
		}
}
	cout << T->data << endl;
}
