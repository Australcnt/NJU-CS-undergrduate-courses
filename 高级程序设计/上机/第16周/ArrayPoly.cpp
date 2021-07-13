#include "ArrayPoly.h"

ArrayPoly::ArrayPoly()
{
	item_array = NULL;
	size = 0;
}

ArrayPoly::ArrayPoly(ArrayPoly const& a)
{
	item_array = NULL;
	item_array = new Item[a.size];
	size = a.size;
	for (int i = 0; i < a.size; i++)
	{
		item_array[i].coef = a.item_array[i].coef;
		item_array[i].power = a.item_array[i].power;
	}
}

ArrayPoly::~ArrayPoly()
{
	delete[]item_array;
	size = 0;
}

ArrayPoly& ArrayPoly::operator = (const ArrayPoly& p)
{
	delete[]item_array;
	item_array = NULL;
	item_array = new Item[p.size];
	size = p.size;
	for (int i = 0; i < p.size; i++)
	{
		item_array[i].coef = p.item_array[i].coef;
		item_array[i].power = p.item_array[i].power;
	}
	return *this;
}

void ArrayPoly::addTerm(int coef, int power)
{
	for (int i = 0; i < size; i++)
	{
		if (item_array[i].power == power)
		{
			item_array[i].coef += coef;
			if (item_array[i].coef == 0)
			{
				for (int j = i; j < size - 1; j++)
				{
					item_array[j] = item_array[j + 1];
				}
				item_array[size].coef = 0;
				item_array[size].power = 0;
				size--;
			}
			return;
		}
	}
	Item* item_array2 = new Item[size + 1];
	for (int i = 0; i < size; i++)
	{
		item_array2[i] = item_array[i];
	}
	item_array2[size].coef = coef;
	item_array2[size].power = power;
	size++;
	delete[]item_array;
	item_array = item_array2;
}

void ArrayPoly::setIthCoe(int i, int coef)
{
	item_array[i].coef = coef;
	if (coef == 0)
	{
		for (int j = i; j < size - 1; j++)
		{
			item_array[j] = item_array[j + 1];
		}
		item_array[size].coef = 0;
		item_array[size].power = 0;
		size--;
	}
}

void ArrayPoly::setIthPow(int i, int power)
{
	/*for (int k = 0; k < size; k++)
	{
		if (item_array[k].power == power)
		{
			item_array[k].coef += item_array[i].coef;
			for (int j = i; j < size - 1; j++)
			{
				item_array[j] = item_array[j + 1];
			}
			item_array[size].coef = 0;
			item_array[size].power = 0;
			size--;
			if (k > i)
				k--;
			if (item_array[k].coef == 0)
			{
				for (int m = k; m < size - 1; m++)
				{
					item_array[m] = item_array[m + 1];
				}
				item_array[size].coef = 0;
				item_array[size].power = 0;
				size--;
			}
		}
		return;
	}*/
	item_array[i].power = power;
}

int ArrayPoly::getIthCoe(int i)
{
	return item_array[i].coef;
}

int ArrayPoly::getIthPow(int i)
{
	return item_array[i].power;
}

int ArrayPoly::getSize()
{
	return size;
}