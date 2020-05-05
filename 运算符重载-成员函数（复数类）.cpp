#include <iostream>
using namespace std;

class Complex
{
private:
    double real, image;
public:
    Complex(double a = 0.0, double b = 0.0);
    Complex operator +(Complex a);
    Complex operator -(Complex a);
    void print();
};

Complex::Complex(double a, double b)
{
    real = a;
    image = b;
}

Complex Complex::operator +(Complex a)
{
    return Complex(this->real + a.real, this->image + a.image);
}

Complex Complex::operator -(Complex a)
{
    return Complex(this->real - a.real, this->image - a.image);
}

void Complex::print()
{
    cout << real << "+" << image << "i" << endl;
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

    return 0;
}


