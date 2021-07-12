int CountDigit(int n) //定义CountDigit函数计算整数n的位数;
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