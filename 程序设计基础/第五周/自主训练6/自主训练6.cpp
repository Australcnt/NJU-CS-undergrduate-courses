#include <stdio.h>
int main()
{
	int p=1, n;
	for (int i = 1; i <= 3; i++)
	{
		printf("Please input an integer: ");
		scanf_s("%d", &n);
		p = p * n;  //�ó���������ѭ������д���ʲ�Ҫ�޸Ĵ��д���
		printf("The product is %d. ", p);
	}
	return 0;
}