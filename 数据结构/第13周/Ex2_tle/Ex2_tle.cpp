#include <iostream>

using namespace std;

int* id;
int* parent;
int friend_max = 0;

int gcd_calculate(int a, int b);
int Find(int x);
int Union(int root1, int root2);

int main()
{
	int n = 0;
	cin >> n;
	id = new int[n];
	parent = new int[n];
	for (int i = 0; i < n; i++)
		parent[i] = -1;
	for (int i = 0; i < n; i++)
		cin >> id[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Find(i) != Find(j) && ((id[i] % 2 == 0 && id[j] % 2 == 0) || (id[i] % 3 == 0 && id[j] % 3 == 0) || (gcd_calculate(id[i], id[j]) != 1)))
			{
				int friend_number = -Union(i, j);
				if (friend_number > friend_max)
					friend_max = friend_number;
			}
		}
	}
	cout << friend_max << endl;
	return 0;
}

int gcd_calculate(int a, int b)
{
	int temp = 0;
	if (b > a)
	{
		temp = b;
		b = a;
		a = temp;
	}
	while (b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int Find(int x)
{
	if (parent[x] < 0)
		return x;
	else
		return Find(parent[x]);
}

int Union(int root1, int root2)
{
	root1 = Find(root1);
	root2 = Find(root2);
	int temp = parent[root1] + parent[root2];
	if (parent[root1] < parent[root2])
	{
		parent[root2] = root1;
		parent[root1] = temp;
	}
	else
	{
		parent[root1] = root2;
		parent[root2] = temp;
	}
	return temp;
}