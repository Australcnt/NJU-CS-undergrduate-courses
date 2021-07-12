#include <iostream>
using namespace std;
int main()
{
	int n = 0, iShpFee = 10;
	double dUnitPrice = 40.5, dDiscnt = 0, dAmount;	//dUnitPriceÎªµ¥¼Û
	scanf_s("%d", &n);
	if (n <= 0)
		printf("Error");
	if (n > 0)
	{
		if (n <= 9)
			;
		else if (n <= 29)
			dDiscnt = 0.1;
		else if (n <= 49)
			dDiscnt = 0.2;
		if (n > 49)
		{
			dDiscnt = 0.2;
			iShpFee = 0;
		}
	}
	dAmount = dUnitPrice*n*(1 - dDiscnt) + iShpFee;
	printf("Amount RMB: %.2f", dAmount);
	return 0;
}