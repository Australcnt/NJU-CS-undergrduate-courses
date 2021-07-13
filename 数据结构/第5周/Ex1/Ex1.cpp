#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
	int data;
	int cur_addr;
	int next_addr;
};

int main()
{
	int first_addr;
	int data_number;
	cin >> first_addr;
	cin >> data_number;
	Node *data_store = new Node[100000];//创建结构数组
	for (int i = 0; i < data_number; i++)
	{
		Node* p = new Node;
		cin >> p->cur_addr;
		cin >> p->data;
		cin >> p->next_addr;
		data_store[p->cur_addr] = *p;//数组下标与地址一致
	}
	int addr = first_addr;
	Node *data_output = new Node[100000];//按顺序存储结点
	for (int j = 0; j < data_number; j++)
	{
		data_output[j] = data_store[addr];
		addr = data_store[addr].next_addr;
	}
	for (int k = data_number - 1; k > 0; k--)//逆序输出
		cout << setfill('0') << setw(5) << data_output[k].cur_addr << ' ' << data_output[k].data << ' ' << setfill('0') << setw(5) << data_output[k - 1].cur_addr << endl;
	cout << setfill('0') << setw(5) << data_output[0].cur_addr << ' ' << data_output[0].data << ' ' << "-1" << endl;
	return 0;
}
