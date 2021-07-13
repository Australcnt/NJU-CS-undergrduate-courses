//用染色法判断该图中的每一个连通分量是否为二分图，若都是二分图则输出yes，反之则输出no
#include <iostream>

using namespace std;

struct Node//邻接表结点结构
{
	int id;
	Node* next;
	Node() { id = -1; next = NULL; }
};

int n, m;
int* parent;//并查集根结点
int* color;//结点颜色
Node** adjoin;//邻接表表头数组
int* queue;//bfs队列
int head = 0, tail = 0;//队头指针，队尾指针

int Find(int x);//寻找根结点
void WeightedUnion(int root1, int root2);//合并两个集合
bool adjoin_check(int a, int b);//判断两个人是否是相邻
void push(int x);//压入队列
int pop();//弹出队列
bool empty();//队列为空

int main()
{
	cin >> n >> m;
	parent = new int[n];
	color = new int[n];
	adjoin = new Node * [m];
	queue = new int[100000];
	for (int i = 0; i < n; i++)//初始化并查集
		parent[i] = -1;
	for (int i = 0; i < n; i++)//初始化各结点颜色为空
		color[i] = -1;
	for (int i = 0; i < n; i++)//初始化邻接表表头数组
		adjoin[i] = new Node;
	int a = 0, b = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		Node* cur1 = adjoin[a];//写入邻接表
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
			WeightedUnion(a, b);//并查集
	}
	for (int i = 0; i < n; i++)
	{
		if (parent[i] < 0)//判断每个连通分量是否为二分图
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
						color[j] = !color[from];//将相邻结点染成不同的颜色   
					}
					if (color[from] == color[j] && adjoin_check(from, j))//若相邻结点颜色相同，则不是二分图   
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

int Find(int x)//寻找根结点
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

void WeightedUnion(int root1, int root2)//合并两个集合
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

bool adjoin_check(int a, int b)//是否为相邻结点
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

void push(int x)//压入队列
{
	queue[tail] = x;
	tail++;
}

int pop()//弹出队列
{
	int x = queue[head];
	head++;
	return x;
}

bool empty()//队列为空
{
	if (head == tail)
		return true;
	else
		return false;
}