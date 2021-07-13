#include <iostream>

using namespace std;

struct Node
{
	int id;//�����
	Node* parents;//˫�׽��
	Node* left;//����
	Node* right;//�Һ���
	int depth;//��ǰ������
};

int front = 0, rear = 0;//����ͷβָ��

void push(Node** queue, Node* cur);//ѹ�����
Node* pop(Node** queue);//��������

int main()
{
	int id_p, id_q;//�����˵�id
	cin >> id_p >> id_q;
	Node* p = NULL, * q = NULL;//�����˵Ľ��ָ��
	int n;//�����Ŀ�������ս�㣩
	cin >> n;
	int* node_array = new int[n];//���洢
	for (int i = 0; i < n; i++)
		cin >> node_array[i];
	Node **node_queue = new Node*[1024];//������
	int index = 0;//����±�
	Node* cur = new Node;//��ǰ���ָ��
	cur->id = node_array[index];
	cur->parents = NULL;
	cur->depth = 1;
	if (cur->id == id_p)//�Ƿ�Ϊp��q
		p = cur;
	else if (cur->id == id_q)
		q = cur;
	push(node_queue, cur);
	//���ݲ�����д���������
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
			if (cur->left->id == id_p)//�Ƿ�Ϊp��q
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
			if (cur->right->id == id_p)//�Ƿ�Ϊp��q
				p = cur->right;
			else if (cur->right->id == id_q)
				q = cur->right;
			push(node_queue, cur->right);
		}
	}
	while (p->id != q->id)//Ѱ�ҹ�ͬ����
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
	cout << p->id << endl;//�����ͬ����
	return 0;
}

void push(Node** queue, Node* cur)//ѹ�����
{
	queue[rear] = cur;
	rear++;
}

Node* pop(Node**queue)//��������
{
	Node* temp = queue[front];
	front++;
	return temp;
}