#include "UI.h"

UI::UI()
{
	;
}

void UI::Set_Window() // ���ô�����ز���
{
	SetConsoleTitleA("ֲ���ս��ʬ - PlantsVsZombies by Australcnt"); // ���ô��ڱ���
	COORD buf_size = { WINDOW_LENGTH_X, WINDOW_LENGTH_Y }; // ���ô��ڻ�������С
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), buf_size);
	//SMALL_RECT window_size = { 0,0, WINDOW_LENGTH_X - 1, WINDOW_LENGTH_Y - 1 }; // ���ô���λ�úʹ�С
	//SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &window_size);
	char cmd[30];
	sprintf(cmd, "mode con cols=%d lines=%d", WINDOW_LENGTH_X, WINDOW_LENGTH_Y);
	system(cmd); //���ô��ڿ�Ⱥ͸߶�
}

void UI::Hide_Cursor() // ���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1 ,false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void UI::Move_Cursor(const int x, const int y) // ���ù��λ��
{
	COORD cursor_pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_pos);
}

void UI::Set_Color(int color) //������ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void UI::Print_With_Color(const string& str, int color) // ����ɫ���ַ������
{
	Set_Color(color);
	cout << str;
	Set_Color(DEFAULT_COLOR); //������������û�Ĭ��ɫ
}

void UI::Print_With_Color(int num, int color) // ����ɫ���������
{
	Set_Color(color);
	cout << num;
	Set_Color(DEFAULT_COLOR); //������������û�Ĭ��ɫ
}
