#include <iostream>
using namespace std;
struct Node
{
	char a;
	Node *next;
};
Node *AppCreate()
{
	Node *head = NULL, *tail = NULL;
	char a;
	while ((a=getchar())!='\n')
	{
		Node *p = new Node;
		p->a = a;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	return head;
}
const Node *findFirstCross(const Node *headA, const Node *headB)
{
	const Node *fakeheadA = headA;
	const Node *fakeheadB = headB;
	while (fakeheadA)
	{
		while (fakeheadB)
		{
			if (fakeheadA == fakeheadB)
				return fakeheadA;
			fakeheadB = fakeheadB->next;
		}
		fakeheadA = fakeheadA->next;
		fakeheadB = headB;
	}
	return NULL;
}
int main()
{
	Node *A = AppCreate();
	Node *B = AppCreate();
	Node *C = AppCreate();
	Node *pA = A;
	if (pA)
	{
		while (pA->next)
			pA = pA->next;
		pA->next = C;
	}
	else
		pA = C;
	Node *pB = B;
	if (pB)
	{
		while (pB->next)
			pB = pB->next;
		pB->next = C;
	}
	else
		pB = C;
	const Node *p = findFirstCross(A, B);
	if (p)
		cout << "首个重合节点是：" << (p->a) << endl;
	else
		cout << "无重合节点" << endl;
	return 0;
}