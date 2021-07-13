#include <iostream>
#include <cmath>

using namespace std;

class Date
{
	friend class Datetime;
private:
	int _year, _month, _day;
public:
	Date() { _year = _month = _day = 0; }
	Date(int year, int month, int day);
};

class Time
{
	friend class Datetime;
private:
	int _hour, _minute, _second;
public:
	Time() { _hour = _minute = _second = 0; }
	Time(int hour, int minute, int second);
};

class Datetime
{
private:
	Date _date;
	Time _time;
public:
	Datetime(const Date& date, const Time& time);
	std::string to_string() const;
	// 可以不实现，帮助调试，格式如下
	// year.month.day/hour.minute.second.
	Datetime operator + (long) const; // 日期时间加秒数
	Datetime operator - (long) const; // 日期时间减秒数
	long operator - (const Datetime&) const; // 日期时间减日期时间
	Datetime& operator ++ (); // 日期时间加一秒
	Datetime& operator -- (); // 日期时间减一秒
	bool operator < (const Datetime&) const; // 比较日期时间大小
	bool operator == (const Datetime&) const; // 比较日期时间是否相等
	bool is_leapyear(int) const; // 判断是否为闰年
	int days_of_month(int, int) const; // 得到该月的天数
	void display() const; // 打印当前日期时间
};

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Time::Time(int hour, int minute, int second)
{
	_hour = hour;
	_minute = minute;
	_second = second;
}

Datetime::Datetime(const Date& date, const Time& time)
{
	_date = date;
	_time = time;
}

bool Datetime::is_leapyear(int year) const // 判断是否为闰年
{
	return (year % 4 == 0 && (year % 100 != 0)) || (year % 400 == 0);
}

int Datetime::days_of_month(int month, int year) const // 得到该月的天数
{
	switch(month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31; break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30; break;
	case 2:
		return 28 + is_leapyear(year); break;
	}
}

Datetime Datetime::operator + (long duration) const // 日期时间加秒数
{
	Datetime datetime(_date, _time);
	int day = duration / 86400;
	int hour = (duration % 86400) / 3600;
	int minute = (duration % 3600) / 60;
	int second = duration % 60;
	datetime._time._second += second;
	if (datetime._time._second > 60)
	{
		int add_minute = datetime._time._second / 60;
		datetime._time._second -= add_minute * 60;
		datetime._time._minute += add_minute;
	}
	datetime._time._minute += minute;
	if (datetime._time._minute > 60)
	{
		int add_hour = datetime._time._minute / 60;
		datetime._time._minute -= add_hour * 60;
		datetime._time._hour += add_hour;
	}
	datetime._time._hour += hour;
	if (datetime._time._hour > 24)
	{
		int add_day = datetime._time._hour / 24;
		datetime._time._hour -= add_day * 24;
		datetime._date._day += add_day;
	}
	datetime._date._day += day;
	while (datetime._date._day > days_of_month(datetime._date._month,datetime._date._year))
	{
		datetime._date._day -= days_of_month(datetime._date._month, datetime._date._year);
		datetime._date._month++;
		if (datetime._date._month > 12)
		{
			datetime._date._month -= 12;
			datetime._date._year++;
		}
	}
	return datetime;
}

Datetime Datetime::operator - (long duration) const // 日期时间减秒数
{
	Datetime datetime(_date, _time);
	int day = duration / 86400;
	int hour = (duration % 86400) / 3600;
	int minute = (duration % 3600) / 60;
	int second = duration % 60;
	datetime._time._second -= second;

	if (datetime._time._second < 0)
	{
		int minus_minute = abs(datetime._time._second / 60 - 1);
		datetime._time._second += minus_minute * 60;
		datetime._time._minute -= minus_minute;
	}
	datetime._time._minute -= minute;
	if (datetime._time._minute < 0)
	{
		int minus_hour = abs(datetime._time._minute / 60 - 1);
		datetime._time._minute += minus_hour * 60;
		datetime._time._hour -= minus_hour;
	}
	datetime._time._hour -= hour;
	if (datetime._time._hour < 0)
	{
		int minus_day = abs(datetime._time._hour / 24 - 1);
		datetime._time._hour += minus_day * 24;
		datetime._date._day -= minus_day;
	}
	datetime._date._day -= day;
	while (datetime._date._day < 0)
	{
		datetime._date._month--;
		if (datetime._date._month <= 0)
		{
			datetime._date._month += 12;
			datetime._date._year--;
		}
		datetime._date._day += days_of_month(datetime._date._month, datetime._date._year);
	}
	return datetime;
}

long Datetime::operator - (const Datetime& datetime) const // 日期时间减日期时间
{
	long duration = 0, duration1 = 0, duration2 = 0;
	for (int year1 = 0; year1 < _date._year; year1++)
	{
		if (is_leapyear(year1))
			duration1 += 366 * 86400;
		else
			duration1 += 365 * 86400;
	}
	for (int month1 = 1; month1 < _date._month; month1++)
	{
		duration1 += days_of_month(month1, _date._year) * 86400;
	}
	duration1 += _date._day * 86400 + _time._hour * 3600 + _time._minute * 60 + _time._second;
	for (int year2 = 0; year2 < datetime._date._year; year2++)
	{
		if (is_leapyear(year2))
			duration2 += 366 * 86400;
		else
			duration2 += 365 * 86400;
	}
	for (int month2 = 1; month2 < datetime._date._month; month2++)
	{
		duration2 += days_of_month(month2, datetime._date._year) * 86400;
	}
	duration2 += datetime._date._day * 86400 + datetime._time._hour * 3600 + datetime._time._minute * 60 + datetime._time._second;
	duration = duration1 - duration2;
	return duration;
}

Datetime& Datetime::operator ++ () // 日期时间加一秒
{
	*this = *this + 1;
	return *this;
}

Datetime& Datetime::operator -- () // 日期时间减一秒
{
	*this = *this - 1;
	return *this;
}

bool Datetime::operator < (const Datetime& datetime) const // 比较日期时间大小
{
	if (_date._year < datetime._date._year)
		return true;
	else if (_date._year > datetime._date._year)
		return false;
	if (_date._month < datetime._date._month)
		return true;
	else if (_date._month > datetime._date._month)
		return false;
	if (_date._day < datetime._date._day)
		return true;
	else if (_date._day > datetime._date._day)
		return false;
	if (_time._hour < datetime._time._hour)
		return true;
	else if (_time._hour > datetime._time._hour)
		return false;
	if (_time._minute < datetime._time._minute)
		return true;
	else if (_time._minute > datetime._time._minute)
		return false;
	if (_time._second < datetime._time._second)
		return true;
	else if (_time._second > datetime._time._second)
		return false;
	return false;
}

bool Datetime::operator == (const Datetime& datetime) const // 比较日期时间是否相等
{
	return _date._year == datetime._date._year && _date._month == datetime._date._month && _date._day == datetime._date._day && _time._hour == datetime._time._hour && _time._minute == datetime._time._minute && _time._second == datetime._time._second;
}

void Datetime::display() const // 打印当前日期时间
{
	cout << _date._year << '.' << _date._month << '.' << _date._day << '/' << _time._hour << '.' << _time._minute << '.' << _time._second << endl;
}

int main()
{
	Date date(2000, 12, 8);
	Time time(13, 14, 52);
	Datetime datetime(date, time), datetime1(date, time);
	datetime = datetime + 73821733;
	datetime.display();
	cout << datetime - datetime1 << endl;
	datetime = datetime - 73821733;
	datetime.display();
	++datetime;
	datetime.display();
	--datetime;
	datetime.display();
	return 0;
}