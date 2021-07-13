#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
	int frequency;//该字母出现频率
	int sum;//该结点下的哈夫曼编码和
	int length;//该字母对应的哈夫曼编码长度
	int flag;//是否是叶节点
	Node* left;//左孩子
	Node* right;//右孩子
	Node* next;//队列下一结点指针
};

char str[10000];//字符串

Node* pop(Node* head);//弹出队列
void insert(Node* head, Node* p);//按递增顺序插入队列
int preorder_traversal(Node* subtree);//前序遍历计算哈夫曼编码和

int main()
{
	int frequency_table[26];
	cin >> str;
	int length = strlen(str);
	for (int i = 0; i < 26; i++)
		frequency_table[i] = 0;
	for (int i = 0; i < length; i++)//保存各字母的出现频率
		frequency_table[str[i] - 'A']++;
	Node* head = new Node;
	head->next = NULL;
	for (int i = 0; i < 26; i++)//创建频率的递增队列
	{
		if (frequency_table[i] == 0)
			continue;
		Node* cur = head;
		while (cur->next != NULL && frequency_table[i] > cur->next->frequency)
			cur = cur->next;
		Node* p = new Node;
		p->frequency = frequency_table[i];
		p->flag = 1;//设为叶节点
		p->left = NULL;
		p->right = NULL;
		p->next = cur->next;//按递增顺序插入队列
		cur->next = p;
	}
	Node* min1 = NULL, * min2 = NULL;//创建哈夫曼树
	while(1)
	{
		min1 = pop(head);//弹出频率第一小的结点
		if (head->next == NULL)//队列为空时，得到哈夫曼树的根节点
			break;
		min2 = pop(head);//弹出频率第二小的结点
		Node* combine = new Node;
		combine->frequency = min1->frequency + min2->frequency;
		combine->flag = 0;//设为非叶节点
		combine->left = min1;
		combine->right = min2;
		insert(head, combine);//按递增顺序插入到队列中
	}
	min1->length = 0;
	int sum = preorder_traversal(min1);//前序遍历计算哈夫曼编码和
	cout << sum << endl;
	return 0;
}

Node* pop(Node* head)//弹出队列
{
	Node* cur = head->next;
	head->next = head->next->next;
	return cur;
}

void insert(Node* head, Node* p)//按递增顺序插入队列
{
	Node* cur = head;
	while (cur->next != NULL && p->frequency > cur->next->frequency)
		cur = cur->next;
	p->next = cur->next;
	cur->next = p;
}

int preorder_traversal(Node* subtree)//前序遍历计算哈夫曼编码和
{
	if (subtree == NULL)//递归结束条件
		return 0;
	if (subtree->left != NULL)
		subtree->left->length = subtree->length + 1;//设置左孩子哈夫曼编码长度
	if (subtree->right != NULL)
		subtree->right->length = subtree->length + 1;//设置右孩子哈夫曼编码长度
	int left_sum = preorder_traversal(subtree->left);//计算左子树的哈夫曼编码和
	int right_sum = preorder_traversal(subtree->right);//计算右子树的哈夫曼编码和
	subtree->sum = left_sum + right_sum + subtree->flag * subtree->length * subtree->frequency;//计算当前结点下的哈夫曼编码和
	return subtree->sum;//返回当前结点下的哈夫曼编码和
}