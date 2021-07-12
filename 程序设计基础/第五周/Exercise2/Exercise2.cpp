#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		int x,a = 0,b = 0, c = 0, d = 0;
		x = n;
		while (a*a <= x)
			a++;
		if (a*a == x)
			cout << a <<" "<< 0 <<" "<< 0 <<" "<< 0 << endl;
		else
			x = x - (a - 1)*(a - 1);
		a = a - 1;
		while (b*b <= x)
			b++;
		if (b*b == x)
			cout << a <<" "<< " "<<b <<" "<< 0 <<" "<< 0 << endl;
		else
			x = x - (b - 1)*(b - 1);
		b = b - 1;
		while (c*c <= x)
			c++;
		if (c*c == x)
			cout << a <<" "<< b <<" "<< c <<" "<< 0 << endl;
		else
			x = x - (c - 1)*(c - 1);
		c = c - 1;
		while (d*d <= x)
			d++;
		d = d - 1;
		if (d*d==x)
		cout << a <<" "<< b <<" "<< c <<" "<< d << endl;
		else
		{ loop:
		a = a - 1;
		int  m,b = 0 ,c = 0, d = 0;
		m = n - a*a;
		while (b*b <= m)
			b++;
		if (b*b == m)
			cout << a << " " << " " << b << " " << 0 << " " << 0 << endl;
		else
			m = m - (b - 1)*(b - 1);
		b = b - 1;
		while (c*c <= m)
			c++;
		if (c*c == m)
			cout << a << " " << b << " " << c << " " << 0 << endl;
		else
			m = m - (c - 1)*(c - 1);
		c = c - 1;
		while (d*d <= m)
			d++;
		d = d - 1;
		if (d*d == m)
			cout << a << " " << b << " " << c << " " << d << endl;
		else
			goto loop;
		}
		cin >> n;
	}

	if (n=0)
		return 0;
}