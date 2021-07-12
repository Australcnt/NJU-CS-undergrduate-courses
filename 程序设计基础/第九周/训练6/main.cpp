#include <iostream>
using namespace std;
int main()
{
	int b = 0;
	for (int a = 1; a >= 1; a++)
	{
		b = a;
		for (int i = 1; i <= 5; i++)
		{
			
			if (a % 4 == 0)
			{
				a = 5 * (a / 4) + 1;
				if (i == 5)
				{
					cout << a << " " << b << endl;
					return 0;
				}
			}
				else
				{
					a = b;
					break;
				}
		 }		
	}
	

}