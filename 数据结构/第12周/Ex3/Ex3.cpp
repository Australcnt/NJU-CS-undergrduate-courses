#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

struct Node
{
	double d;
	Node* next;
};

int main()
{
	int m;
	cin >> m;
	int n = 0;
	double x = 0, y = 0, z = 0;
	Node* head = new Node;
	head->d = -1;
	head->next = NULL;
	Node* tail = NULL;
	Node* p;
	for (int i = 0; i < m; i++)
	{
		char choice;
		scanf("%d", &choice);
		if (choice == 'A')
		{
			scanf("%f",&x);
			scanf("%f", &y);
			scanf("%f", &z);
			p = new Node;
			p->d = sqrt(x * x + y * y + z * z);
			
			if (head->next == NULL)
			{
				head->next = p;
				p->next = NULL;
			}
			else
			{
				Node* cur = head->next, *pre = head;
				while (cur != NULL && cur->d < p->d)
				{
					cur = cur->next;
					pre = pre->next;
				}
				p->next = cur;
				pre->next = p;
			}
		}
		else
		{
			scanf("%d", &n);
			double sum = 0;
			double count = 0;
			Node* cur = head->next;
			for (int j = 0; j < n; j++)
			{
				sum = sum + cur->d;
				count++;
				cur = cur->next;
			}
			head->next = cur;
			double average = 0;
			average = sum / count;
			printf("%.5f\n", average);
		}
	}
	return 0;
}