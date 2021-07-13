#include <iostream>
#include <math.h>

using namespace std;

struct Node
{
	int x;
	int y;
	int min_intercept;
	Node* next;
	Node() { x = -1; y = -1; min_intercept = INT32_MAX; next = NULL; }
};

int row, col;//����������
int map[100][100];//���θ߶�
int dist[100][100];//�������
bool visit[100][100];//�Ƿ���ʹ�
Node* priority_queue = new Node;//���ȼ�����
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

Node* pop();//�������ȼ�����
void push(Node* p);//ѹ�����ȼ�����
bool empty();//����Ϊ��
int max(int a, int b);//�ϴ���

int main()
{
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)//���θ߶ȳ�ʼ��
			cin >> map[i][j];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)//��������ʼ��
			dist[i][j] = INT32_MAX;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)//���ʳ�ʼ��
			visit[i][j] = false;
	dist[0][0] = 0;//����ʼ��
	Node* p = new Node;
	p->x = 0;
	p->y = 0;
	p->min_intercept = 0;
	push(p);
	while (!empty())//Dijkstra�㷨������С�������·��
	{
		Node* top = pop();
		int x = top->x;
		int y = top->y;
		int min_intercept = top->min_intercept;
		if (visit[y][x])
			continue;
		visit[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 0 || next_x > col - 1 || next_y < 0 || next_y > row - 1)
				continue;
			int next_min_intercept = max(min_intercept, abs(map[y][x] - map[next_y][next_x]));//����ý��ĵ������
			if (dist[next_y][next_x] > next_min_intercept)
			{
				dist[next_y][next_x] = next_min_intercept;
				p = new Node;
				p->x = next_x;
				p->y = next_y;
				p->min_intercept = next_min_intercept;
				push(p);
			}
		}
	}
	cout << dist[row - 1][col - 1] << endl;
	return 0;
}

Node* pop()//�������ȼ�����
{
	Node* p = priority_queue->next;
	priority_queue->next = priority_queue->next->next;
	return p;
}

void push(Node* p)//ѹ�����ȼ�����
{
	Node* pre = priority_queue;
	Node* cur = priority_queue->next;
	while (cur != NULL && p->min_intercept > cur->min_intercept)
	{
		pre = pre->next;
		cur = cur->next;
	}
	p->next = cur;
	pre->next = p;
}

bool empty()//����Ϊ��
{
	if (priority_queue->next == NULL)
		return true;
	else
		return false;
}

int max(int a, int b)//�ϴ���
{
	if (a < b)
		a = b;
	return a;
}