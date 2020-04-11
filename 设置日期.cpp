#include<iostream>
#include<cmath>
using namespace std;

class CTime
{
private:
    int year, month, day, hour, minute, second;
public:
    CTime(int NewYear, int NewMonth, int NewDay, int NewHour = 0, int NewMinute = 0, int NewSecond = 0);
    
    void showTime();
    int isvalid();
    int dayDiff(CTime &t);
    ~CTime();
};

CTime::~CTime() { cout << "析构函数被调用" << endl; }

int CTime::dayDiff(CTime& t)
{
    cout << "拷贝构造函数被调用" << endl;
    int m = 0, sum = 0, minYear = year, maxYear = year;
    if (year > t.year) minYear = t.year;
    else maxYear = t.year;
    if (abs(month - t.month) == 1) m += 31;      //2月份与1月份所差天数
    else if (abs(month - t.month) == 2) m += 31 + 27;         //3月份与1月份所差天数
    else if (abs(month - t.month) == 3) m += 31 + 27 + 31;     //4月份与1月份所差天数
    else if (abs(month - t.month) == 4) m += 31 + 27 + 31 + 30;     //5月份与1月份所差天数
    else if (abs(month - t.month) == 5) m += 31 + 27 + 31 + 30 + 31;     //6月份与1月份所差天数
    else if (abs(month - t.month) == 6) m += 31 + 27 + 31 + 30 + 31 + 30;     //7月份与1月份所差天数
    else if (abs(month - t.month) == 7) m += 31 + 27 + 31 + 30 + 31 + 30 + 31;     //8月份与1月份所差天数
    else if (abs(month - t.month) == 8) m += 31 + 27 + 31 + 30 + 31 + 30 + 31 + 31;     //9月份与1月份所差天数
    else if (abs(month - t.month) == 9) m += 31 + 27 + 31 + 30 + 31 + 30 + 31 + 31 + 30;     //10月份与1月份所差天数
    else if (abs(month - t.month) == 10) m += 31 + 27 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;     //11月份与1月份所差天数
    else if (abs(month - t.month) == 11) m += 31 + 27 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;     //12月份与1月份所差天数
    if (minYear >= 2000)
    {
        if (maxYear % 400 == 0 || (maxYear % 100 != 0 && maxYear % 4 == 0)) m += 1;
        sum = abs(year - t.year) / 4 + 1 + abs(year - t.year) * 365 + m + abs(day - t.day);
    }
    else sum = abs(year - t.year) / 4 + abs(year - t.year) * 365 - (m + abs(day - t.day));
    CTime::~CTime();
    return sum;
}

CTime::CTime(int NewYear, int NewMonth, int NewDay, int NewHour, int NewMinute, int NewSecond)
{
    year = NewYear;
    month = NewMonth;
    day = NewDay;
    hour = NewHour;
    minute = NewMinute;
    second = NewSecond;
    int data = 1, time = 1;
    if (year < 0 || month < 0 || month>12 || day < 0 || day>31) data = 0;
    if (hour < 0 || hour>23 || minute < 0 || minute>60 || second < 0 || second>60) time = 0;

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31) data = 0;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30) data = 0;
    }
    else if (month == 2)
    {
        if ((year % 400 == 0 || year % 100 != 0 && year % 4 == 0) && day > 29) data = 0;
        else if (!(year % 400 == 0 || year % 100 != 0 || year % 4 == 0) && day > 28) data = 0;
        if (hour >= 23 || minute >= 59 || second >= 59) time = 0;
    }

    if (data == 0 && time == 1) cout << "date error!" << endl;
    else if (data == 1 && time == 0) cout << "time error!" << endl;
    else if (data == 0 && time == 0) cout << "data and time error!" << endl;

    if (data == 0 || time == 0) year = month = day = hour = minute = second = 0;
    cout << "构造函数被调用" << endl;
}

void CTime::showTime()
{
    cout << year << '/' << month << '/' << day << ' ' << hour << ':' << minute << ':' << second << endl;
}

int CTime::isvalid()
{
    if (year != 0) return 1;
    else return 0;
}

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
//声明一个表示时间的类CTime，可以精确表示年、月、日、小时、分、秒，请计算两个日期对象之间相隔的天数。
//要求：
//1、包括私有成员年、月、日、小时、分、秒。
//
//2、请使用构造函数实现的类的初始化工作，并判断日期和时间的有效性。年月日时分秒应该在正确的范围内。考虑闰年时候二月份的情况。时间的格式是xx:xx:xx, 小时不是超过23，分钟和秒不能超过59。
//
//1）如果日期无效，则输出 “date error!”  并将年、月、日、小时、分、秒置为0。
//
//2）如果时间无效，则输出 “time error!”  并将年、月、日、小时、分、秒置为0。
//
//3）如果日期和时间都有效，则根据传递的参数初始化年、月、日、小时、分、秒。
//
//4）构造函数的三个参数：小时、分、秒 设计为默认形成，其默认值为0。
//
//5)  输出"构造函数被调用"
//
//3、请设计一个拷贝构造函数，实现将参数的值全部传递给当前对象，同时输出“拷贝构造函数被调用”
//
//4、请设计一个析构函数，同时输出“析构函数被调用”
//
//5、设计一个成员函数  int dayDiff(CTime t) ，用于计算当前对象与形参t之间的相隔的天数，注意相隔天数为大于等于0的正整数。注意闰年的问题。
//
//6、设计一个成员函数 showTime()，用于显示日期，显示格式为：2020 / 3 / 12 11:50 : 20
//提示：除了上传要求的成员函数外，你可以自由添加需要的成员函数。
//main函数已经给定，请补全其他代码。
//
//【样例输入1】
//2020 3 12 11 50 20

//【样例输出1】
//构造函数被调用
//
//2020 / 3 / 12 11:50 : 20
//
//构造函数被调用
//
//拷贝构造函数被调用
//
//析构函数被调用
//
//这两天之间相隔了7376天
//
//拷贝构造函数被调用
//
//析构函数被调用
//
//这两天之间相隔了7376天
//
//析构函数被调用
//
//析构函数被调用
//
//
//【样例输入2】
//
//2100 2 29 10 29 59
//【样例输出2】
//
//date error!
//
//构造函数被调用
//
//0 / 0 / 0 0:0 : 0
//
//构造函数被调用
//
//析构函数被调用
//
//析构函数被调用
//
//
//【样例输入3】
//
//2000 2 29 15 79 40
//【样例输出3】
//
//time error!
//
//构造函数被调用
//
//0 / 0 / 0 0:0 : 0
//
//构造函数被调用
//
//析构函数被调用
//
//析构函数被调用
//
//
//【样例输入4】
//
//2007 9 31 12 89 89
//【样例输出4】
//
//date and time error!
//
//构造函数被调用
//
//0 / 0 / 0 0:0 : 0
//
//构造函数被调用
//
//析构函数被调用
//
//析构函数被调用