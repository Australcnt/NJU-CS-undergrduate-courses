#include "ReservationTable.h"

// ���캯������ʼ��ReservationTable����
ReservationTable::ReservationTable()
{
	;
}
// ��Ա������ԤԼĳ��CareerTalk������table
bool ReservationTable::AddTalk(CareerTalk* career_talk)
{
	if (career_talk->IsOpen() == false)
		return false;
	for(auto i=_career_talk.begin();i<_career_talk.end();i++)
	{
		if((*i)->GetDay()==career_talk->GetDay())
		{
			if (strcmp((*i)->GetName(), career_talk->GetName()) == 0)
				return false;
			if ((*i)->GetStartTime() < career_talk->GetEndTime() && (*i)->GetEndTime() > career_talk->GetStartTime())
				return false;
		}
	}
	_career_talk.push_back(career_talk);
	return true;
}
// ��Ա������ȡ��ԤԼ
bool ReservationTable::CancelTalk(CareerTalk* career_talk)
{
	for (auto i = _career_talk.begin(); i < _career_talk.end(); i++)
	{
		if ((*i) == career_talk)
		{
			_career_talk.erase(i);
			return true;
		}
	}
	return false;
}
// ��Ա����������ĳ��ĳʱ�ľ���������
CareerTalk* ReservationTable::QueryTalk(int day, int time)
{
	for (auto i = _career_talk.begin(); i < _career_talk.end(); i++)
	{
		if ((*i)->GetDay() == day)
		{
			if ((*i)->GetStartTime() <= time && (*i)->GetEndTime() > time)
				return *i;
		}
	}
	return NULL;
}
// ��Ա����������ĳ���ж���ԤԼ�˵�������
int ReservationTable::TalksInADay(int day)
{
	int counter = 0;
	for (auto i = _career_talk.begin(); i < _career_talk.end(); i++)
	{
		if ((*i)->GetDay() == day)
			counter++;
	}
	return counter;
}
// ��Ա����������ĳ���޸��˵���������Ϣ����table
bool ReservationTable::AdjustTalk(CareerTalk* career_talk)
{
	bool has_flag = false;
	for (auto i = _career_talk.begin(); i < _career_talk.end(); i++)
	{
		if ((*i) == career_talk)
		{
			has_flag = true;
			CancelTalk(career_talk);
		}
	}
	if (has_flag == false)
		return false;
	if (AddTalk(career_talk))
		return true;
	else
		return false;
}
/*
int main()
{
	
	// ��ʼ����������Ϣ����ѶУ�������ᰲ�����ܶ���9:00-11:00
	CareerTalk tencentTalk("Tencent", 2, 9, 11);
	// ��ѯ��Ϣ
	int day = tencentTalk.GetDay();
	int start_time = tencentTalk.GetStartTime();
	int end_time = tencentTalk.GetEndTime();
	// �޸���������Ϣ������������11:00-13:00
	tencentTalk.AdjustInfo(4, 11, 13);
	// ����ԤԼͨ��
	tencentTalk.OpenAccess();
	// ��ѯԤԼͨ���Ƿ���
	bool isOpen = tencentTalk.IsOpen();
	// ���������8�ֺ�10��
	tencentTalk.Comment(8);
	tencentTalk.Comment(10);
	// ��ȡ��������֣�Ԥ��Ϊ9�֣�
	float avgScore = tencentTalk.GetScore();
	// �ر�ԤԼͨ��
	tencentTalk.CloseAccess();
	



	CareerTalk talk1 = CareerTalk("Tencent QQ", 1, 8, 10);
	CareerTalk talk2 = CareerTalk("Alibaba", 2, 14, 16);
	CareerTalk talk3 = CareerTalk("Baidu", 3, 12, 15);
	talk1.OpenAccess();
	talk2.OpenAccess();
	// ��ʼ������
	ReservationTable table;
	// ԤԼ�����ᣬ���ݿ���ԤԼ�����в�ͬ�Ľ��
	bool addState1 = table.AddTalk(&talk1);
	bool addState2 = table.AddTalk(&talk2);
	bool addState3 = table.AddTalk(&talk3);
	// ��ѯ��һ9:00-10:00����������Ϣ
	CareerTalk* queryTalk = table.QueryTalk(1, 9);
	// ��ѯ��һԤԼ�˼���������
	int talkNum = table.TalksInADay(1);
	// ����������ʱ�䣬�����ͻ���Զ�ȡ��ԤԼ���Ķ��������ᣬ����ͻ��table�е���������Ϣ����
	talk1.AdjustInfo(4, 15, 17);
	bool adjustState = table.AdjustTalk(&talk1);
	talk1.AdjustInfo(2, 15, 17);
	adjustState = table.AdjustTalk(&talk1);
	// ȡ��ԤԼ
	bool cancelState = table.CancelTalk(&talk2);
}*/