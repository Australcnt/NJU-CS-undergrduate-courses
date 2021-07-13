#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
	double score;//掌握度
    double average;//平均掌握度
	int number;//当前结点下的结点数目
	Node* left;//左孩子
	Node* right;//右孩子
	
};

Node** node_queue = new Node * [10000];//结点队列
int front = 0, rear = 0;//队列头尾指针
double average_max = 0;//最大平均掌握度

void CreateBinTree(Node* root);//根据层次序列创建二叉树
void push(Node* cur);//压入队列
Node* pop();//弹出队列
double average_calculate(Node* p);//结算当前结点的平均掌握度

int main()
{
	Node* root = new Node;
	CreateBinTree(root);//根据层次序列创建二叉树
	average_calculate(root);//计算当前结点的平均掌握度
	cout << fixed << setprecision(5) << average_max << endl;
	return 0;
}

void CreateBinTree(Node* root)//根据层次序列创建二叉树
{
	cin >> root->score;
	Node* cur = new Node;//当前结点指针
	cur = root;
	push(cur);
	while (front != rear)
	{
		cur = pop();
		int left_score = 0, right_score = 0;
		cin >> left_score;
		if (left_score == -1)
			cur->left = NULL;
		else
		{
			cur->left = new Node;
			cur->left->score = left_score;
			push(cur->left);
		}
		cin >> right_score;
		if (right_score == -1)
			cur->right = NULL;
		else
		{
			cur->right = new Node;
			cur->right->score = right_score;
			push(cur->right);
		}
	}
}

void push(Node* cur)//压入队列
{
	node_queue[rear] = cur;
	rear++;
}

Node* pop()//弹出队列
{
	Node* temp = node_queue[front];
	front++;
	return temp;
}

double average_calculate(Node* p)//计算当前结点的平均掌握度
{
	if (p == NULL)//递归结束条件
		return 0;
	double left_average = 0, right_average = 0;
	int left_number = 0, right_number = 0;//左右子树的结点数目
	left_average = average_calculate(p->left);//计算左孩子的平均掌握度
	right_average = average_calculate(p->right);//计算右孩子的平均掌握度
	if (p->left == NULL)
		left_number = 0;
	else
		left_number = p->left->number;
	if (p->right == NULL)
		right_number = 0;
	else
		right_number = p->right->number;
	p->number = left_number + right_number + 1;//当前结点下的结点数目
	p->average = (left_number * left_average + right_number * right_average + p->score) / p->number;//当前结点的平均掌握度
	if (p->average > average_max)//更新最大平均掌握度
		average_max = p->average;
	return p->average;
}