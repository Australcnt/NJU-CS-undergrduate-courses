int CountDigit(int n) //����CountDigit������������n��λ��;
{
	int m = 0, x = 1;
	x = n;
	while (x >= 1)
	{
		x = x / 10;
		m++;
	}
	return m;
}