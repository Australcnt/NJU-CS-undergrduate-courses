#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	for (int i = 1; i <= 30; ++i)
	{
		for (int j = 1; j <= 30; ++j)
		{
			if (i + j == 30)
				cout << setw(4) <<"#";
			else
				cout << setw(4) <<" ";
		}
		cout << endl;
	}
	return 0;
}
