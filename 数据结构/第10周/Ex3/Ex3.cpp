#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
	int frequency;//����ĸ����Ƶ��
	int sum;//�ý���µĹ����������
	int length;//����ĸ��Ӧ�Ĺ��������볤��
	int flag;//�Ƿ���Ҷ�ڵ�
	Node* left;//����
	Node* right;//�Һ���
	Node* next;//������һ���ָ��
};

char str[10000];//�ַ���

Node* pop(Node* head);//��������
void insert(Node* head, Node* p);//������˳��������
int preorder_traversal(Node* subtree);//ǰ�������������������

int main()
{
	int frequency_table[26];
	cin >> str;
	int length = strlen(str);
	for (int i = 0; i < 26; i++)
		frequency_table[i] = 0;
	for (int i = 0; i < length; i++)//�������ĸ�ĳ���Ƶ��
		frequency_table[str[i] - 'A']++;
	Node* head = new Node;
	head->next = NULL;
	for (int i = 0; i < 26; i++)//����Ƶ�ʵĵ�������
	{
		if (frequency_table[i] == 0)
			continue;
		Node* cur = head;
		while (cur->next != NULL && frequency_table[i] > cur->next->frequency)
			cur = cur->next;
		Node* p = new Node;
		p->frequency = frequency_table[i];
		p->flag = 1;//��ΪҶ�ڵ�
		p->left = NULL;
		p->right = NULL;
		p->next = cur->next;//������˳��������
		cur->next = p;
	}
	Node* min1 = NULL, * min2 = NULL;//������������
	while(1)
	{
		min1 = pop(head);//����Ƶ�ʵ�һС�Ľ��
		if (head->next == NULL)//����Ϊ��ʱ���õ����������ĸ��ڵ�
			break;
		min2 = pop(head);//����Ƶ�ʵڶ�С�Ľ��
		Node* combine = new Node;
		combine->frequency = min1->frequency + min2->frequency;
		combine->flag = 0;//��Ϊ��Ҷ�ڵ�
		combine->left = min1;
		combine->right = min2;
		insert(head, combine);//������˳����뵽������
	}
	min1->length = 0;
	int sum = preorder_traversal(min1);//ǰ�������������������
	cout << sum << endl;
	return 0;
}

Node* pop(Node* head)//��������
{
	Node* cur = head->next;
	head->next = head->next->next;
	return cur;
}

void insert(Node* head, Node* p)//������˳��������
{
	Node* cur = head;
	while (cur->next != NULL && p->frequency > cur->next->frequency)
		cur = cur->next;
	p->next = cur->next;
	cur->next = p;
}

int preorder_traversal(Node* subtree)//ǰ�������������������
{
	if (subtree == NULL)//�ݹ��������
		return 0;
	if (subtree->left != NULL)
		subtree->left->length = subtree->length + 1;//�������ӹ��������볤��
	if (subtree->right != NULL)
		subtree->right->length = subtree->length + 1;//�����Һ��ӹ��������볤��
	int left_sum = preorder_traversal(subtree->left);//�����������Ĺ����������
	int right_sum = preorder_traversal(subtree->right);//�����������Ĺ����������
	subtree->sum = left_sum + right_sum + subtree->flag * subtree->length * subtree->frequency;//���㵱ǰ����µĹ����������
	return subtree->sum;//���ص�ǰ����µĹ����������
}