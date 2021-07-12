#include<iostream>
using namespace std;
#include "Function.h"


int main() {
	FILE* stream;
	freopen_s(&stream, "Test.txt", "r", stdin);
	Node* head = NULL;
	head=list_head_insert(head, 1);
	head = list_head_insert(head, 2);
	head = list_head_insert(head, 2);
	list_tail_insert(head, 5);
	list_tail_insert(head, 6);
	head = list_specific_insert(head, 4, 4);
	print_list(head);
	cout << endl;
	head = list_specific_insert(head, 1, 8);
	print_list(head);
	cout << endl;
	head = list_specific_insert(head, 8, 9);
	print_list(head);
	cout << endl;
	head = sort(head);
	print_list(head);
	cout << endl;
	reverse_print_list(head);
	cout << endl;
	change_specific_var(head, 2, 3);
	print_list(head);
	cout <<"----" <<endl;
	head = del_specific_var(head, 3);
	print_list(head);
	cout << "----" << endl;
	int num;
	while (cin >> num) {
		
		Tree_Node* tree = NULL;
		for (int i = 0; i < num; i++) {
			int node;
			cin >> node;
			tree = insert(tree, node);
		}
		postorder(tree);
		cout << endl;
	}
	
	return 0;
}