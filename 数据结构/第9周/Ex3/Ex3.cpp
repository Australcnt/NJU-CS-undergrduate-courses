#include <iostream>

using namespace std;

struct Node//�ڵ���Ϣ
{
    int data;
    Node* left;
    Node* right;
};

void create_bintree(int* in_order, int* post_order, int length, Node*& subtree);//��֪����ͺ��򣬽���������
void snake_traversal(Node* root);//�����������α���
void push(Node* Node_queue[], Node* p, int* head, int* tail);//ѹ��
Node* pop_front(Node* Node_queue[], int* head, int* tail);//ǰ����
Node* pop_back(Node* Node_queue[], int* head, int* tail);//�󵯳�

int main()
{
    int n;//�ڵ����
    cin >> n;
    int in_order[31];//��������
    int post_order[31];//��������
    for (int i = 0; i < n; i++)
        cin >> in_order[i];
    for (int j = 0; j < n; j++)
        cin >> post_order[j];
    Node* root = NULL;
    create_bintree(in_order, post_order, n, root);//��֪����ͺ��򣬽���������
    snake_traversal(root);//�����������α���
	return 0;
}

void create_bintree(int* in_order, int* post_order, int length, Node*& subtree)//��֪����ͺ��򣬽���������
{
    if (length == 0)
        subtree = NULL;
    else
    {
        int position_root = 0;//���ڵ��λ��
        subtree = new Node;
        subtree->data = post_order[length - 1];
        for (position_root = 0; post_order[length - 1] != in_order[position_root]; position_root++);
        create_bintree(in_order, post_order, position_root, subtree->left);
        create_bintree(in_order + position_root + 1, post_order + position_root, length - position_root - 1, subtree->right);
    }
}

void snake_traversal(Node* root)//�����������α���
{
    Node* Node_queue[100];//��������
    Node* Node_stack[100];//�����ݴ�ջ������������ż��������
    int head = 0, tail = 0;
    int head2 = 0, tail2 = 0;
    Node* p = root;
    push(Node_queue, p, &head, &tail);
    int odd_flag = 1;
    int root_flag = 1;
    while (head < tail)
    {
        while (head < tail)
        {
            p = pop_front(Node_queue, &head, &tail);
            if (root_flag)//�Ƿ�Ϊ���ڵ�
            {
                cout << p->data;
                root_flag--;
            }
            else
                cout << ' ' << p->data;
            if (odd_flag % 2 == 1)//������
            {
                if (p->right != NULL)
                    push(Node_stack, p->right, &head2, &tail2);
                if (p->left != NULL)
                    push(Node_stack, p->left, &head2, &tail2);
            }
            else//ż����
            {
                if (p->left != NULL)
                    push(Node_stack, p->left, &head2, &tail2);
                if (p->right != NULL)
                    push(Node_stack, p->right, &head2, &tail2);
            }
        }
        odd_flag++;
        while (head2 < tail2)
            push(Node_queue, pop_back(Node_stack, &head2, &tail2), &head, &tail);
    }
}

void push(Node* Node_queue[], Node* p, int* head, int* tail)//ѹ��
{
    Node_queue[*tail] = p;
    (*tail)++;
}

Node *pop_front(Node* Node_queue[], int* head, int* tail)//ǰ����
{
    Node* p = Node_queue[*head];
    (*head)++;
    return p;
}

Node* pop_back(Node* Node_queue[], int* head, int* tail)//�󵯳�
{
    Node* p = Node_queue[*tail - 1];
    (*tail)--;
    return p;
}