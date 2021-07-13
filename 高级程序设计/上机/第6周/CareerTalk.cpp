#define _CRT_SECURE_NO_WARNINGS
#include "CareerTalk.h"

// 构造函数，初始化CareerTalk对象
CareerTalk::CareerTalk(const char* company_name, int day, int start_time, int end_time)
{
	score_sum = 0;
	score_number = 0;
	open_flag = false;
	strcpy(_company_name, company_name);
	_day = day;
	_start_time = start_time;
	_end_time = end_time;
}
// 成员函数，返回宣讲会企业或机构名称
const char* CareerTalk::GetName()
{
	return _company_name;
}
// 成员函数，返回宣讲会举办日期
int CareerTalk::GetDay()
{
	return _day;
}
// 成员函数，返回宣讲会开始时间
int CareerTalk::GetStartTime()
{
	return _start_time;
}
// 成员函数，返回宣讲会结束时间
int CareerTalk::GetEndTime()
{
	return _end_time;
}
// 成员函数，修改宣讲会具体信息
void CareerTalk::AdjustInfo(int day, int start_time, int end_time)
{
	_day = day;
	_start_time = start_time;
	_end_time = end_time;
}
// 成员函数，开放这个宣讲会的预约通道
void CareerTalk::OpenAccess()
{
	open_flag = true;
}
// 成员函数，关闭这个宣讲会的预约通道
void CareerTalk::CloseAccess()
{
	open_flag = false;
}
// 成员函数，返回是否已开放预约
bool CareerTalk::IsOpen()
{
	return open_flag;
}
// 成员函数，对该宣讲会评分
void CareerTalk::Comment(int score)
{
	// 说明：score取值范围为[0, 10]，不考虑输出超过该范围的情况；毕业生随时可以对宣讲会评分
	score_sum += score;
	score_number++;
}
// 成员函数，返回该宣讲会的平均评分
float CareerTalk::GetScore()
{
	float average = float(((float)score_sum) / ((float)score_number));
	return average;
}