#include <stdio.h>
int MyFibR(int);
int count = 0;
int main()
{
	printf("第6个月有 %d 对兔子.\n", MyFibR(6));
	printf("递归函数一共被调用执行了%d次.\n", count);
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