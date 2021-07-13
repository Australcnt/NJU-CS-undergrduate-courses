#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
	double score;//���ն�
    double average;//ƽ�����ն�
	int number;//��ǰ����µĽ����Ŀ
	Node* left;//����
	Node* right;//�Һ���
	
};

Node** node_queue = new Node * [10000];//������
int front = 0, rear = 0;//����ͷβָ��
double average_max = 0;//���ƽ�����ն�

void CreateBinTree(Node* root);//���ݲ�����д���������
void push(Node* cur);//ѹ�����
Node* pop();//��������
double average_calculate(Node* p);//���㵱ǰ����ƽ�����ն�

int main()
{
	Node* root = new Node;
	CreateBinTree(root);//���ݲ�����д���������
	average_calculate(root);//���㵱ǰ����ƽ�����ն�
	cout << fixed << setprecision(5) << average_max << endl;
	return 0;
}

void CreateBinTree(Node* root)//���ݲ�����д���������
{
	cin >> root->score;
	Node* cur = new Node;//��ǰ���ָ��
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

void push(Node* cur)//ѹ�����
{
	node_queue[rear] = cur;
	rear++;
}

Node* pop()//��������
{
	Node* temp = node_queue[front];
	front++;
	return temp;
}

double average_calculate(Node* p)//���㵱ǰ����ƽ�����ն�
{
	if (p == NULL)//�ݹ��������
		return 0;
	double left_average = 0, right_average = 0;
	int left_number = 0, right_number = 0;//���������Ľ����Ŀ
	left_average = average_calculate(p->left);//�������ӵ�ƽ�����ն�
	right_average = average_calculate(p->right);//�����Һ��ӵ�ƽ�����ն�
	if (p->left == NULL)
		left_number = 0;
	else
		left_number = p->left->number;
	if (p->right == NULL)
		right_number = 0;
	else
		right_number = p->right->number;
	p->number = left_number + right_number + 1;//��ǰ����µĽ����Ŀ
	p->average = (left_number * left_average + right_number * right_average + p->score) / p->number;//��ǰ����ƽ�����ն�
	if (p->average > average_max)//�������ƽ�����ն�
		average_max = p->average;
	return p->average;
}