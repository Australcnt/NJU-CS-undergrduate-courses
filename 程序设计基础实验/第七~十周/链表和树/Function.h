#pragma once
struct Node {
	Node* link;//ָ����
	int var;//������
};
struct Tree_Node {
	Tree_Node* lchild;     //������
	Tree_Node* rchild;    //������
	int var;
};

int list_tail_insert(Node* list_head, int var);

Node* list_head_insert(Node* list_head, int var);

Node* list_specific_insert(Node* list_head, int location, int var);

void print_list(Node* list_head);

void reverse_print_list(Node* list_head);

void change_specific_var(Node* list_head, int old_var, int new_var);

Node* del_specific_var(Node* list_head, int del_var);

Node* sort(Node* list_head);

Tree_Node* insert(Tree_Node* T, int x);

void postorder(Tree_Node* T);
