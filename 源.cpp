#include<iostream>
#include<string>
#include<cmath>
using namespace std;

void change(char& x, int &n, int& num, int& l, int& i)
{
	if (48 <= x && x <= 57) num = num + (x - 48) * pow(n, l - i - 1);
	else num = num + (x - 55) * pow(n, l - i - 1);
}

int main()
{
	int n, m;
	cin >> n;

	string s;
	cin >> s;

	cin >> m;

	int num = 0;
	int l = s.length();

	for (int i = 0; s[i] != '\0'; i++) change(s[i], n, num, l, i);
	
	string s1="";
	int r;

	do
	{
		r = num % m;
		num = num / m;

		if(r == 0) s1.insert(0, "0");
		else if (r == 1) s1.insert(0, "1");
		else if (r == 2) s1.insert(0, "2");
		else if (r == 3) s1.insert(0, "3");
		else if (r == 4) s1.insert(0, "4");
		else if (r == 5) s1.insert(0, "5");
		else if (r == 6) s1.insert(0, "6");
		else if (r == 7) s1.insert(0, "7");
		else if (r == 8) s1.insert(0, "8");
		else if (r == 9) s1.insert(0, "9");
		else if (r == 10) s1.insert(0, "A");
		else if (r == 11) s1.insert(0, "B");
		else if (r == 12) s1.insert(0, "C");
		else if (r == 13) s1.insert(0, "D");
		else if (r == 14) s1.insert(0, "E");
		else if (r == 15) s1.insert(0, "F");
	} while (num != 0);

	cout << s1 << endl;
	return 0;
}
