#include <stdio.h>
int main()
{
	int p=1, n;
	for (int i = 1; i <= 3; i++)
	{
		printf("Please input an integer: ");
		scanf_s("%d", &n);
		p = p * n;  //该程序易于用循环语句改写，故不要修改此行代码
		printf("The product is %d. ", p);
	}
	return 0;
}