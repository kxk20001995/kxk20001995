/*编程序模拟“地雷游戏”的布雷和标注地雷功能，其具体要求为：在指定的雷区中，随机布上多颗地雷（要求显示时地雷用*号表示）；然后在有相邻地雷的无雷方格中标注出相邻地雷的个数；最后输出标注后的结果（雷区）。程序实现的要求如下：
雷区的大小在程序运行过程中指定；
地雷的个数在程序运行过程中指定；
布雷功能使用随机函数实现；
布雷功能、标注地雷（排雷）功能和输出功能均使用独立的函数完成；
[提示]使用二维动态数组表示雷区
*/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

//布雷
void mines_disposal(vector<vector<char> >& a, int const &width, int const &length, int const &num)
{
	vector<int>b;
	vector<int>c;

	srand((unsigned)time(NULL));
	int m, n, flag = 1;	//flag用于判断随机产生的位置是否已经有雷，1表示无雷，0表示有雷

	for (int i = 0; i < num;flag = 1)	//i表示 正在 安置第几个雷
	{
		m = rand() % width;		//随机确定行数
		n = rand() % length;	//随机确定列数

		if (i == 0)
		{
			a[m][n] = '*';

			//记录已安置的雷，用于接下来else里面的判断
			b.push_back(m);
			c.push_back(n);

			i++;
		}
		else
		{
			for (int j = 0; j < i; j++)	//判断此位置是否有雷
			{
				if (m == b[j] && n == c[j]) flag = 0;
			}

			if (flag == 1)	//如果此位置无雷
			{
				a[m][n] = '*';

				//记录此位置
				b.push_back(m);
				c.push_back(n);

				i++;
			}
			else continue;	//重新随机产生一个位置
		}
	}
}

//标注地雷
void marking_mines(vector<vector<char> >& a, int const& width, int const& length)	//此处&是 引用
{
	for (int i = 0, sum = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++, sum = 0)
		{
			if (a[i][j] == '*') continue;	//如果a[i][j]位置有雷，直接进行下一个位置的判断

			if (i == 0)	//第一行
			{
				if (j == 0)	//左上角第一个
				{
					if (a[i][j + 1] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i + 1][j + 1] == '*') sum++;
				}
				else if (j == length - 1)	//右上角最后一个
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i + 1][j - 1] == '*') sum++;
				}
				else
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i][j + 1] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i + 1][j + 1] == '*') sum++;
					if (a[i + 1][j - 1] == '*') sum++;
				}
			}
			else if (i == width - 1)	//最后一行
			{
				if (j == 0)	//左下角第一个
				{
					if (a[i][j + 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i - 1][j + 1] == '*') sum++;
				}
				else if (j == length - 1)	//右下角最后一个
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i - 1][j - 1] == '*') sum++;
				}
				else
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i][j + 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i - 1][j + 1] == '*') sum++;
					if (a[i - 1][j - 1] == '*') sum++;
				}
			}
			else	//第一行与最后一行中间部分
			{
				if (j == 0)	//第一列
				{
					if (a[i][j + 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i - 1][j + 1] == '*') sum++;
					if (a[i + 1][j + 1] == '*') sum++;
				}
				else if (j == length - 1)	//最后一列
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i - 1][j - 1] == '*') sum++;
					if (a[i + 1][j - 1] == '*') sum++;
				}
				else	//第一列与最后一列中间部分
				{
					if (a[i - 1][j - 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i - 1][j + 1] == '*') sum++;
					if (a[i][j - 1] == '*') sum++;
					if (a[i][j + 1] == '*') sum++;
					if (a[i + 1][j - 1] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i + 1][j + 1] == '*') sum++;
				}
			}
			a[i][j] = 48 + sum;	//a是char类型，sum是int型，所以需要强制类型转换
		}
	}
}

//输出
void output_a(vector<vector<char> >& a, int const& width, int const& length)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	//width是雷区宽，即数组有多少“行”；length是雷区长，即数组的有多少“列”; num是地雷个数
	int width, length, num;
	cin >> width >> length >> num;
	vector<vector<char> >a(width);
	//初始化数组
	for (int i = 0; i < width; i++)
	{
		a[i].resize(length);
		for (int j = 0; j < length; j++)
		{
			a[i][j] = 0;
		}
	}

	//布雷
	mines_disposal(a, width, length, num);

	//标注地雷
	marking_mines(a, width, length);

	//输出
	output_a(a, width, length);
	return 0;
}