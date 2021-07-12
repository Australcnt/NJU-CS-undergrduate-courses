#include <iostream>
using namespace std;
void Count(char a[], int x[], int n)
{
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] >= '0'&&a[i] <= '9')
			x[0]++;
		else if (a[i] == ' ')
			x[1]++;
		else
			x[2]++;
	}
}
int main()
{
	char a[100];
	cin.getline(a, 100);
	int x[3];
	x[0] = x[1] = x[2] = 0;
	Count(a, x, 3);
	cout << x[0] << " " << x[1] << " " << x[2] << endl;
	return 0;
}