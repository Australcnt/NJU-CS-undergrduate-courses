#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
	int id;
	int cost;
	Node* next;
	Node() { id = 0; cost = 1000000; next = NULL; }
};

int m, n;//�ȼ�������ƣ���Ʒ����
int value[101] = { 0 };//��Ʒ�۸�
int level[101] = { 0 };//��Ʒ�ȼ�
int in_degree[101] = { 0 };//���滻��Ʒ��
int exchange_cost[101][101];//�滻�۸�
bool allow[101] = { false };//�ȼ�Լ��
int min_cost = 0;//��С����
int dist[101];//��������Ʒ��С
bool visit[101] = { false };//�Ƿ���ʹ�
Node* priority_queue = new Node;//���ȼ�����


void dijkstra(int x);
void push(Node* p);//ѹ�����ȼ�����
Node* pop();//�������ȼ�����
bool empty();//����Ϊ��

int main()
{
	cin >> m >> n;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			exchange_cost[i][j] = 1000000;//��ʼ��
	for (int i = 1; i <= n; i++)
		dist[i] = 1000000;//��ʼ��
	for (int i = 1; i <= n; i++)
	{
		cin >> value[i];
		cin >> level[i];
		cin >> in_degree[i];
		for (int j = 1; j <= in_degree[i]; j++)
		{
			int id = 0, cost = 0;
			cin >> id >> cost;
			exchange_cost[id][i] = cost;
		}
	}
	min_cost = value[1];
	int level_low = 0, level_high = 0;
	for (int i = 0; i <= m; i++)
	{
		level_low = level[1] - m + i;
		level_high = level[1] + i;
		for (int j = 1; j <= n; j++)//����ȼ����Ʒ�Χ
		{
			if (level[j] >= level_low && level[j] <= level_high)
				allow[j] = true;
		}
		for (int k = 2; k <= n; k++)//������ÿ����Ʒ��Ϊ���ʱ���������С����
		{
			if (allow[k] == false)
				continue;
			dijkstra(k);
			if (dist[1] + value[k] < min_cost)
				min_cost = dist[1] + value[k];
			
			memset(visit, false, sizeof(visit));
			memset(dist, 1000000, sizeof(dist));
		}
		memset(allow, false, sizeof(allow));
	}
	cout << min_cost << endl;
	return 0;
}

void dijkstra(int x)
{
	dist[x] = 0;//����ʼ��
	Node* p = new Node;
	p->id = x;
	p->cost = 0;
	push(p);
	while (!empty())
	{
		Node* top = pop();
		int id = top->id;
		int cost = top->cost;
		if (visit[id])
			continue;
		visit[id] = true;
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i] && allow[i] && i != id && dist[i] > dist[id] + exchange_cost[id][i])
			{
				dist[i] = dist[id] + exchange_cost[id][i];
				p = new Node;
				p->id = i;
				p->cost = dist[i];
				push(p);
			}
		}
	}
}

void push(Node* p)//ѹ�����ȼ�����
{
	Node* pre = priority_queue;
	Node* cur = priority_queue->next;
	while (cur != NULL && p->cost > cur->cost)
	{
		pre = pre->next;
		cur = cur->next;
	}
	p->next = cur;
	pre->next = p;
}

Node* pop()//�������ȼ�����
{
	Node* p = priority_queue->next;
	priority_queue->next = priority_queue->next->next;
	return p;
}

bool empty()//����Ϊ��
{
	if (priority_queue->next == NULL)
		return true;
	else
		return false;
}