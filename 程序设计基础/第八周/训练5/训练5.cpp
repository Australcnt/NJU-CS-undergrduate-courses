#include <stdio.h>
void EchoPrint(int);
int main()
{
	int n;
	printf("input n:");
	scanf_s("%d", &n);
	EchoPrint(n);
	printf("\n");
	return 0;
}
void EchoPrint(int n)
{
	if (n >= 10)
		EchoPrint(n / 10);
	printf("%d", n % 10);
}
