#include <iostream>

using namespace std;

int queue[200000];
int head = 0, tail = 0;

void push(int data);//ѹ�����
int pop();//��������

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
		for (int k = tail - 1; k > head; k--)//�������
			cout << queue[k] << ' ';
		cout << queue[head] << endl;
	}
	return 0;
}

void push(int data)//ѹ�����
{
	queue[tail] = data;
	tail++;
}

int pop()//��������
{
	int data = queue[head];
	queue[head] = 0;
	head++;
	return data;
}