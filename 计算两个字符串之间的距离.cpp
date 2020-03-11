#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b;
	char s1[20], s2[20];
	cin>>s1>>s2;
	for(a=0; s1[a]!='\0'; a++) ;
	for(b=0; s2[b]!='\0'; b++) ;
	for(int i=0; i<a; i++)	if(s1[i]<91) s1[i]+=32;
	for(int i=0; i<b; i++)	if(s2[i]<91) s2[i]+=32;
	int min=fabs(s1[0]-s2[0]);
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			if(fabs(s1[i]-s2[j])<min) min=fabs(s1[i]-s2[j]);
			if(min==0) 
			{
				cout<<min;
				return 0;
			}
		}
	}
	cout<<min;
	return 0;
}

