#pragma once
#include <iostream>
#include <vector>
#include "CareerTalk.h"

using namespace std;

class ReservationTable
{
private:
	vector<CareerTalk*>_career_talk;
public:
	// 构造函数，初始化ReservationTable对象
	ReservationTable();
	// 成员函数，预约某个CareerTalk并更新table
	bool AddTalk(CareerTalk* career_talk);
	// 成员函数，取消预约
	bool CancelTalk(CareerTalk* career_talk);
	// 成员函数，返回某天某时的具体宣讲会
	CareerTalk* QueryTalk(int day, int time);
	// 成员函数，返回某天有多少预约了的宣讲会
	int TalksInADay(int day);
	// 成员函数，根据某个修改了的宣讲会信息更新table
	bool AdjustTalk(CareerTalk* career_talk);
};