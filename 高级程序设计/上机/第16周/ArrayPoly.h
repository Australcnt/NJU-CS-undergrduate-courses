#pragma once
#include "Polynomial.h"
#include <iostream>

using namespace std;

struct Item {// 多项式的单个项数据结构
	int coef;
	int power;
	Item() {}
	Item(int a, int b) { coef = a; power = b; }
};


class ArrayPoly : public Polynomial {
private:
	// 使⽤Item的数组实现，不允许使⽤stl中的模版实现
	Item* item_array;
public:
	ArrayPoly();
	ArrayPoly(ArrayPoly const& a);
	~ArrayPoly();
	ArrayPoly& operator = (const ArrayPoly& p);
	void addTerm(int coef, int power);
	void setIthCoe(int i, int coef);
	void setIthPow(int i, int power);
	int getIthCoe(int i);
	int getIthPow(int i);
	int getSize();
};