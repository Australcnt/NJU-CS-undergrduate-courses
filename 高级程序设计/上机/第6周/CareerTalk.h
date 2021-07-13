#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class CareerTalk
{
private:
	char _company_name[100];
	int _day;
	int _start_time;
	int _end_time;
	bool open_flag;
	int score_sum;
	int score_number;
public:
	// 构造函数，初始化CareerTalk对象
	CareerTalk(const char* company_name, int day, int start_time, int end_time);
	// 成员函数，返回宣讲会企业或机构名称
	const char* GetName();
	// 成员函数，返回宣讲会举办日期
	int GetDay();
	// 成员函数，返回宣讲会开始时间
	int GetStartTime();
	// 成员函数，返回宣讲会结束时间
	int GetEndTime();
	// 成员函数，修改宣讲会具体信息
	void AdjustInfo(int day, int start_time, int end_time);
	// 成员函数，开放这个宣讲会的预约通道
	void OpenAccess();
	// 成员函数，关闭这个宣讲会的预约通道
	void CloseAccess();
	// 成员函数，返回是否已开放预约
	bool IsOpen();
	// 成员函数，对该宣讲会评分
	void Comment(int score);
	// 成员函数，返回该宣讲会的平均评分
	float GetScore();
};