//��Ⱦɫ���жϸ�ͼ�е�ÿһ����ͨ�����Ƿ�Ϊ����ͼ�������Ƕ���ͼ�����yes����֮�����no
#include <iostream>

using namespace std;

struct Node//�ڽӱ���ṹ
{
	int id;
	Node* next;
	Node() { id = -1; next = NULL; }
};

int n, m;
int* parent;//���鼯�����
int* color;//�����ɫ
Node** adjoin;//�ڽӱ��ͷ����
int* queue;//bfs����
int head = 0, tail = 0;//��ͷָ�룬��βָ��

int Find(int x);//Ѱ�Ҹ����
void WeightedUnion(int root1, int root2);//�ϲ���������
bool adjoin_check(int a, int b);//�ж��������Ƿ�������
void push(int x);//ѹ�����
int pop();//��������
bool empty();//����Ϊ��

int main()
{
	cin >> n >> m;
	parent = new int[n];
	color = new int[n];
	adjoin = new Node * [m];
	queue = new int[100000];
	for (int i = 0; i < n; i++)//��ʼ�����鼯
		parent[i] = -1;
	for (int i = 0; i < n; i++)//��ʼ���������ɫΪ��
		color[i] = -1;
	for (int i = 0; i < n; i++)//��ʼ���ڽӱ��ͷ����
		adjoin[i] = new Node;
	int a = 0, b = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		Node* cur1 = adjoin[a];//д���ڽӱ�
		while (cur1->next != NULL)
			cur1 = cur1->next;
		Node* p1 = new Node;
		p1->id = b;
		cur1->next = p1;
		Node* cur2 = adjoin[b];
		while (cur2->next != NULL)
			cur2 = cur2->next;
		Node* p2 = new Node;
		p2->id = a;
		cur2->next = p2;
		a = Find(a);
		b = Find(b);
		if (a != b)
			WeightedUnion(a, b);//���鼯
	}
	for (int i = 0; i < n; i++)
	{
		if (parent[i] < 0)//�ж�ÿ����ͨ�����Ƿ�Ϊ����ͼ
		{
			head = 0;
			tail = 0;
			push(i);
			color[i] = 1;
			while (!empty())
			{
				int from = pop();
				for (int j = 0; j < n; j++)
				{
					if (color[j] == -1 && adjoin_check(from, j))
					{
						push(j);
						color[j] = !color[from];//�����ڽ��Ⱦ�ɲ�ͬ����ɫ   
					}
					if (color[from] == color[j] && adjoin_check(from, j))//�����ڽ����ɫ��ͬ�����Ƕ���ͼ   
					{
						cout << "No" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}

int Find(int x)//Ѱ�Ҹ����
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

void WeightedUnion(int root1, int root2)//�ϲ���������
{
	int temp = parent[root1] + parent[root2];
	if (parent[root1] < parent[root2])
	{
		parent[root2] = root1;
		parent[root1] = temp;
	}
	else
	{
		parent[root1] = root2;
		parent[root2] = temp;
	}
}

bool adjoin_check(int a, int b)//�Ƿ�Ϊ���ڽ��
{
	Node* p = adjoin[a];
	while (p->next != NULL)
	{
		if (p->id == b)
			return true;
		p = p->next;
	}
	return false;
}

void push(int x)//ѹ�����
{
	queue[tail] = x;
	tail++;
}

int pop()//��������
{
	int x = queue[head];
	head++;
	return x;
}

bool empty()//����Ϊ��
{
	if (head == tail)
		return true;
	else
		return false;
}