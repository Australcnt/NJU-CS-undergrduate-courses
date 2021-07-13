#include <iostream>

using namespace std;

struct Node
{
	int data;//结点权值
	int length;//当前结点的路径长度
	Node* leftchild;//左子树
	Node* rightchild;//右子树
};

int target_length;
int flag = 0;

void CreateBinTree(int pre_length, Node* &subtree);

int main()
{
	cin >> target_length;
	Node* subtree = NULL;
	CreateBinTree(0, subtree);
	if (flag)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}

void CreateBinTree(int pre_length, Node* &subtree)
{
	int data;
	cin >> data;
	if (data == -1)
		subtree = NULL;
	else
	{
		subtree = new Node;
		subtree->data = data;
		subtree->length = pre_length + data;//计算当前路径长度
		CreateBinTree(subtree->length, subtree->leftchild);
		CreateBinTree(subtree->length, subtree->rightchild);
		if (subtree->leftchild == NULL && subtree->rightchild == NULL && subtree->length == target_length)//判断叶节点路径长度是否与目标长度相同
			flag = 1;
	}
}