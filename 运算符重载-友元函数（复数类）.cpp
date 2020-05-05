#include <iostream>
using namespace std;
class Complex
{
private:
    double real, image;
public:
    Complex(double a = 0.0, double b = 0.0);
    friend Complex operator +(Complex a, Complex b);
    friend Complex operator -(Complex a, Complex b);
    void print();
};

Complex::Complex(double a, double b)
{
    real = a;
    image = b;
}

Complex operator +(Complex a, Complex b)
{
    return Complex(a.real + b.real, a.image + b.image);
}

Complex operator -(Complex a, Complex b)
{
    return Complex(a.real - b.real, a.image - b.image);
}

void Complex::print()
{
    cout << "(" << real << ")" << "+" << "(" << image << "i" << ")" << endl;
}

int main()
{
    Complex a(3,4),b(1,-1),c;
    c=a+b;
    cout<<"a+b=";
    c.print();
    cout<<endl;
    c=a-b;
    cout<<"a-b=";
    c.print();
    cout<<endl;
    c=a+100;
    cout<<"a+100=";
    c.print();
    cout<<endl;
    c=a-2.5;
    cout<<"a-2.5=";
    c.print();
    cout<<endl;
    c=100+a;
    cout<<"100+a=";
    c.print();
    cout<<endl;
    c=2.5-a;
    cout<<"2.5-a=";
    c.print();
    cout<<endl;
    return 0;
}


