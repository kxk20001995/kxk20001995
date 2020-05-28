/*编程序实现功能：随机产生50个具有三位整数两位小数的实型数据，并将这些数据写入到指定文件中，
要求写入文件的两个数据之间用空格分隔。
	[提示]
	指定写入实数：setiosflags(ios::fixed)
	指定2位小数： setprecision(2)
（二）编制程序实现功能：处理实验（一）部分产生的数据文件，将其中整数部分为偶数的数据进行修改，
把这些数据的整数部分修改为恰好比原数据小的奇数。*/
#include<iostream>
#include<iomanip>
#include<random>
#include<ctime>
#include<fstream>
using namespace std;

int main()
{
	default_random_engine e(time(0));//引擎，生成随机序列。time(0)是设置的种子，保证每次产生的序列不同
	uniform_real_distribution<double> u(-1000, 1000);//分布

	double a;

	ofstream fout("b.txt");//如果此文件存在，则打开并进行 写 操作；若不存在，则创建此文件
	ifstream fin("b.txt");//进行读取文件数据

	for (int i = 0, x = 0; i < 50; i++)
	{
		a = u(e);

		if (a<100.0 && a>-100.0)//如果整数部分为小于三位数，则重新生成随机数
		{
			i--;
			continue;
		}

		x = int(a);//强制类型转换，取随机数的整数部分
		if (x % 2 == 0) a = a - 1;//若整数部分为偶数，把整数部分修改为恰好比原数据小的奇数
		fout << setiosflags(ios::fixed) << setprecision(2) << a << endl;
	}

	fout.close();//关闭此文件
	fin.close();
	return 0;
}