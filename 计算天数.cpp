#include<iostream>
#include<cmath>
using namespace std;
class CTime
{
private:
	int year = 0, month = 0, day = 0, hour = 0,minute = 0, second = 0;

public:
	int daysinmonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int flag,flag2;

	int judgeyear(int year)                                                      //判断年丰是否是闰年
{
	if (year % 4 == 0 && year % 100 != 0)return 1;
	else if (year % 400 == 0)return 1;
	else return 0;
}


	int isvalid()      //判断日期的合法性
{
		if (hour <= 23 && minute <= 59 && second <= 59)flag2 = 1;
		else flag2 = 0;
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:if (day <= 31) { flag = 1;return 1; }
				else { flag = 0;return 0; } break;
		case 4:
		case 6:
		case 9:
		case 11:if (day <= 30)
		{
			flag = 1; return 1;
		}
				else
		{
			flag = 0;
			return 0;
		}break;
			
		
		case 2:if (judgeyear(year) && day <= 29) 
		{
			flag = 1; return 1;
		}
			   else if (judgeyear(year) == 0 && day <= 28)
		{
			flag = 1; return 1;
		}
			   else 
		{
			flag = 0;
			return 0;
		} break;
		default: 
		{
			flag = 0;
			return 0;
		} break;
		}
}


	CTime(int input_year,int input_month,int input_day,int input_hour = 0,int input_minute = 0,int input_second = 0)     //构造函数
	{
		year = input_year;
		month = input_month;
		day = input_day;
		hour = input_hour;
		minute = input_minute;
		second = input_second;
		
		isvalid();
		if (flag2 == 0 && flag == 1)
		{
			cout << "time error!" << endl;
			year = month = day = minute = hour = second = 0;
		}
		else if (flag == 0 && flag2 == 1)
		{
			cout << "date error!" << endl;
			year = month = day = minute = hour = second = 0;
		}
		else if (flag == 0 && flag2 == 0)
		{
			cout << "date and time error!" << endl;
			year = month = day = minute = hour = second = 0;
		}
		cout << "构造函数被调用" << endl;
	}
	CTime(CTime &t)     //构造函数
	{
		cout << "拷贝构造函数被调用" << endl;
		year = t.year;
		month = t.month;
		day = t.day;
		hour = t.hour;
		minute = t.minute;
		second = t.second;
	}


	~CTime()                         //析构函数
	{
		cout << "析构函数被调用" << endl;
	}


	void showTime()                  //显示时间
	{
			cout << year << '/' << month << '/' << day << ' ' << hour << ':' << minute << ':' << second << endl;
	}
	int daysinyear(int year,int month,int day)
	{
		int days = day;
		if (judgeyear(year))
		{
			daysinmonth[1] = 29;
			for (month - 1; month >= 1; month--)
			{
				days += daysinmonth[month - 1];
			}
		}
		else 
			for (month - 1; month >= 1; month--)
			{
				days += daysinmonth[month - 1];
			}
		return days;


	}

	int dayDiff(CTime t)
	{
		int dayDiff = 0;                                                   //同年同月
		if (year == t.year && month == t.month)
			dayDiff = day > t.day ? day - t.day : t.day - day;



		else if (year == t.year && month != t.month)                   //同年不同月
		{
			int day1, day2;
			day1 = daysinyear(year,month,day);
			day2 = daysinyear(t.year, t.month, t.day);
			dayDiff = day1 > day2 ? day1 - day2 : day2 - day1;
		}



		else                                                        //年份月份都不同
		{
			int dayleave;              //当年余下的天数
			int dayhave;              //当年的第几天  
			int year1, year2, month1, month2, day1, day2;
			if (year > t.year)
			{
				year1 = year; year2 = t.year; month1 = month; month2 = t.month; day1 = day; day2 = t.day; 
			}
			else
			{
				year2 = year; year1 = t.year; month2 = month; month1 = t.month; day2 = day; day1 = t.day;
			}
			dayhave = daysinyear(year1, month1, day1);
			dayDiff += dayhave;
			if (judgeyear(year2) == 1)
				dayleave = 366 - daysinyear(year2, month2, day2);
			else 
				dayleave = 365 - daysinyear(year2, month2, day2);
			dayDiff += dayleave;
			for (year2; year2 < year1 - 1; year2++)
			{
				if (judgeyear(year2+1))dayDiff += 366;
				else dayDiff += 365;
			}
			
		}
		return dayDiff;

	}

};
int  main()
{
	int  year, month, day, hour, minute, second;
	cin >> year >> month >> day >> hour >> minute >> second;
	CTime  t1(year, month, day, hour, minute, second);
	t1.showTime();
	CTime  t2(2000, 1, 1);  //利用默认形参将时间初始化为00:00:00 
	if (t1.isvalid())          //如果日期和时间合法，则计算天数 
	{
		int  days = 0;
		days = t1.dayDiff(t2);
		cout << "这两天之间相隔了" << days << "天" << endl;
		days = t2.dayDiff(t1);
		cout << "这两天之间相隔了" << days << "天" << endl;
	}
}