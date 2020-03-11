#include<iostream>
using namespace std;
int main()
{
	char s[9], x;
	int i, j, flag=1;
	cin >>s;
	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++) 
		{
			if(i==j) continue;
			if(s[i]==s[j]) 
			{
				cout<<"No Answer";
				return 0;
			}
			else if(s[j]==s[i]-(j-i)||s[j]==s[i]+j-i)
			{
				cout<<"No Answer";
				return 0;
			}
		}
	}
	for(x='1'; x<='8'; x++, flag=1)
	{
		for(j=0; j<8; j++) if(x==s[j]) flag=0;
		if(flag==1) 
		{
			cout<<x;
			break;
		}
	}
	return 0;
}



