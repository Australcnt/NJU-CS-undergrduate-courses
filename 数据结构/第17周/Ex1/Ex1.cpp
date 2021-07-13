#include <iostream>

using namespace std;

struct Node
{
	int data;
	int height;
	int left_height;
	int right_height;
	Node* left;
	Node* right;
	Node() { height = 0; left_height = 0; right_height = 0; left = NULL; right = NULL; }
};

Node* root = NULL;
int num = 0;
int bf_max = -100000000;

int Insert(int data, Node*& p, Node*& pre);
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
	Node* head = new Node;
	head->height = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> data;
		if (root == NULL)
			Insert(data, root, head);
		else
		{
			int height = Insert(data, root, head);
			if (data < root->data && root->left_height < height)
				root->left_height = height;
			else if (data > root->data && root->right_height < height)
				root->right_height = height;
		}
	}
	bf_max_search(root);
	cout << bf_max << endl;
	return 0;
}

int Insert(int data, Node*& p, Node*& pre)
{
	if (p == NULL)
	{
		p = new Node;
		p->data = data;
		p->height = pre->height + 1;
		p->left_height = p->height;
		p->right_height = p->height;
		return p->height;
	}
	else
	{
		if (data < p->data)
		{
			int l_height = Insert(data, p->left, p);
			if (p->left_height < l_height)
				p->left_height = l_height;
			return l_height;
		}
		else if (data > p->data)
		{
			int r_height = Insert(data, p->right, p);
			if (p->right_height < r_height)
				p->right_height = r_height;
			return r_height;
		}
	}
}


void bf_max_search(Node* p)
{
	if (p != NULL)
	{
		if (p->right_height - p->left_height > bf_max)
			bf_max = p->right_height - p->left_height;
		if (p->left_height - p->right_height > bf_max)
			bf_max = p->left_height - p->right_height;
		bf_max_search(p->left);
		bf_max_search(p->right);
	}
}