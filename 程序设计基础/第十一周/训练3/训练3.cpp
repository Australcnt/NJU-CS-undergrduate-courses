#include <iostream>
using namespace std;
int main()
{
	int b[][3] = { 0, 2, 1, 1, 0, 2, 1, 2, 0 };
	for (int i = 0; i <= 2; ++i)
		for (int j = 0; j <= 2; ++j)
		{
			b[i][j] = b[b[i][j]][b[j][i]];
			printf("%d, ", b[i][j]);
		}
	return 0;
}