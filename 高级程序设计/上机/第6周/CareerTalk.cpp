#define _CRT_SECURE_NO_WARNINGS
#include "CareerTalk.h"

// ���캯������ʼ��CareerTalk����
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
// ��Ա������������������ҵ���������
const char* CareerTalk::GetName()
{
	return _company_name;
}
// ��Ա����������������ٰ�����
int CareerTalk::GetDay()
{
	return _day;
}
// ��Ա���������������Ὺʼʱ��
int CareerTalk::GetStartTime()
{
	return _start_time;
}
// ��Ա�������������������ʱ��
int CareerTalk::GetEndTime()
{
	return _end_time;
}
// ��Ա�������޸������������Ϣ
void CareerTalk::AdjustInfo(int day, int start_time, int end_time)
{
	_day = day;
	_start_time = start_time;
	_end_time = end_time;
}
// ��Ա��������������������ԤԼͨ��
void CareerTalk::OpenAccess()
{
	open_flag = true;
}
// ��Ա�������ر�����������ԤԼͨ��
void CareerTalk::CloseAccess()
{
	open_flag = false;
}
// ��Ա�����������Ƿ��ѿ���ԤԼ
bool CareerTalk::IsOpen()
{
	return open_flag;
}
// ��Ա�������Ը�����������
void CareerTalk::Comment(int score)
{
	// ˵����scoreȡֵ��ΧΪ[0, 10]����������������÷�Χ���������ҵ����ʱ���Զ�����������
	score_sum += score;
	score_number++;
}
// ��Ա���������ظ��������ƽ������
float CareerTalk::GetScore()
{
	float average = float(((float)score_sum) / ((float)score_number));
	return average;
}