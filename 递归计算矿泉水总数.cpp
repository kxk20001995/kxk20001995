#include<iostream>
using namespace std;
int kkk(int a, int b)
{
	if(a<2&&b<3) return 0;
	else	return a/2+b/3+kkk(a%2+a/2+b/3, b%3+a/2+b/3);
}
int main()
{
	int x;
	cin>>x;
	cout<<x+kkk(x, x);
	return 0;
}


