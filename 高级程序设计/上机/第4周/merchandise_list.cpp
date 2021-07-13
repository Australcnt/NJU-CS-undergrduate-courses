#include "merchandise.h"
#include "merchandise_list.h"
#include "user.h"

using namespace std;

MerchandiseList::MerchandiseList()
{
	head = NULL;
}

void MerchandiseList::AddRecord(Merchandise* merchandise, int value)
{
	Node* p = new Node;
	p->good = merchandise;
	p->value = value;
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		Node* q = head;
		if (q->next == NULL && strcmp(q->good->GetMerchandiseName(), p->good->GetMerchandiseName()) == 0)
		{
			q->value += p->value;
			return;
		}
		while (q->next != NULL)
		{
			if (strcmp(q->good->GetMerchandiseName(), p->good->GetMerchandiseName()) != 0)
				q = q->next;
			else
			{
				q->value += p->value;
				return;
			}
		}
		if(strcmp(q->good->GetMerchandiseName(), p->good->GetMerchandiseName()) == 0)
		{
			q->value += p->value;
			return;
		}
		q->next = p;
	}
}

void MerchandiseList::ModifyRecord(Merchandise* merchandise, int new_value)
{
	if (head == NULL)
		return;
	Node* p = head;
	//if (p->next == NULL && strcmp(p->good->GetMerchandiseName(), merchandise->GetMerchandiseName()) == 0)
	//	p->value = new_value;
	while (p != NULL)
	{
		if (strcmp(p->good->GetMerchandiseName(), merchandise->GetMerchandiseName()) == 0)
			p->value = new_value;
		p = p->next;
	}
}

int MerchandiseList::FindRecord(Merchandise* merchandise)
{
	if (head == NULL)
		return -1;
	Node* p = head;
	//if (p->next == NULL && strcmp(p->good->GetMerchandiseName(), merchandise->GetMerchandiseName()) == 0)
	//	return p->value;
	while (p != NULL)
	{
		if (strcmp(p->good->GetMerchandiseName(), merchandise->GetMerchandiseName()) == 0)
			return p->value;
		p = p->next;
	} 
	return -1;
}

bool MerchandiseList::DeleteRecord(Merchandise* merchandise)
{
	if (head == NULL)
		return false;
	Node* p = head;
	Node* pre = p;
	if (p->next == NULL && strcmp(p->good->GetMerchandiseName(), merchandise->GetMerchandiseName()) == 0)
	{
		delete p;
		head = NULL;
		return true;
	}
	while (p != NULL)
	{
		if (strcmp(p->good->GetMerchandiseName(), merchandise->GetMerchandiseName()) == 0)
		{
			pre->next = p->next;
			delete p;
			return true;
		}
		pre = p;
		p = p->next;
	}
	return false;
}
/*
int main()
{
	MerchandiseList merchandise_list; // 创建⼀个merchandise_list对象
	merchandise_list.AddRecord(&mer_pen, 8); // 在merchandise_list中添加⼀条记录(&mer_pen, 8)

	merchandise_list.ModifyRecord(&mer_pen, 7); // 修改merchandise_list中的项（& mer_pen, 8）为(&mer_pen, 7)

	merchandise_list.FindRecord(&mer_pen); // 查找&mer_pen所在的项，并返回7
	merchandise_list.DeleteRecord(&mer_pen); // 成功删除mer_pen，并返回true
	merchandise_list.DeleteRecord(&mer_apple); // 因为mer_apple不在merchandise_list中，删除失败并返回false
	return 0;
}*/