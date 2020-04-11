#include <iostream>
using namespace std;
//请在这里补充CPoint，CRectangle类的定义
class CPoint
{

public:
    int a, b;

    CPoint(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
        cout << "CPoint contstructor with default value(0,0) is called." << endl;
    }

    ~CPoint(){}
};

class CRectangle
{
private:
    int x, y;
    
public:
    CRectangle()
    {
        for (int i = 0; i < 2; i++) cout << "CPoint contstructor with default value(0,0) is called." << endl;
        this->x = 0;
        this->y = 0;
        cout << "CRectangle default contstructor is called." << endl;
    }
    CRectangle(CPoint &m, CPoint &n)
    {
        for (int i = 0; i < 4; i++) cout << "CPoint copy contstructor is called." << endl;
        this->x = n.a - m.a;
        this->y = n.b - m.b;
        cout << "CRectangle contstructor with (CPoint,CPoint) is called." << endl;
    }
    CRectangle(int a, int b, int c, int d)
    {
        for (int i = 0; i < 2; i++) cout << "CPoint contstructor with default value(0,0) is called." << endl;
        this->x = c - a;
        this->y = d - b;
        cout << "CRectangle contstructor with (int,int,int,int) is called." << endl;
    }
    CRectangle(CRectangle& a)
    {
        for (int i = 0; i < 2; i++) cout << "CPoint copy contstructor is called." << endl;
        this->x = a.x;
        this->y = a.y;
        cout << "CRectangle copy contstructor is called." << endl;
    }
    int GetArea()
    {
        return x * y;
    }
};


int main()
{
    int a=1, b=1, c=6, d=11;
    cout<<"# Define p1 ######"<<endl;
    CPoint p1;
    cout<<"# Define p2 ######"<<endl;
    CPoint p2(10,20);
    cout<<"# Define rect1 ######"<<endl;
    CRectangle rect1;
    cout<<"# Define rect2 ######"<<endl;
    CRectangle rect2(p1, p2);
    cout<<"# Define rect3 ######"<<endl;
    CRectangle rect3(a, b, c, d);
    cout<<"# Define rect4 ######"<<endl;
    CRectangle rect4(rect2);
    cout<<"# Calculate area ######"<<endl;
    cout << "rect1面积为" << rect1.GetArea() << endl;
    cout << "rect2面积为" << rect2.GetArea() << endl;
    cout << "rect3面积为" << rect3.GetArea() << endl;
    cout << "rect4面积为" << rect4.GetArea() << endl;
    system("pause");
    return 0;
}



