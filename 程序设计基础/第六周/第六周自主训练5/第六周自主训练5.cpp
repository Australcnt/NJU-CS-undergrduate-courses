#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int iYear, iMonth, iWeek=0, iDay=1, c, y, n;
	cin >> iYear >> iMonth;
	if (iYear >= 1600 && 1 <= iMonth && iMonth <= 12 )
	{
		cout << iYear << "年" << iMonth << "月" << endl;
		cout << setw(4) << "日" << setw(4) << "一" << setw(4) << "二" << setw(4) << "三" << setw(4) << "四" << setw(4) << "五" << setw(4) << "六" << endl;
		switch (iMonth)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			n = 31; break;
		case 2:
			n = 29; break;
		case 4:case 6:case 9:case 11:
			n = 30;
		}
		c = iYear / 100;
		y = iYear % 100;
		if (iMonth == 1)
		{
			iYear = iYear - 1;
			iMonth = 13;
		}
		if (iMonth == 2)
		{
			iYear = iYear - 1;
			iMonth = 14;
		}
		iWeek = ((c / 4) - 2 * c + y + (y / 4) + (26 * (iMonth + 1) / 10) + iDay - 1) % 7;
		if (iWeek < 0)
			iWeek = iWeek + 7;
		if (iWeek == 7)
			iWeek = 0;
		for (int i = 1; i <= iWeek; ++i)
			cout << setw(4) << " ";
		int j = 1;
		for (; j <= 7 - iWeek; ++j)
			cout << setw(4) << j;
		cout << endl;
		while (j <= n)
		{
			for (int k = 1; k <= 7&& j<=n ; ++k, ++j)
				cout << setw(4) << j;
			cout << endl;
		}

	}
	return 0;
}