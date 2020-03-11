#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a, b, c, d;
	cin>>a>>b>>c>>d;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<a-c<<' '<<b-d;
	return 0;
}


