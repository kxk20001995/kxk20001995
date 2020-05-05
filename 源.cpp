/*编程序输出魔方矩阵。魔方矩阵是一个n×n奇数矩阵，其中n2个元素分别是1,2,3,…, n2，并且任意一行、任意一列以及主副对角线的所有数之和均相等，且都等于n(n2+1)/2。
[提示]魔方矩阵数字排列规则如下：
1.	数字1在矩阵的第一行中间一列；
2.	从数字2到n2的各数依次存放在比前一个数行数减一、列数加一的位置（即前一个数的右上角位置）；
3.	若上一个数在第一行，则下一个数在做后一行；
4.	若上一个数在最后一列，下一个数在第一列；
5.	如果按上述规则寻找的位置上已经放置有数，则将数字放在上一个数的下面。
三阶魔方矩阵如下图所示：
8	1	6
3	5	7
4	9	2
*/ 

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, row, column, temp_row, temp_column;
	cin >> n;
	vector<vector<int> >a(n);	//动态定义n行的二维数组
	for (int i = 0; i < n; i++)	//初始化数组
	{
		for (int j = 0; j < n; j++) a[i].push_back(0);
	}

	a[0][n / 2] = 1;
	row = 0;
	column = n / 2;	//记录元素的行(row)和列(column)
	for (int num = 2; num <= n * n; num++)
	{
		temp_row = row;
		temp_column = column;		//temp_row记录上一个数的行，temp_column记录上一个数的列

		if (row == 0) row = n - 1;	//若上一个数在第一行，则下一个数在做后一行
		else row -= 1;	//比前一个数行数减一

		if (column == n - 1) column = 0;	//若上一个数在最后一列，下一个数在第一列
		else column += 1;	//比前一个数列数加一

		if (a[row][column] != 0)	//如果按规则寻找的位置上已经放置有数，则将数字放在上一个数的下面
		{
			if (temp_row == n - 1) row = 0;	//如果row在最后一行，则下一个数在第一行
			else row = temp_row + 1;	//否则将数字放在上一个数的下面

			column = temp_column;	//将这个数还原到与上一个数的列数相同

			a[row][column] = num;
		}
		else a[row][column] = num;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
		cout << endl;
	}

	return 0;
}
