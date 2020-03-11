#include <iostream>
#include <cmath>
using namespace std;

int isPrime(long num)
{
	if(num<=3) return 1;
	for(int i=2; i<=sqrt(num); i++) if(num%i==0) return 0;
	return 1;
}

void factorization(long n, long *f, int &num)
{
	if(isPrime(n)) 
	{
		f[num]=n;
		num++;
	}
	else 
	{
		int i;
		for(i=2; i<=sqrt(n); i++)
		{
			if(n%i==0)
			{
				f[num]=i;
				++num;
				factorization(n/i, f, num);
				break;
			}
		}
	}
    return;
}

int main()
{
    long n;
    long factor[100];
    int numofFactor = 0;
    cin >> n;
    factorization(n, factor, numofFactor);
    for (int i = 0; i < numofFactor; i++)
    {
        cout << factor[i] << " ";
    }
    cout << endl;
    return 0;
}

