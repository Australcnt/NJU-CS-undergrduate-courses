#pragma once
#include <iostream>
#include "merchandise.h"
using namespace std;


class MerchandiseList
{
public:
	struct Node
	{
		Merchandise* good;
		int value;
		Node* next;
		Node() { good = NULL; value = 0; next = NULL; }
	};
	Node* head;
public:
	// 构造函数，初始化⼀个MerchandiseList类的对象。
	MerchandiseList();

	// 成员函数，往MerchandiseList对象中增加⼀条记录(每条记录包括⼀个Merchandise指针，和⼀个数值)
	void AddRecord(Merchandise* merchandise, int value);

	// 成员函数，修改商品merchandise所在的那条记录中的value值为new_value，若商品不在列表中，不进⾏操作直接返回。
	void ModifyRecord(Merchandise* merchandise, int new_value);
	// 成员函数，查找merchandise所代表商品的记录，并返回这条记录中的value值(若未找到记录则返回 - 1)
	int FindRecord(Merchandise* merchandise);
	// 成员函数，删除merchandise所代表商品的记录，成功删除后返回true，如果不存在该记录，则不做操作并返回false
	bool DeleteRecord(Merchandise* merchandise);

	//Node* get_head() { return head; }
};