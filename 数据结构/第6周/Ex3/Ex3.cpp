#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char moon_cake[100000];
	cin >> moon_cake;
	int length = strlen(moon_cake);
	int largest_number = 0;
	//��ÿһ�������н��б�������
	for (int i = 0; i < length; i++)
	{
		if (length - i <= largest_number)//���ڱ�����±������ٵ������ֱ����������������
			break;
		for (int j = length - 1; j >= i; j--)
		{
			int number = j - i + 1;
			if (number <= largest_number)//���ڱ�����±������ٵ������ֱ����������������
				break;
			int count_n = 0, count_j = 0, count_u = 0, count_c = 0, count_s = 0;
			for (int k = i; k <= j; k++)
			{
				if (moon_cake[k] == 'n')
					count_n++;
				else if (moon_cake[k] == 'j')
					count_j++;
				else if (moon_cake[k] == 'u')
					count_u++;
				else if (moon_cake[k] == 'c')
					count_c++;
				else if (moon_cake[k] == 's')
					count_s++;
			}

			if (count_n % 2 == 0 && count_j % 2 == 0 && count_u % 2 == 0 && count_c % 2 == 0 && count_s % 2 == 0 && number > largest_number)
				largest_number = number;
		}
	}
	cout << largest_number << endl;
	return 0;
}