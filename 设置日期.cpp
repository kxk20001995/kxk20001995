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

CTime::~CTime() { cout << "��������������" << endl; }

int CTime::dayDiff(CTime& t)
{
    cout << "�������캯��������" << endl;
    int m = 0, sum = 0, minYear = year, maxYear = year;
    if (year > t.year) minYear = t.year;
    else maxYear = t.year;
    if (abs(month - t.month) == 1) m += 31;      //2�·���1�·���������
    else if (abs(month - t.month) == 2) m += 31 + 27;         //3�·���1�·���������
    else if (abs(month - t.month) == 3) m += 31 + 27 + 31;     //4�·���1�·���������
    else if (abs(month - t.month) == 4) m += 31 + 27 + 31 + 30;     //5�·���1�·���������
    else if (abs(month - t.month) == 5) m += 31 + 27 + 31 + 30 + 31;     //6�·���1�·���������
    else if (abs(month - t.month) == 6) m += 31 + 27 + 31 + 30 + 31 + 30;     //7�·���1�·���������
    else if (abs(month - t.month) == 7) m += 31 + 27 + 31 + 30 + 31 + 30 + 31;     //8�·���1�·���������
    else if (abs(month - t.month) == 8) m += 31 + 27 + 31 + 30 + 31 + 30 + 31 + 31;     //9�·���1�·���������
    else if (abs(month - t.month) == 9) m += 31 + 27 + 31 + 30 + 31 + 30 + 31 + 31 + 30;     //10�·���1�·���������
    else if (abs(month - t.month) == 10) m += 31 + 27 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;     //11�·���1�·���������
    else if (abs(month - t.month) == 11) m += 31 + 27 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;     //12�·���1�·���������
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
    cout << "���캯��������" << endl;
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
    CTime  t2(2000, 1, 1);  //����Ĭ���βν�ʱ���ʼ��Ϊ00:00:00
    if (t1.isvalid())          //������ں�ʱ��Ϸ������������
    {
        int  days = 0;
        days = t1.dayDiff(t2);
        cout << "������֮�������" << days << "��" << endl;
        days = t2.dayDiff(t1);
        cout << "������֮�������" << days << "��" << endl;
    }
}
//����һ����ʾʱ�����CTime�����Ծ�ȷ��ʾ�ꡢ�¡��ա�Сʱ���֡��룬������������ڶ���֮�������������
//Ҫ��
//1������˽�г�Ա�ꡢ�¡��ա�Сʱ���֡��롣
//
//2����ʹ�ù��캯��ʵ�ֵ���ĳ�ʼ�����������ж����ں�ʱ�����Ч�ԡ�������ʱ����Ӧ������ȷ�ķ�Χ�ڡ���������ʱ����·ݵ������ʱ��ĸ�ʽ��xx:xx:xx, Сʱ���ǳ���23�����Ӻ��벻�ܳ���59��
//
//1�����������Ч������� ��date error!��  �����ꡢ�¡��ա�Сʱ���֡�����Ϊ0��
//
//2�����ʱ����Ч������� ��time error!��  �����ꡢ�¡��ա�Сʱ���֡�����Ϊ0��
//
//3��������ں�ʱ�䶼��Ч������ݴ��ݵĲ�����ʼ���ꡢ�¡��ա�Сʱ���֡��롣
//
//4�����캯��������������Сʱ���֡��� ���ΪĬ���γɣ���Ĭ��ֵΪ0��
//
//5)  ���"���캯��������"
//
//3�������һ���������캯����ʵ�ֽ�������ֵȫ�����ݸ���ǰ����ͬʱ������������캯�������á�
//
//4�������һ������������ͬʱ������������������á�
//
//5�����һ����Ա����  int dayDiff(CTime t) �����ڼ��㵱ǰ�������β�t֮��������������ע���������Ϊ���ڵ���0����������ע����������⡣
//
//6�����һ����Ա���� showTime()��������ʾ���ڣ���ʾ��ʽΪ��2020 / 3 / 12 11:50 : 20
//��ʾ�������ϴ�Ҫ��ĳ�Ա�����⣬��������������Ҫ�ĳ�Ա������
//main�����Ѿ��������벹ȫ�������롣
//
//����������1��
//2020 3 12 11 50 20

//���������1��
//���캯��������
//
//2020 / 3 / 12 11:50 : 20
//
//���캯��������
//
//�������캯��������
//
//��������������
//
//������֮�������7376��
//
//�������캯��������
//
//��������������
//
//������֮�������7376��
//
//��������������
//
//��������������
//
//
//����������2��
//
//2100 2 29 10 29 59
//���������2��
//
//date error!
//
//���캯��������
//
//0 / 0 / 0 0:0 : 0
//
//���캯��������
//
//��������������
//
//��������������
//
//
//����������3��
//
//2000 2 29 15 79 40
//���������3��
//
//time error!
//
//���캯��������
//
//0 / 0 / 0 0:0 : 0
//
//���캯��������
//
//��������������
//
//��������������
//
//
//����������4��
//
//2007 9 31 12 89 89
//���������4��
//
//date and time error!
//
//���캯��������
//
//0 / 0 / 0 0:0 : 0
//
//���캯��������
//
//��������������
//
//��������������