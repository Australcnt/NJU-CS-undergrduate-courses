#pragma once
#include "Vaccine.h"
#include "Mask.h"
#include <vector>
#include <algorithm>

template <class T>
class CombinedOrder
{
public:
	vector<T>orders;
public:
	CombinedOrder();
	bool AddOrder(T& order);
	int GetTotalCost();
	T& operator[](int index);
};

template <class T>
CombinedOrder<T>::CombinedOrder()
{
	;
}

template <class T>
bool CombinedOrder<T>::AddOrder(T& order)
{
	for (auto i = orders.begin(); i != orders.end(); i++)
	{
		if ((*i).name == order.name)
		{
			if (order.bound >= 0 && (*i).number + order.number <= order.bound)
			{
				(*i).number = (*i).number + order.number;
				return true;
			}
			else if (order.bound < 0)
			{
				(*i).number = (*i).number + order.number;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	if (order.bound >= 0 && order.number > order.bound)
		return false;
	orders.push_back(order);
	return true;
}

template <class T>
int CombinedOrder<T>::GetTotalCost()
{
	int totalcost = 0;
	for (auto i = orders.begin(); i != orders.end(); i++)
	{
		totalcost += (*i).price * (*i).number;
	}
	return totalcost;
}

template <class T>
T& CombinedOrder<T>::operator [] (int index)
{
	return orders[index];
}

template <class T>
bool IsLessThan(T t1, T t2)
{
	if (t1.price * t1.number < t2.price * t2.number)
		return true;
	else
		return false;
}
/*
template <class T>
bool sortFun(const T& t1, const T& t2)
{
	return t1.price * t1. number < t2.price* t2.number;
}*/

template <class T>
void SortOrder(CombinedOrder<T>& order)
{
	std::sort(order.orders.begin(), order.orders.end(), [](T t1, T t2) { return t1.price * t1.number < t2.price* t2.number; });
}
