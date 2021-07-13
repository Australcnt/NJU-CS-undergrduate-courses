#include <iostream>

using namespace std;

struct Node
{
	int id;//结点编号
	Node* parents;//双亲结点
	Node* left;//左孩子
	Node* right;//右孩子
	int depth;//当前结点层数
};

int front = 0, rear = 0;//队列头尾指针

void push(Node** queue, Node* cur);//压入队列
Node* pop(Node** queue);//弹出队列

int main()
{
	int id_p, id_q;//两个人的id
	cin >> id_p >> id_q;
	Node* p = NULL, * q = NULL;//两个人的结点指针
	int n;//结点数目（包括空结点）
	cin >> n;
	int* node_array = new int[n];//结点存储
	for (int i = 0; i < n; i++)
		cin >> node_array[i];
	Node **node_queue = new Node*[1024];//结点队列
	int index = 0;//结点下标
	Node* cur = new Node;//当前结点指针
	cur->id = node_array[index];
	cur->parents = NULL;
	cur->depth = 1;
	if (cur->id == id_p)//是否为p或q
		p = cur;
	else if (cur->id == id_q)
		q = cur;
	push(node_queue, cur);
	//根据层次序列创建二叉树
	while (front != rear)
	{
		cur = pop(node_queue);
		index++;
		if (index >= n - 1 || node_array[index] == -1)
			cur->left = NULL;
		else
		{
			cur->left = new Node;
			cur->left->id = node_array[index];
			cur->left->parents = cur;
			cur->left->depth = cur->depth + 1;
			if (cur->left->id == id_p)//是否为p或q
				p = cur->left;
			else if (cur->left->id == id_q)
				q = cur->left;
			push(node_queue, cur->left);
		}
		index++;
		if (index >= n - 1 || node_array[index] == -1)
			cur->right = NULL;
		else
		{
			cur->right = new Node;
			cur->right->id = node_array[index];
			cur->right->parents = cur;
			cur->right->depth = cur->depth + 1;
			if (cur->right->id == id_p)//是否为p或q
				p = cur->right;
			else if (cur->right->id == id_q)
				q = cur->right;
			push(node_queue, cur->right);
		}
	}
	while (p->id != q->id)//寻找共同祖先
	{
		if (p->depth > q->depth)
			p = p->parents;
		else if (p->depth < q->depth)
			q = q->parents;
		else if(p->id != q->id)
		{
			p = p->parents;
			q = q->parents;
		}
	}
	cout << p->id << endl;//输出共同祖先
	return 0;
}

void push(Node** queue, Node* cur)//压入队列
{
	queue[rear] = cur;
	rear++;
}

Node* pop(Node**queue)//弹出队列
{
	Node* temp = queue[front];
	front++;
	return temp;
}