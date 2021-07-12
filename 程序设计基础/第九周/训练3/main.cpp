#include "Head.h"
#include <iostream>
using namespace std;
int main()
{
	for (int n = 1; n <= 10000; n++)
		if (n == TongGou(n))
			cout << n << " ";
	return 0;


}