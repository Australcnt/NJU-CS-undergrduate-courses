#include <iostream>
using namespace std;

struct Node//结点信息
{
	int data;//数据
	Node* left;//左孩子
	Node* right;//右孩子
};

Node** node_store = new Node * [1000];//结点指针存储
int max_flag = 1;//最大堆标志位
int min_flag = 1;//最小堆标志位
Node* path[1000];//路径栈
int length = -1;//路径长度

void heap_judge(Node* parents, Node* child);//堆类型判断
void path_search(Node* p);//路径搜索
void path_output();//路径输出
void push(Node* p);//压入路径栈
void pop();//弹出路径栈

int main()
{
	int n = 0;
	cin >> n;//结点数目
	for (int i = 0; i < n; i++)//创建完全二叉树
	{
		node_store[i] = new Node;
		cin >> node_store[i]->data;
		node_store[i]->left = NULL;
		node_store[i]->right = NULL;
		if (i != 0)
		{
			if (i % 2 == 1)
				node_store[(i - 1) / 2]->left = node_store[i];
			else
				node_store[(i - 1) / 2]->right = node_store[i];
		}
	}
	heap_judge(NULL, node_store[0]);//堆类型判断
	path_search(node_store[0]);//路径搜索
	if (max_flag)
		cout << "Max Heap" << endl;
	else if (min_flag)
		cout << "Min Heap" << endl;
	else
		cout << "Not Heap" << endl;
	return 0;
}

void heap_judge(Node* parents, Node* child)//堆类型判断
{
	if (child == NULL)//递归结束条件
		return;
	if (parents != NULL)
	{
		if (parents->data < child->data)//是否为最大堆
			max_flag = 0;
		else if (parents->data > child->data)//是否为最小堆
			min_flag = 0;
	}
	heap_judge(child, child->left);//递归
	heap_judge(child, child->right);//递归
}

void path_search(Node* p)//路径搜索
{
	if (p == NULL)//递归结束条件
		return;
	else
	{
		push(p);//压入路径栈
		if (p->left == NULL && p->right == NULL)//若为叶节点，则输出当前路径
			path_output();
		path_search(p->right);//递归搜索
		path_search(p->left);//递归搜索
		pop();//弹出路径栈
	}
}

void path_output()//路径输出
{
	for (int i = 0; i <= length; i++)
		cout << path[i]->data << " ";
	cout << endl;
}

void push(Node* p)//压入路径栈
{
	path[length + 1] = p;
	length++;
}

void pop()//弹出路径栈
{
	length--;
}