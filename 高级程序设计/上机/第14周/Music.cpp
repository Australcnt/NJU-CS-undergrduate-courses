#include "Music.h"

//���캯��
//nameΪ�������ƣ�singerΪ���֣�countΪ����������dateΪ����ʱ�䣬nationΪ���й���
Music::Music(string name, string singer, int count, string date, string nation)
{
	this->name = name;
	this->singer = singer;
	this->count = count;
	this->date = date;
	this->nation = nation;
}

//��Ա���������ظ����ֵ�����
string Music::getName()
{
	return name;
}

//��Ա���������ظ����ֵĸ���
string Music::getSinger()
{
	return singer;
}

//��Ա���������ظ����ֵĵ�������
int Music::getCount()
{
	return count;
}

//��Ա���������ظ����ֵķ���ʱ��
string Music::getDate()
{
	return date;
}

//��Ա���������ظ����ֵķ��й���
string Music::getNation()
{
	return nation;
}

//��Ԫ������������������
ostream& operator << (ostream& out, const Music& music)
/* ˵��
* 1) �����������ơ����֡���������������ʱ�䡢���й��ҵĴ�������
* 2) ��ͬ��Ϣ֮���ö��ŷָ�
* 3) ����������� �� ���з�
*/
{
	out << music.name << ',' << music.singer << ',' << music.count << ',' << music.date << ',' << music.nation;
	return out;
}