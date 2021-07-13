#pragma once
#include <iostream>
#include "merchandise_list.h"

using namespace std;

class User
{
public:
	// 构造函数，初始化⼀个User类的对象
	User(const char* user_name);

	// 成员函数，浏览商品(使⽤上⾯定义好的MerchandiseList类记录浏览情况)
	void BrowseMerchandise(Merchandise* merchandise);

	// 成员函数，返回浏览记录
	MerchandiseList* GetBrowseHistory();

	// 成员函数，购买商品(使⽤上⾯定义好的MerchandiseList类记录购买情况，number代表购买的数量)
	void BuyMerchandise(Merchandise* merchandise, int number);

	// 成员函数，返回购买记录
	MerchandiseList* GetBuyHistory();
public:
	char* users_name;
	MerchandiseList browse;
	MerchandiseList perchase;
};