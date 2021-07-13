#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Merchandise
{
public:
	// 构造函数，初始化⼀个Merchandise类的对象
	Merchandise(const char* name, int price);

	// 成员函数，返回商品名
	const char* GetMerchandiseName();
	// 成员函数，返回商品价格
	int GetMerchandisePrice();
private:
	char* good_name;
	int good_price;
};