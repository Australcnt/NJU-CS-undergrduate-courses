extern int CountDigit(int);
int TongGou(int n)//�ж��Ƿ�Ϊͬ����;
{
	int a = n*n - n;
	int b = 1;
	for (int i = 1;i<=CountDigit(n);i++)
		b *= 10;
	if (a%b == 0)
		return n;
}