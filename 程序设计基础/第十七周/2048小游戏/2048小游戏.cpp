/***
*
*		2048С��Ϸ����v4.0
*
*       Copyright ½����. All rights reserved.
*
*		2015-11-10
*
*		Visual Studio2013��Ҫȥ��printf_s�Ȱ�ȫ�����ſ�˳������
*		ԭ����Ϸ�ƶ�һ��ÿ����������ֻ�ܺϲ�һ�Σ����ó��������κϲ����磺8 4 4 0 ִ�����Ҳ����������� 0 0 0 16
****/
/***
*	version4.0�� ---------------2015-11-10
*	1�����ƻ��棬��������ɫ����
*	2��������ʱ�ͼƲ�����
****/
/***
*	version3.0��----------------2015-11-9
*	1���޸���Ч����ʱҲ���������ֵ�bug
*	2���޸��ظ�������ʾ��Ϣ��bug
****/
/***
*	version2.0��----------------2015-11-9
*	1�����÷���������
****/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;
void init(int(&board)[4][4]);		//��ʼ������
void randnum(int(&board)[4][4]);	//������������
void printboard(int(&board)[4][4]);//��ӡ����
int leftmove(int(&board)[4][4]);	//�����ƶ�����,����ֵ1��ʾ��Ч������0��ʾ��Ч����
int rightmove(int(&board)[4][4]);	//�����ƶ�����
int upmove(int(&board)[4][4]);		//�����ƶ�����
int downmove(int(&board)[4][4]);	//�����ƶ�����
int iswin(int(&board)[4][4]);		//�ж��Ƿ�ʤ��
int isfail(int(&board)[4][4]);		//�ж��Ƿ�ʧ��
unsigned short int getcolor(int color);//�õ����ֶ�Ӧ����ɫ����
int main()
{
	clock_t start, finish;
	double time_length;
	start = clock();

	int count = 0;	//�洢��������
	int board[4][4];	//����
	char move;

	cout << "��Ϸͨ������������:" << endl;
	init(board);
	printboard(board);
	int output = 0;
	for (;;)
	{
		if (!output)	//ͨ��output������ֹ����������ʾ
		{
			cout << "�����������ƶ�����Esc����������:";
			output = 1;
		}
		move = _getch();	//��������һ���ַ�Ϊ-32
		move = _getch();	//vs2013�� _getch() ������getch()�����ã�
		switch (move)
		{
		case 72:
		{
			if (upmove(board)) //��������Ч����
			{
				randnum(board);
				system("cls");
				printboard(board);
				output = 0;
				++count;
				break;
			}
			else
				continue;
		}
		case 80:
		{
			if (downmove(board))
			{
				randnum(board);
				system("cls");
				printboard(board);
				output = 0;
				++count;
				break;
			}
			else
				continue;
		}
		case 75:
		{
			if (leftmove(board))
			{
				randnum(board);
				system("cls");
				printboard(board);
				output = 0;
				++count;
				break;
			}
			else
				continue;
		}
		case 77:
		{
			if (rightmove(board))
			{
				randnum(board);
				system("cls");
				printboard(board);
				output = 0;
				++count;
				break;
			}
			else
				continue;
		}
		case 27:exit(0);
		}
		if (iswin(board))
		{
			cout << "��Ӯ�ˣ�" << endl;
			finish = clock();
			time_length = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("��������Ϸʱ��Ϊ��%.1fs\n", time_length);
			printf("���Ĳ�������Ϊ:%d\n", count);
			cout << "��������������" << endl;
			_getch();
			_getch();
			exit(0);
		}
		if (isfail(board))
		{
			cout << "��Ϸ����" << endl;
			finish = clock();
			time_length = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("��������Ϸʱ��Ϊ��%.1fs\n", time_length);
			printf("���Ĳ�������Ϊ:%d\n", count);
			cout << "��������������" << endl;
			_getch();
			_getch();
			exit(0);
		}
	}
}
int iswin(int(&board)[4][4])
{
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
			if (board[i][j] == 2048)
				return 1;
	return 0;
}
int isfail(int(&board)[4][4])
{
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
			if (board[i][j] == 0)
				return 0;		//������0������Ϸδ����
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 2; j++)
			if (board[i][j] == board[i][j + 1])
				return 0;		//���������Ѿ��������������Կɲ�������δ����
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 3; j++)
			if (board[i][j] == board[i + 1][j])
				return 0;		//���������Ѿ��������������Կɲ�������δ����
	return 1;		//����ִ���κβ�������Ϸ����
}
void init(int(&board)[4][4])
{
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
			board[i][j] = 0;
	srand((unsigned)time(NULL));
	int i = rand() % 4;
	int j = rand() % 4;
	board[i][j] = 2;
	do
	{
		i = rand() % 4;
		j = rand() % 4;
	} while (board[i][j] != 0);
	board[i][j] = 2;
}
void randnum(int(&board)[4][4])
{
	int num = (rand() % 2 + 1) * 2;
	int i, j;
	srand((unsigned)time(NULL));
	do
	{
		i = rand() % 4;
		j = rand() % 4;
	} while (board[i][j] != 0);
	board[i][j] = num;
}

void printboard(int(&board)[4][4])
{
	HANDLE hOut;//��������
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
		{
			if (j == 3)
			{
				SetConsoleTextAttribute(hOut, getcolor(board[i][j]));//����������ɫ
				printf("%d\n", board[i][j]);						//getcolor()��������ȡ�ö�Ӧ���ֵ���ɫ������Ȼ������SetConsoleTextAttribute()������ɫ
			}
			else
			{
				SetConsoleTextAttribute(hOut, getcolor(board[i][j]));
				printf("%d\t", board[i][j]);
			}
		}
	SetConsoleTextAttribute(hOut, getcolor(0));//��ԭΪ��ɫ����
}
int rightmove(int(&board)[4][4])
{
	int flag = 0;
	for (int i = 0; i <= 3; i++)		//����Ϊ��λѭ������
	{
		int tmp[4] = { 0, 0, 0, 0 }, count = 3;	//tmp��������ִ�в����������ս���
		for (int j = 3; j >= 0; j--)	//���������������ķ�0���ִ���tmp[]
		{
			if (board[i][j] != 0)
			{
				if (tmp[count] == 0)		//tmp��Ӧ��λ��Ϊ0��˵����δ�������֣�������������
					tmp[count] = board[i][j];
				else
				{
					if (board[i][j] == tmp[count])	//tmp��Ӧ��λ���������֣������������ȣ����ϲ�
						tmp[count] += board[i][j];
					else
						tmp[--count] = board[i][j];	//tmp��Ӧ��λ���������֣��������ֲ���
				}									//����ǰһλ����tmp������Ϊ0�Ŀ�λ
			}
		}
		for (int j = 0; j <= 3; j++)		//ֻҪԭ������������������һ����ͬ����Ϊ��Ч����
			if (board[i][j] != tmp[j])		//����Ϊ��Ч����
				flag = 1;
		for (int j = 3; j >= 0; j--)	//��tmp���Ƶ�����
			board[i][j] = tmp[j];
	}
	return flag;
}
int leftmove(int(&board)[4][4])
{
	int flag = 0;
	for (int i = 0; i <= 3; i++)
	{
		int tmp[4] = { 0, 0, 0, 0 }, count = 0;
		for (int j = 0; j <= 3; j++)
		{
			if (board[i][j] != 0)
			{
				if (tmp[count] == 0)
					tmp[count] = board[i][j];
				else
				{
					if (board[i][j] == tmp[count])
						tmp[count] += board[i][j];
					else
						tmp[++count] = board[i][j];
				}
			}
		}
		for (int j = 0; j <= 3; j++)
			if (board[i][j] != tmp[j])
				flag = 1;
		for (int j = 0; j <= 3; j++)
			board[i][j] = tmp[j];
	}
	return flag;
}
int upmove(int(&board)[4][4])
{
	int flag = 0;
	for (int j = 0; j <= 3; j++)
	{
		int tmp[4] = { 0, 0, 0, 0 }, count = 0;
		for (int i = 0; i <= 3; i++)
		{
			if (board[i][j] != 0)
			{
				if (tmp[count] == 0)
					tmp[count] = board[i][j];
				else
				{
					if (board[i][j] == tmp[count])
						tmp[count] += board[i][j];
					else
						tmp[++count] = board[i][j];
				}
			}
		}
		for (int i = 0; i <= 3; i++)
			if (board[i][j] != tmp[i])
				flag = 1;
		for (int i = 0; i <= 3; i++)
			board[i][j] = tmp[i];
	}
	return flag;
}
int downmove(int(&board)[4][4])
{
	int flag = 0;
	for (int j = 0; j <= 3; j++)
	{
		int tmp[4] = { 0, 0, 0, 0 }, count = 3;
		for (int i = 3; i >= 0; i--)
		{
			if (board[i][j] != 0)
			{
				if (tmp[count] == 0)
					tmp[count] = board[i][j];
				else
				{
					if (board[i][j] == tmp[count])
						tmp[count] += board[i][j];
					else
						tmp[--count] = board[i][j];
				}
			}
		}
		for (int i = 0; i <= 3; i++)
			if (board[i][j] != tmp[i])
				flag = 1;
		for (int i = 3; i >= 0; i--)
			board[i][j] = tmp[i];
	}
	return flag;
}
unsigned short int getcolor(int color)
{
	switch (color)
	{
	case 0:return  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;			//ǳ��ɫ
	case 2:return  FOREGROUND_RED | FOREGROUND_BLUE;							//ǳ��ɫ
	case 4:return  FOREGROUND_GREEN;											//ǳ��ɫ
	case 8:return  FOREGROUND_RED;												//ǳ��ɫ
	case 16:return FOREGROUND_GREEN | FOREGROUND_BLUE;							//ǳ��ɫ
	case 32:return  FOREGROUND_RED | FOREGROUND_GREEN;							//ǳ��ɫ
	case 64:return FOREGROUND_INTENSITY | FOREGROUND_RED;						//������ɫ
	case 128:return FOREGROUND_INTENSITY | FOREGROUND_GREEN;					//������ɫ
	case 256:return FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE;	//����ǳ��ɫ
	case 512:return FOREGROUND_INTENSITY | FOREGROUND_BLUE;						//������ɫ
	case 1024:return FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN;	//������ɫ
	case 2048:return FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE;	//������ɫ
	default:return 0;//ǳ��ɫ
	}
}