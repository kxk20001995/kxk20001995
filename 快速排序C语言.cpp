#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int *a, int *b,int left, int right)
{
	if(left>=right) return ;
	srand((unsigned)time(NULL));
	int i=left, j=right, m=rand()%(right-left+1)+left,t;	//运用随机数防止过多次无意义排序
	
	t=a[left];
	a[left]=a[m];
	a[m]=t;
	t=b[left];
	b[left]=b[m];
	b[m]=t;
	
	int key=a[left], key1=b[left];
	while(i<j) 
	{
	    while(i<j&&key<=a[j]) j--;
	    a[i]=a[j];
	    b[i]=b[j];
	    while(i<j&&key>=a[i]) i++;
	    a[j]=a[i];
	    b[i]=b[j];
	}
	a[i] = key;
	b[i]=key1;
	sort(a, b,left, i-1);
	sort(a, b, i+1, right);
}
int main()
{
	int n,i,f=1;
	scanf("%d",&n);
	int a[n],b[n];
	scanf("%d",&a[0]);
	for(i=1;i<n;i++) 
	{
		scanf("%d",&a[i]);
		b[i]=i+1;	//b[i]记录a[i]原来所输入的顺序
		if(a[i]<a[i-1]) f=0;
	}
	if(f!=1) sort(a,b,0,n-1);     //a[i]排序，但是其原来编号不变，所以版b[i]也传入sort,
	for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
} 
