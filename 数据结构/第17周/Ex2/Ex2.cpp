#include <iostream>

using namespace std;

struct Node
{
	int data;
	long long number;
	Node* left;
	Node* right;
	Node() { left = NULL; right = NULL; }
};

Node* root = NULL;
int num = 0;
int max_num = 0;

long long Insert(int data, Node*& p);
void bf_max_search(Node* p);

int main()
{
	int data = 0;
	cin >> num;
	if (num == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	for (int i = 0; i < num; i++)
	{
		cin >> data;
		int cur_num = Insert(data, root);
		if (cur_num > max_num)
			max_num = cur_num;
	}
	void bf_max_search(Node * p);
	cout << max_num << endl;
	return 0;
}

long long Insert(int data, Node*& p)
{
	if (p == NULL)
	{
		p = new Node;
		p->data = data;
		p->number = 1;
		return p->number;
	}
	else
	{
		int l_num = 0;
		int r_num = 0;
		if (data < p->data)
		{
			l_num = Insert(data, p->left);

		}
		else if (data > p->data)
		{
			r_num = Insert(data, p->right);
		}
		long long cur_num = 1;
		for (int i = l_num + r_num; i > l_num; i--)
			cur_num = cur_num * i;
		for (int i = 1; i <= l_num; i++)
			cur_num = cur_num / i;
		p->number = cur_num;
		return cur_num;
	}
}

void bf_max_search(Node* p)
{
	if (p != NULL)
	{
		if (p->number > max_num)
			max_num = p->number;
		bf_max_search(p->left);
		bf_max_search(p->right);
	}
}