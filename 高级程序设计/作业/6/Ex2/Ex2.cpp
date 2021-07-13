#include <iostream>

using namespace std;

enum TimeZone { W12 = -12, W11, W10, W9, W8, W7, W6, W5, W4, W3, W2, W1, GMT, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12 };

class Time
{
public:
	Time();
	Time(int h, int m, int s);
	void set(int h, int m, int s);
	void increment();
	void display();
	bool equal(Time& other_time);
	bool less_than(Time& other_time);
protected:
	int hour, min, sec;
};

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::Time(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}

void Time::set(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}

void Time::increment()
{
	if (sec == 59)
	{
		if (min == 59)
		{
			if (hour == 23)
				hour = min = sec = 0;
			else
			{
				hour++;
				min = sec = 0;
			}
		}
		else
		{
			min++;
			sec = 0;
		}
	}
	else
		sec++;
}

void Time::display()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

bool Time::equal(Time& other_time)
{
	return other_time.hour == hour && other_time.min == min && other_time.sec == sec;
}

bool Time::less_than(Time& other_time)
{
	int sub_hour, sub_min, sub_sec;
	sub_hour = other_time.hour - hour;
	sub_min = other_time.min - min;
	sub_sec = other_time.sec - sec;
	if (sub_hour > 0 || sub_hour == 0 && sub_min > 0 || sub_hour == 0 && sub_min == 0 && sub_sec > 0)
		return true;
	else
		return false;
}

class ExtTime :private Time
{
private:
	TimeZone timezone;
public:
	ExtTime(); //设置为GMT时间
	ExtTime(int h, int m, int s, TimeZone t); //构造函数
	void set(int h, int m, int s, TimeZone t); //调整时间
	void display();//展示时间，首先打印时区，再打印时间
	bool equal(const ExtTime& other_time); //判断是否相等
	bool less_than(const ExtTime& other_time);//判断是否小于
};

ExtTime::ExtTime() //设置为GMT时间
{
	hour = 0;
	min = 0;
	sec = 0;
	timezone = GMT;
}

ExtTime::ExtTime(int h, int m, int s, TimeZone t) //构造函数
{
	hour = h;
	min = m;
	sec = s;
	timezone = t;
}

void ExtTime::set(int h, int m, int s, TimeZone t) //调整时间
{
	Time::set(h, m, s);
	timezone = t;
}

void ExtTime::display() //展示时间，首先打印时区，再打印时间
{
	if (timezone == 0)
		cout << "GMT ";
	else
	{
		if (timezone < 0)
			cout << "W";
		else
			cout << "E";
		cout << abs(timezone) << " ";
	}
	Time::display();
}

bool ExtTime::equal(const ExtTime& other_time) //判断是否相等
{
	Time time1((hour + GMT - timezone) % 24, min, sec);
	Time time2((other_time.hour + GMT - other_time.timezone) % 24, other_time.min, other_time.sec);
	return time1.equal(time2);
}

bool ExtTime::less_than(const ExtTime& other_time) //判断是否小于
{
	Time time1((hour + GMT - timezone) % 24, min, sec);
	Time time2((other_time.hour + GMT - other_time.timezone) % 24, other_time.min, other_time.sec);
	return time1.less_than(time2);
}

int main()
{
	ExtTime time1(11, 32, 56, E5);
	time1.display();
	ExtTime time2(6, 23, 43, W2);
	time2.display();
	if (time1.less_than(time2))
		cout << "time1 < time2" << endl;
	return 0;
}
