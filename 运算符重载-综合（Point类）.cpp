#include <iostream>
using namespace std;
class Point
{
private:
    int m_x, m_y;
public:
    Point(int x = 0, int y = 0)
    {
        m_x = x;
        m_y = y;
    }
    Point operator++();
    Point operator++(int);
    friend ostream& operator<<(ostream& out, const Point& a);
};

Point Point::operator++()
{
    ++m_x;
    ++m_y;
    return Point(this->m_x, this->m_y);
}

Point Point::operator++(int)
{
    Point fp;
    fp.m_x = this->m_x;
    fp.m_y = this->m_y;
    ++m_x;
    ++m_y;
    return fp;
}

ostream& operator<<(ostream& out, const Point& a)
{
    return out << '(' << a.m_x << ',' << a.m_y << ')' << endl;
}

int main()
{
    Point a(1,3);
    cout<<a;
    cout<<a++;
    cout<<++a;
    return 0;
}

