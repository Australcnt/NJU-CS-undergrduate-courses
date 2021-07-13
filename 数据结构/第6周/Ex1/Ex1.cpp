#include <iostream>
#include <string.h>

using namespace std;

char stack[100000];
char postfix_expression[100000];
long long stack3[100000];
int top = -1;
int head = 0;
int tail = 0;
int top3 = -1;

void push(char c);//ѹջ
char pop();//��ջ
void push2(char c);//ѹ�����
char pop2();//��������
void push3(long long number);//ѹջ
long long pop3();//��������
int priority(char c);//���ȼ�����

int main()
{
	char infix_expression[100000];
	cin >> infix_expression;
	int length = strlen(infix_expression);
	//��׺���ʽת��׺���ʽ
	for (int i = 0; i < length; i++)
	{
		if (infix_expression[i] >= '0' && infix_expression[i] <= '9')//��������ֱ�������׺���ʽ
			push2(infix_expression[i]);
		else if (infix_expression[i] == '(')//���������ţ�ֱ����ջ
			push(infix_expression[i]);
		else if (infix_expression[i] == ')')//���������ţ���ջ�������������������׺���ʽ��ֱ������������
		{
			while (stack[top] != '(')//�����Ų������׺���ʽ
				push2(pop());
			pop();
		}
		else//��������������ջ�����ȼ������ڸò������Ĳ����������������׺���ʽ���ٽ��ò�������ջ
		{
			while (top != -1 && priority(stack[top]) >= priority(infix_expression[i]))
			    push2(pop());
			push(infix_expression[i]);
		}
	}
	while (top != -1)//��ջ��ʣ����������ε����������׺���ʽ
		push2(pop());
	//��׺���ʽ��ֵ
	while (head != tail)
	{
		char c = pop2();
		long long a = 0, b = 0;
		switch (c)
		{
		    case '+':
				a = pop3();
				b = pop3();
				push3(a + b);
				break;
			case '-':
				a = pop3();
				b = pop3();
				push3(b - a);
				break;
			case 'x':
				a = pop3();
				b = pop3();
				push3(a * b);
				break;
			default:
				push3(c - '0');
		}
	}
	long long result = pop3();
	cout << result << endl;
	return 0;
}

void push(char c)//ѹջ
{
	stack[top + 1] = c;
	top++;
}

char pop()//��ջ
{
	char c = stack[top];
	//stack[top] = NULL;
	top--;
	return c;
}

void push2(char c)//ѹ�����
{
	postfix_expression[tail] = c;
	tail++;
}

char pop2()//��������
{
	char c = postfix_expression[head];
	postfix_expression[head] = NULL;
	head++;
	return c;
}

void push3(long long number)//ѹջ
{
	stack3[top3 + 1] = number;
	top3++;
}

long long pop3()//��ջ
{
	long long number = stack3[top3];
	stack3[top3] = 0;
	top3--;
	return number;
}

int priority(char c)//���ȼ�����
{
	if (c == '(' || c == ')')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	else if (c == 'x')
		return 3;
	return 0;
}