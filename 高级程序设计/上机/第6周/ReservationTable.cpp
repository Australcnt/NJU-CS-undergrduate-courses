#include "ReservationTable.h"

// 构造函数，初始化ReservationTable对象
ReservationTable::ReservationTable()
{
	;
}
// 成员函数，预约某个CareerTalk并更新table
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
// 成员函数，取消预约
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
// 成员函数，返回某天某时的具体宣讲会
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
// 成员函数，返回某天有多少预约了的宣讲会
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
// 成员函数，根据某个修改了的宣讲会信息更新table
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
	
	// 初始化宣讲会信息，腾讯校招宣讲会安排在周二的9:00-11:00
	CareerTalk tencentTalk("Tencent", 2, 9, 11);
	// 查询信息
	int day = tencentTalk.GetDay();
	int start_time = tencentTalk.GetStartTime();
	int end_time = tencentTalk.GetEndTime();
	// 修改宣讲会信息，调整到周四11:00-13:00
	tencentTalk.AdjustInfo(4, 11, 13);
	// 开放预约通道
	tencentTalk.OpenAccess();
	// 查询预约通道是否开启
	bool isOpen = tencentTalk.IsOpen();
	// 给宣讲会打8分和10分
	tencentTalk.Comment(8);
	tencentTalk.Comment(10);
	// 获取宣讲会均分（预期为9分）
	float avgScore = tencentTalk.GetScore();
	// 关闭预约通道
	tencentTalk.CloseAccess();
	



	CareerTalk talk1 = CareerTalk("Tencent QQ", 1, 8, 10);
	CareerTalk talk2 = CareerTalk("Alibaba", 2, 14, 16);
	CareerTalk talk3 = CareerTalk("Baidu", 3, 12, 15);
	talk1.OpenAccess();
	talk2.OpenAccess();
	// 初始化对象
	ReservationTable table;
	// 预约宣讲会，根据开放预约与否会有不同的结果
	bool addState1 = table.AddTalk(&talk1);
	bool addState2 = table.AddTalk(&talk2);
	bool addState3 = table.AddTalk(&talk3);
	// 查询周一9:00-10:00的宣讲会信息
	CareerTalk* queryTalk = table.QueryTalk(1, 9);
	// 查询周一预约了几场宣讲会
	int talkNum = table.TalksInADay(1);
	// 调整宣讲会时间，如果冲突则自动取消预约被改动的宣讲会，不冲突则将table中的宣讲会信息更新
	talk1.AdjustInfo(4, 15, 17);
	bool adjustState = table.AdjustTalk(&talk1);
	talk1.AdjustInfo(2, 15, 17);
	adjustState = table.AdjustTalk(&talk1);
	// 取消预约
	bool cancelState = table.CancelTalk(&talk2);
}*/