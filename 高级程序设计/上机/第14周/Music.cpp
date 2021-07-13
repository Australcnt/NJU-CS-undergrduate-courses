#include "Music.h"

//构造函数
//name为音乐名称，singer为歌手，count为点评人数，date为发行时间，nation为发行国家
Music::Music(string name, string singer, int count, string date, string nation)
{
	this->name = name;
	this->singer = singer;
	this->count = count;
	this->date = date;
	this->nation = nation;
}

//成员函数，返回该音乐的名称
string Music::getName()
{
	return name;
}

//成员函数，返回该音乐的歌手
string Music::getSinger()
{
	return singer;
}

//成员函数，返回该音乐的点评人数
int Music::getCount()
{
	return count;
}

//成员函数，返回该音乐的发行时间
string Music::getDate()
{
	return date;
}

//成员函数，返回该音乐的发行国家
string Music::getNation()
{
	return nation;
}

//友元函数，输出运算符重载
ostream& operator << (ostream& out, const Music& music)
/* 说明
* 1) 按照音乐名称、歌手、点评人数、发行时间、发行国家的次序排列
* 2) 不同信息之间用逗号分隔
* 3) 输出结果的最后 无 换行符
*/
{
	out << music.name << ',' << music.singer << ',' << music.count << ',' << music.date << ',' << music.nation;
	return out;
}