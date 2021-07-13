#include "ListPoly.h"

ListPoly::ListPoly()
{
	head = NULL;
	size = 0;
}

ListPoly::~ListPoly()
{
	while(head)
	{
		Node* p = head;
		head = head->m_next;
		delete[]p;
	}
	size = 0;
}

ListPoly::ListPoly(ListPoly const& polynomial)
{
	head = NULL;
	size = 0;
	Node* p1 = head;
	Node* p2 = polynomial.head;
	Node* pre = NULL;
	Node* next = new Node(0, 0);
	
	for (int i = 0; i < polynomial.size; i++)
	{
		if (i == 0)
		{
			p1 = new Node(p2->coef, p2->power);
			head = p1;
		}
		else
		{
			p1->coef = p2->coef;
			p1->power = p2->power;
		}
		p1->m_pre = pre;
		p1->m_next = next;
		pre = p1;
		p1 = next;
		next = new Node(0, 0);
		if (i == polynomial.size - 1)
			p1->m_next == NULL;
		p2 = p2->m_next;
	}
	size = polynomial.size;
}

ListPoly& ListPoly::operator = (const ListPoly& p)
{
	while (head)
	{
		Node* p = head;
		head = head->m_next;
		delete[]p;
	}
	size = 0;
	Node* p1 = head;
	Node* p2 = p.head;
	Node* pre = NULL;
	Node* next = new Node(0, 0);

	for (int i = 0; i < p.size; i++)
	{
		if (i == 0)
		{
			p1 = new Node(p2->coef, p2->power);
			head = p1;
		}
		else
		{
			p1->coef = p2->coef;
			p1->power = p2->power;
		}
		p1->m_pre = pre;
		p1->m_next = next;
		pre = p1;
		p1 = next;
		next = new Node(0, 0);
		if (i == p.size - 1)
			p1->m_next == NULL;
		p2 = p2->m_next;
	}
	size = p.size;
	return *this;
}

void ListPoly::addTerm(int coef, int power)
{
	Node* p = head;
	while(p)
	{
		if (p->power == power)
		{
			p->coef += coef;
			if (p->coef == 0)
			{
				Node* cur = p;
				if (p->m_pre != NULL)
					p->m_pre->m_next = p->m_next;
				if (p->m_next != NULL)
					p->m_next->m_pre = p->m_pre;
				delete[]cur;
				size--;
			}
			return;
		}
		p = p->m_next;
	}
	p = head;
	if (size == 0)
	{
		p = new Node(coef, power);
		head = p;
	}
	else
	{
		while (p->m_next)
		{
			p = p->m_next;
		}
		Node* q = new Node(coef, power);
		p->m_next = q;
		q->m_pre = p;
		q->m_next = NULL;
	}
	size++;
}

void ListPoly::setIthCoe(int i, int coef)
{
	Node* p = head;
	for (int j = 0; j < i; j++)
	{
		p = p->m_next;
	}
	p->coef += coef;
	if (p->coef == 0)
	{
		Node* cur = p;
		if (p->m_pre != NULL)
			p->m_pre->m_next = p->m_next;
		if (p->m_next != NULL)
			p->m_next->m_pre = p->m_pre;
		delete[]cur;
		size--;
	}
}

void ListPoly::setIthPow(int i, int power)
{
	Node* p = head;
	for (int j = 0; j < i; j++)
	{
		p = p->m_next;
	}
	p->power = power;
}

int ListPoly::getIthCoe(int i)
{
	Node* p = head;
	for (int j = 0; j < i; j++)
	{
		p = p->m_next;
	}
	return p->coef;
}

int ListPoly::getIthPow(int i)
{
	Node* p = head;
	for (int j = 0; j < i; j++)
	{
		p = p->m_next;
	}
	return p->power;
}

int ListPoly::getSize()
{
	return size;
}