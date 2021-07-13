#pragma once
#include "Polynomial.h"
#include <iostream>

using namespace std;

struct Node {
	int coef;
	int power;
	Node* m_pre, * m_next;
	Node(int _coef, int _power) {
		m_pre = nullptr;
		m_next = nullptr;
		coef = _coef;
		power = _power;
	}
};

class ListPoly : public Polynomial {
private:
	// 指向链表头的指针
	Node* head;
public:
	ListPoly();
	~ListPoly();
	ListPoly(ListPoly const& polynomial);
	ListPoly& operator = (const ListPoly& p);
	void addTerm(int coef, int power);
	void setIthCoe(int i, int coef);
	void setIthPow(int i, int power);
	int getIthCoe(int i);
	int getIthPow(int i);
	int getSize();
};