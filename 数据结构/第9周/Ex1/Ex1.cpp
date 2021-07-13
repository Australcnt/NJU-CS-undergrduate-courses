#include <iostream>

using namespace std;

struct Node
{
	int data;//���Ȩֵ
	int length;//��ǰ����·������
	Node* leftchild;//������
	Node* rightchild;//������
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
		subtree->length = pre_length + data;//���㵱ǰ·������
		CreateBinTree(subtree->length, subtree->leftchild);
		CreateBinTree(subtree->length, subtree->rightchild);
		if (subtree->leftchild == NULL && subtree->rightchild == NULL && subtree->length == target_length)//�ж�Ҷ�ڵ�·�������Ƿ���Ŀ�곤����ͬ
			flag = 1;
	}
}