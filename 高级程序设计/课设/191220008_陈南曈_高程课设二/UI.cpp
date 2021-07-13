#include "UI.h"

UI::UI()
{
	;
}

void UI::Set_Window() // 设置窗口相关参数
{
	SetConsoleTitleA("植物大战僵尸 - PlantsVsZombies by Australcnt"); // 设置窗口标题
	COORD buf_size = { WINDOW_LENGTH_X, WINDOW_LENGTH_Y }; // 设置窗口缓冲区大小
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), buf_size);
	//SMALL_RECT window_size = { 0,0, WINDOW_LENGTH_X - 1, WINDOW_LENGTH_Y - 1 }; // 设置窗口位置和大小
	//SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &window_size);
	char cmd[30];
	sprintf(cmd, "mode con cols=%d lines=%d", WINDOW_LENGTH_X, WINDOW_LENGTH_Y);
	system(cmd); //设置窗口宽度和高度
}

void UI::Hide_Cursor() // 隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1 ,false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void UI::Move_Cursor(const int x, const int y) // 设置光标位置
{
	COORD cursor_pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_pos);
}

void UI::Set_Color(int color) //设置颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void UI::Print_With_Color(const string& str, int color) // 带颜色的字符串输出
{
	Set_Color(color);
	cout << str;
	Set_Color(DEFAULT_COLOR); //输出结束后设置回默认色
}

void UI::Print_With_Color(int num, int color) // 带颜色的数字输出
{
	Set_Color(color);
	cout << num;
	Set_Color(DEFAULT_COLOR); //输出结束后设置回默认色
}
