#include <iostream>

using namespace std;

int queue[200000];
int head = 0, tail = 0;

void push(int data);//压入队列
int pop();//弹出队列

int main()
{
	int test_number;
	cin >> test_number;
	for (int i = 0; i < test_number; i++)
	{
		int data;
		cin >> data;
        head = 0;
	    tail = 0;
		for (int j = data; j > 0; j--)
		{
			push(j);//
			push(pop());
		}
		for (int k = tail - 1; k > head; k--)//逆序输出
			cout << queue[k] << ' ';
		cout << queue[head] << endl;
	}
	return 0;
}

void push(int data)//压入队列
{
	queue[tail] = data;
	tail++;
}

int pop()//弹出队列
{
	int data = queue[head];
	queue[head] = 0;
	head++;
	return data;
}