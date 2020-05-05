#include <iostream>
using namespace std;
const float pi=3.14159;
class Shape
{
private:
	double m_ID;
public:
	Shape();
	Shape(double id);
	void set_m_ID(double m_ID);
	double get_m_ID();
	double getArea();
	~Shape();
};

Shape::Shape()
{
	this->m_ID = 0;
}

Shape::Shape(double id)
{
	this->m_ID = id;
	cout << "Shape constructor called:" << m_ID << endl;
}

void Shape::set_m_ID(double m_ID)
{
	this->m_ID = m_ID;
}

double Shape::get_m_ID()
{
	return m_ID;
}

double Shape::getArea()
{
	return 0;
}

Shape::~Shape() 
{
	cout << "Shape destructor called:" << m_ID << endl;
}

class Rectangle :public Shape
{
private:
	double h, w;
public:
	Rectangle();
	Rectangle(double i, double j,double k);
	void set(double h, double w);
	double getH();
	double getW();
	double getArea();
	~Rectangle();
};

Rectangle::Rectangle()
{
	this->h = this->w = 0;
}

Rectangle::Rectangle(double i, double j, double k):Shape(k)
{
	this->h = i;
	this->w = j;
	cout << "Rectangle constructor called:" << get_m_ID() << endl;
}

void Rectangle::set(double h, double w)
{
	this->h = h;
	this->w = w;
}

double Rectangle::getH()
{
	return h;
}

double Rectangle::getW()
{
	return w;
}

double Rectangle::getArea()
{
	return h * w;
}

Rectangle::~Rectangle()
{
	cout << "Rectangle destructor called:" << get_m_ID() << endl;
}

class Circle :public Shape
{
private:
	double r;
public:
	Circle();
	Circle(double i, double j);
	void setR(double r);
	double getR();
	double getArea();
	~Circle();
};

Circle::Circle()
{
	r = 0;
}

Circle::Circle(double i, double j):Shape(j)
{
	r = i;
	cout << "Circle constructor called:" << get_m_ID() << endl;
}

void Circle::setR(double r)
{
	this->r = r;
}

double Circle::getR()
{
	return r;
}

double Circle::getArea()
{
	return pi * r * r;
}

Circle::~Circle()
{
	cout << "Circle destructor called:" << get_m_ID() << endl;
}

int main()
{
    Shape s(1);//1表示ID
    Circle c(4,2);//4表示半径，2表示ID
    Rectangle r(4, 5,3);//4和5表示长和宽，3表示ID
    cout<<"Shape的面积"<<s.getArea()<<endl;
    cout<<"Circle的面积"<<c.getArea()<<endl;
    cout<<"Rectangle的面积"<<r.getArea()<<endl;
}

