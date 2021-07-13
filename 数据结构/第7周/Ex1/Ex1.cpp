#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int matrix[100][100];
	int diagonal_flag = 1, upper_flag = 1, lower_flag = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j])
			{
				if (i > j)
				{
					upper_flag = 0;
					diagonal_flag = 0;
				}
				else if (i < j)
				{
					lower_flag = 0;
					diagonal_flag = 0;
				}
			}
		}
	}
    if (diagonal_flag)
		cout << "diagonal" << endl;
	else if (upper_flag)
		cout << "upper" << endl;
	else if(lower_flag)
		cout << "lower" << endl;
	else
        cout << "none" << endl;
	return 0;
}