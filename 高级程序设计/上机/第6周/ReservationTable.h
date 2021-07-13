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
	// ���캯������ʼ��ReservationTable����
	ReservationTable();
	// ��Ա������ԤԼĳ��CareerTalk������table
	bool AddTalk(CareerTalk* career_talk);
	// ��Ա������ȡ��ԤԼ
	bool CancelTalk(CareerTalk* career_talk);
	// ��Ա����������ĳ��ĳʱ�ľ���������
	CareerTalk* QueryTalk(int day, int time);
	// ��Ա����������ĳ���ж���ԤԼ�˵�������
	int TalksInADay(int day);
	// ��Ա����������ĳ���޸��˵���������Ϣ����table
	bool AdjustTalk(CareerTalk* career_talk);
};