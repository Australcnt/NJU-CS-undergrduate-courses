#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
	int height;
	int left_height;
	int right_height;
};

int n;
vector<int>preorder;
vector<int>inorder;
int cur_root = 0;
int tree_height = 0;
int tree_diameter = 0;

Node* CreateTree(int l, int r, int height);
void Traversal(Node* p);

int main()
{
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		preorder.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		inorder.push_back(x);
	}
	Node* root = CreateTree(0, n - 1, 0);
	Traversal(root);
	cout << tree_height << endl;
	cout << tree_diameter << endl;
	return 0;
}

Node* CreateTree(int l, int r, int height)
{
	if (l > r)
		return NULL;
	Node* p = NULL;
	for (int i = l; i <= r; i++)
	{
		if (inorder[i] == preorder[cur_root])
		{
			p = new Node;
			p->value = preorder[cur_root];
			cur_root++;
			p->height = height;
			p->left = CreateTree(l, i - 1, height + 1);// 左半边元素生成左子树
			p->right = CreateTree(i + 1, r, height + 1);// 右半边元素生成右子树
			if (p->left == NULL)
				p->left_height = 0;
			else
			{
				if (p->left->left_height < p->left->right_height)
					p->left_height = p->left->right_height + 1;
				else
					p->left_height = p->left->left_height + 1;
			}
			if (p->right == NULL)
				p->right_height = 0;
			else
			{
				if (p->right->left_height < p->right->right_height)
					p->right_height = p->right->right_height + 1;
				else
					p->right_height = p->right->left_height + 1;
			}
			break;
		}
	}
	return p;
}

void Traversal(Node* p)
{
	if (p == NULL)
		return;
	if (p->height > tree_height)
		tree_height = p->height;
	if (p->left_height + p->right_height > tree_diameter)
		tree_diameter = p->left_height + p->right_height;
	Traversal(p->left);
	Traversal(p->right);
}