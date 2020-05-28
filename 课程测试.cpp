/*请编写一个程序，实现如下功能
a.txt文件中已经预先存储了一组数据，以空格分隔，数据的个数不确定。
从a.txt文件中读取数据，并将从小到大排序后的数据输出到b.txt文件
b.txt文件中数据以空格分隔*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int i = 0;
	double j = 0;
	vector<double>a;
	ifstream fin("a.txt");
	//do
	//{
	//	fin >> j;
	//	a.push_back(j);
	//} while (fin.eof() == 0);
	while(fin>>j) a.push_back(j);
	sort(a.begin(), a.end());
	fin.close();

	ofstream fout("b.txt");
	for (i = 0; i < (int)a.size(); i++) fout << a[i] << ' ';
	fout.close();

	return 0;
}
/*输入形式
输入文件名：a.txt

输出形式
输出文件名：b.txt*/