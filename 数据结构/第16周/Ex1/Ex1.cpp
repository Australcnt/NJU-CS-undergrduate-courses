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

int row, col;//行数、列数
int map[100][100];//地形高度
int dist[100][100];//地势落差
bool visit[100][100];//是否访问过
Node* priority_queue = new Node;//优先级队列
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

Node* pop();//弹出优先级队列
void push(Node* p);//压入优先级队列
bool empty();//队列为空
int max(int a, int b);//较大数

int main()
{
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)//地形高度初始化
			cin >> map[i][j];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)//地势落差初始化
			dist[i][j] = INT32_MAX;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)//访问初始化
			visit[i][j] = false;
	dist[0][0] = 0;//起点初始化
	Node* p = new Node;
	p->x = 0;
	p->y = 0;
	p->min_intercept = 0;
	push(p);
	while (!empty())//Dijkstra算法，求最小地势落差路径
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
			int next_min_intercept = max(min_intercept, abs(map[y][x] - map[next_y][next_x]));//计算该结点的地势落差
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

Node* pop()//弹出优先级队列
{
	Node* p = priority_queue->next;
	priority_queue->next = priority_queue->next->next;
	return p;
}

void push(Node* p)//压入优先级队列
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

bool empty()//队列为空
{
	if (priority_queue->next == NULL)
		return true;
	else
		return false;
}

int max(int a, int b)//较大数
{
	if (a < b)
		a = b;
	return a;
}