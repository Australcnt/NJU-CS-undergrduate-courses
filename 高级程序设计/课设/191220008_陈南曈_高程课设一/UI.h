#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

/*尺寸信息*/
const int WINDOW_LENGTH_X = 156;
const int WINDOW_LENGTH_Y = 44;

const int SWARD_NUM_X = 9;
const int SWARD_NUM_Y = 5;
const int SWARD_LENGTH_X = 14;
const int SWARD_LENGTH_Y = 6;

const int PLANTCARD_LENGTH_X = 25;
const int PLANTCARD_LENGTH_Y = 1;

const int STORE_LENGTH_X = 156;
const int STORE_LENGTH_Y = 7;



/*颜色信息*/
const int DEFAULT_COLOR = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;

const int FOREGROUND_SELECTED_COLOR = FOREGROUND_GREEN | FOREGROUND_RED;
const int BACKGROUND_SELECTED_COLOR = BACKGROUND_GREEN | BACKGROUND_RED | DEFAULT_COLOR;

const int COOLDOWN_COLOR = BACKGROUND_BLUE | BACKGROUND_GREEN | DEFAULT_COLOR;
const int TIP_COLOR = BACKGROUND_BLUE | DEFAULT_COLOR;

const int PEASHOOTER_COLOR = BACKGROUND_GREEN | DEFAULT_COLOR;
const int SUNFLOWER_COLOR = BACKGROUND_GREEN | BACKGROUND_RED | DEFAULT_COLOR;


class UI
{
public:
	UI();
	static void Set_Window(); // 设置窗口相关参数
	static void Hide_Cursor(); // 隐藏光标
	static void Move_Cursor(const int x, const int y); // 设置光标位置
	static void Set_Color(int color); // 设置颜色
	static void Print_With_Color(const string& str, int color); // 带颜色的字符串输出
	static void Print_With_Color(int num, int color); // 带颜色的数字输出
};