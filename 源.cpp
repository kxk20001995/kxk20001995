/*C++编写一个函数模拟动态分配数组的内存空间。
函数具有一个整型参数，它代表待分配的一个整型数组元素的个数。 
函数应当完成必要的出错检测（如参数为0或负数），
如果内存空间充足，那么就分配需要的空间，并返回指向该空间的 指针；否则返回一个空指针*/
#include<iostream>
#include<cstdlib>
#include<exception>
using namespace std;

int* p;		//全局变量

int* ARRAY(int x)
{
	if (x <= 0)		//出错检测
	{
		cout << "false!!!" << endl;
		exit(1);		//表示非正常运行导致退出程序
	}

	//try		
	//{
	//	p = new int[x];		//如果内存不够，返回NULL指针
	//}
	//catch (exception)
	//{
	//	int* p0 = NULL;
	//	cout << "指针申请失败，内存不足！！！" << endl;
	//	return p0;
	//}
	//cout << p << endl;
	//return p;

	//方法二：（内存不够时自动中止）
	if (p == NULL)
	{
		cout << "指针申请失败，内存不足！！！" << endl;
		cout << p << endl;
		delete[] p;		//释放p指针

		int* p0 = NULL;
		return p0;		//返回一个空指针
	}
	else
	{
		cout << p << endl;
		return p;
	}

	//你也可以使用vector或者malloc函数
}

int main()
{
	int x;
	cin >> x;		//确定ARRAY（）函数实参值
	ARRAY(x);
	delete[]p;		//释放p指针
	return 0;
}