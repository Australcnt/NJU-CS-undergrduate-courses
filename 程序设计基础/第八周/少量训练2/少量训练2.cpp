#include <stdio.h>
int MyFibR(int);
int count = 0;
int main()
{
	printf("��6������ %d ������.\n", MyFibR(6));
	printf("�ݹ麯��һ��������ִ����%d��.\n", count);
	return 0;
}
int MyFibR(int n)
{
	count++;
	if (n == 1 || n == 2)
		return 1;
	else
		return MyFibR(n - 2) + MyFibR(n - 1);
}