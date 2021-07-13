#include <iostream>

using namespace std;

const int NUM = 32;

class A
{
public:
	static void* operator new(size_t size);
	static void operator delete(void* p);
private:
	static A* p_free;
	A* next;
};

struct Head
{
	A* head;
	Head* next;
};

A* A::p_free = NULL;
Head* q = NULL;

void* A::operator new(size_t size)
{
	A* p;
	if (p_free == NULL)
	{
		p_free = (A*)malloc(size * (NUM + 1));
		if (q == NULL)
		{
			q = new Head;
			q->head = p_free;
			q->next = NULL;
		}
		else
		{
			Head* r = q;
			while (r->next != NULL)
				r = r->next;
			r->next = new Head;
			r->next->head;
			r->next->next = NULL;
		}
		p_free++;
		for (p = p_free; p != p_free + NUM - 1; p++)
			p->next = p + 1;
		p->next = NULL;
	}
	p = p_free;
	p_free = p_free->next;
	memset(p, 0, size);
	return p;
}

void A::operator delete(void* p)
{
	((A*)p)->next = p_free;
	p_free = (A*)p;
}

void delete_myheap()
{
	Head* p = q;
	Head* pre = p;
	while (p != NULL)
	{
		delete[]p->head;
		pre = p;
		p = p->next;
		delete pre;
	}
}