#include <iostream>
using namespace std;

struct Node//�����Ϣ
{
	int data;//����
	Node* left;//����
	Node* right;//�Һ���
};

Node** node_store = new Node * [1000];//���ָ��洢
int max_flag = 1;//���ѱ�־λ
int min_flag = 1;//��С�ѱ�־λ
Node* path[1000];//·��ջ
int length = -1;//·������

void heap_judge(Node* parents, Node* child);//�������ж�
void path_search(Node* p);//·������
void path_output();//·�����
void push(Node* p);//ѹ��·��ջ
void pop();//����·��ջ

int main()
{
	int n = 0;
	cin >> n;//�����Ŀ
	for (int i = 0; i < n; i++)//������ȫ������
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
	heap_judge(NULL, node_store[0]);//�������ж�
	path_search(node_store[0]);//·������
	if (max_flag)
		cout << "Max Heap" << endl;
	else if (min_flag)
		cout << "Min Heap" << endl;
	else
		cout << "Not Heap" << endl;
	return 0;
}

void heap_judge(Node* parents, Node* child)//�������ж�
{
	if (child == NULL)//�ݹ��������
		return;
	if (parents != NULL)
	{
		if (parents->data < child->data)//�Ƿ�Ϊ����
			max_flag = 0;
		else if (parents->data > child->data)//�Ƿ�Ϊ��С��
			min_flag = 0;
	}
	heap_judge(child, child->left);//�ݹ�
	heap_judge(child, child->right);//�ݹ�
}

void path_search(Node* p)//·������
{
	if (p == NULL)//�ݹ��������
		return;
	else
	{
		push(p);//ѹ��·��ջ
		if (p->left == NULL && p->right == NULL)//��ΪҶ�ڵ㣬�������ǰ·��
			path_output();
		path_search(p->right);//�ݹ�����
		path_search(p->left);//�ݹ�����
		pop();//����·��ջ
	}
}

void path_output()//·�����
{
	for (int i = 0; i <= length; i++)
		cout << path[i]->data << " ";
	cout << endl;
}

void push(Node* p)//ѹ��·��ջ
{
	path[length + 1] = p;
	length++;
}

void pop()//����·��ջ
{
	length--;
}