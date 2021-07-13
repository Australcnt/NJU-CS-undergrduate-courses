#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* parents;
};

    int n1 = 0, n2 = 0;
	Node* treestore1[1024] = { new Node }, * treestore2[1024] = { new Node };
	Node* tree1, * tree2;
	Node* queue1[1024], * queue2[1024];
	int head1 = 0, tail1 = 0;
	int head2 = 0, tail2 = 0;

	bool level_order();
	void push(Node* queue[], Node* p, int* tail);
	Node* pop(Node* queue[], int* head);

int main()
{
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		treestore1[i] = new Node;
		cin >> treestore1[i]->data;
	}
	cin >> n2;
	for (int i = 0; i < n1; i++)
	{
		treestore2[i] = new Node;
		cin >> treestore2[i]->data;
	}
	for (int i = 0; i < n1; i++)
	{
		if (treestore1[i]->data == -1)
		{
			treestore1[i] = NULL;
			continue;
		}
		if (i == 0)
			treestore1[i]->parents = NULL;
		else
			treestore1[i]->parents = treestore1[(i - 1) / 2];
		if (2 * i + 1 >= n1)
			treestore1[i]->left = NULL;
		else
			treestore1[i]->left = treestore1[2 * i + 1];
		if (2 * i + 2 >= n1)
			treestore1[i]->right = NULL;
		else
			treestore1[i]->right = treestore1[2 * i + 2];
	}
	for (int i = 0; i < n2; i++)
	{
		treestore2[i] = new Node;
		cin >> treestore2[i]->data;
		if (treestore2[i]->data == -1)
		{
			treestore2[i] = NULL;
			continue;
		}
		if (i == 0)
			treestore2[i]->parents = NULL;
		else
			treestore2[i]->parents = treestore2[(i - 1) / 2];
		if (2 * i + 1 >= n2)
			treestore2[i]->left = NULL;
		else
			treestore2[i]->left = treestore2[2 * i + 1];
		if (2 * i + 2 >= n2)
			treestore2[i]->right = NULL;
		else
			treestore2[i]->right = treestore2[2 * i + 2];
	}
	tree1 = treestore1[0], tree2 = treestore2[0];
	if (level_order())
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}

/*void CreateBinTree(Node*& p, int treestore[], int n, int pos)
{
	if (pos == n)
		return;
	p->parents = NULL;
	for (int i = 1; i < n; i++)
	{
		p->left=
	}
}*/

bool level_order()
{
	Node* current1 = tree1;
	Node* current2 = tree2;
	Node* p1 = current1;
	Node* p2 = current2;
	Node* temp = NULL;
	if (current2->left->data != current1->left->data)
	{
		temp = current2->left;
		current2->left = current2->right;
		current2->right = temp;
		if (current2->left->data != current1->left->data || current2->right->data != current1->right->data)
			return false;
	}
	push(queue1, current1, &tail1);
	push(queue2, current2, &tail2);
	while (head1 != tail1 && head2 != tail2)
	{
		current1 = pop(queue1, &head1);
		current2 = pop(queue2, &head2);
		if ((current2->left == NULL && current1 != NULL) || (current2->left != NULL && current1 == NULL) || (current2->left->data != current1->left->data))
		{
			temp = current2->left;
			current2->left = current2->right;
			current2->right = temp;
			if (((current2->left == NULL && current1->left != NULL) || (current2->left != NULL && current1->left == NULL) || (current2->left->data != current1->left->data)) || ((current2->right == NULL && current1->right != NULL) || (current2->right != NULL && current1->right == NULL) || (current2->right->data != current1->right->data)))
				return false;
		}
		push(queue1, current1->left, &tail1);
		push(queue2, current2->left, &tail2);
		push(queue1, current1->right, &tail1);
		push(queue2, current2->right, &tail2);
	}
	if ((tail1 - head1) != (tail2 - head2))
		return false;
	else
		return true;
}

void push(Node* queue[], Node* p, int* tail)
{
	queue[*tail] = p;
	*tail++;
}

Node* pop(Node* queue[], int* head)
{
	Node* p = queue[*head];
	*head++;
	return p;
}