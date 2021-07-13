#pragma once
#include <iostream>

using namespace std;

class Polynomial {
public:
	int size;
public:
	// 增加⼀个系数为coef，指数为power的项
	// 若原有的多项式已有指数为power的项，则修改其系数为 new_coef = old_coef + coef，否则新增⼀个系数为coef，指数为power的项
	// 注意：若修改后的coef为0，则在多项式中应该删除这个项
	virtual void addTerm(int coef, int power) = 0;
	// 第i项表示实际存储的第i个单项式，i从0开始，测试样例给出的i不会越界
	// 设置第i项的系数
	virtual void setIthCoe(int i, int coef) = 0;
	// 设置第i项的指数
	virtual void setIthPow(int i, int power) = 0;
	// 获取第i项的系数
	virtual int getIthCoe(int i) = 0;
	// 获取第i项的指数
	virtual int getIthPow(int i) = 0;
	// 获取多项式长度
	virtual int getSize() = 0;
};