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

void push(char c);//压栈
char pop();//出栈
void push2(char c);//压入队列
char pop2();//弹出队列
void push3(long long number);//压栈
long long pop3();//弹出队列
int priority(char c);//优先级设置

int main()
{
	char infix_expression[100000];
	cin >> infix_expression;
	int length = strlen(infix_expression);
	//中缀表达式转后缀表达式
	for (int i = 0; i < length; i++)
	{
		if (infix_expression[i] >= '0' && infix_expression[i] <= '9')//遇到数字直接送入后缀表达式
			push2(infix_expression[i]);
		else if (infix_expression[i] == '(')//遇到左括号，直接入栈
			push(infix_expression[i]);
		else if (infix_expression[i] == ')')//遇到右括号，将栈顶操作符弹出，送入后缀表达式，直到遇到左括号
		{
			while (stack[top] != '(')//左括号不送入后缀表达式
				push2(pop());
			pop();
		}
		else//遇到操作符，将栈顶优先级不低于该操作符的操作符弹出，送入后缀表达式，再将该操作符入栈
		{
			while (top != -1 && priority(stack[top]) >= priority(infix_expression[i]))
			    push2(pop());
			push(infix_expression[i]);
		}
	}
	while (top != -1)//将栈中剩余操作符依次弹出，送入后缀表达式
		push2(pop());
	//后缀表达式求值
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

void push(char c)//压栈
{
	stack[top + 1] = c;
	top++;
}

char pop()//出栈
{
	char c = stack[top];
	//stack[top] = NULL;
	top--;
	return c;
}

void push2(char c)//压入队列
{
	postfix_expression[tail] = c;
	tail++;
}

char pop2()//弹出队列
{
	char c = postfix_expression[head];
	postfix_expression[head] = NULL;
	head++;
	return c;
}

void push3(long long number)//压栈
{
	stack3[top3 + 1] = number;
	top3++;
}

long long pop3()//出栈
{
	long long number = stack3[top3];
	stack3[top3] = 0;
	top3--;
	return number;
}

int priority(char c)//优先级设置
{
	if (c == '(' || c == ')')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	else if (c == 'x')
		return 3;
	return 0;
}