#include <iostream>
using namespace std;
struct Vote
	{
		char name[100];
		int number;
	}p1, p2, p3;
void Choice(char name[], Vote *p)
{
	for (int j = 0; name[j] == p -> name[j]; j++)
		if (name[j + 1] == '\0'&&p->name[j + 1] == '\0')
		{
			p->number++;
			break;
		}
}
int main()
{
	cin.getline(p1.name, 100);
	cin.getline(p2.name, 100);
	cin.getline(p3.name, 100);
	p1.number = 0;
	p2.number = 0;
	p3.number = 0;
	char name[100];
	for (int i = 0; i < 10; i++)
	{
		cin.getline(name, 100);
		Choice(name, &p1);
		Choice(name, &p2);
		Choice(name, &p3);
	}
	cout << p1.number << endl;
	cout << p2.number << endl;
	cout << p3.number << endl;
	return 0;
}
