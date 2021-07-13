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
	// ���캯������ʼ��CareerTalk����
	CareerTalk(const char* company_name, int day, int start_time, int end_time);
	// ��Ա������������������ҵ���������
	const char* GetName();
	// ��Ա����������������ٰ�����
	int GetDay();
	// ��Ա���������������Ὺʼʱ��
	int GetStartTime();
	// ��Ա�������������������ʱ��
	int GetEndTime();
	// ��Ա�������޸������������Ϣ
	void AdjustInfo(int day, int start_time, int end_time);
	// ��Ա��������������������ԤԼͨ��
	void OpenAccess();
	// ��Ա�������ر�����������ԤԼͨ��
	void CloseAccess();
	// ��Ա�����������Ƿ��ѿ���ԤԼ
	bool IsOpen();
	// ��Ա�������Ը�����������
	void Comment(int score);
	// ��Ա���������ظ��������ƽ������
	float GetScore();
};