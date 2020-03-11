#include <iostream>
#include<iomanip>
using namespace std;
void swap1(float *a, float *b)
{
float t;
t=*a;
*a=*b;
*b=t;

}


void swap2(float &a, float &b)
{
float  t;
t=a;
a=b;
b=t;

}


int main()
{
    float m,n;
    cin>>m>>n;
    swap1(&m, &n
);
    cout<<fixed<<setprecision(2)<<m<<" "<<n<<endl;
    swap2(m,  n
);
    cout<<fixed<<setprecision(2)<<m<<" "<<n<<endl;
    cin>>m;
}


