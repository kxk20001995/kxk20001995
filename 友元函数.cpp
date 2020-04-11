#include <iostream>
using namespace std;
//请在这里补充类Boat和Car的定义
class Car;

class Boat
{
private:
    int weight;

public:
    Boat(int Weight)
    {
        this->weight = Weight;
    }
    friend int totalweight(Boat& b, Car& c);
};

class Car
{
private:
    int weight;

public:
    Car(int Weight)
    {
        this->weight = Weight;
    }
    friend int totalweight(Boat& b, Car& c);
};

int totalweight(Boat& b,Car& c)
{
    return b.weight+c.weight;
}
int main()
{
    Boat b(100);
    Car c(200);
    cout<<totalweight( b, c)<<endl;
    return 0;
}


