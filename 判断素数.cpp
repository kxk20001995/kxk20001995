#include <iostream>
#include <cmath>
using namespace std;
int  isPrime( int  a )
{
     if(a==1)  return 0;
     if(a==2)  return  1;
     int  i=0;
     double m=sqrt(a);
     if(a%2==0)  return 0;
     for(i=2; i<=m; i++)
     {
          if(a%i==0)  return 0;
     }
     return 1;
}

int main()
{
    unsigned short a;
    cin>>a;
    if (isPrime(a))
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;
}

