/*请分析main函数，从exception类继承并派生两个异常类MyException1和MyException2，
要求定义what成员函数，在what函数中，要求使用typeid，返回当前类的运行时的类型。
请调试和分析该程序，熟练掌握关于异常捕获机制的使用。*/

//请补充合适的头文件
#include<iostream>
#include<exception>
#include<string>
#include<typeinfo>
using namespace std;

//请定义异常类MyException1
class MyException1 :public exception
{
public:
    const char * what() const throw()
    {
        MyException1 x;
//        return typeid(MyException1).name();
        return typeid(x).name();
//        return "12MyException1";
    }
};

//请定义异常类MyException2
class MyException2 :public exception
{
public:
    const char* what() const throw()
    {
//        MyException2 x;
        return typeid(MyException2).name();
//        return "12MyException2";
    }
};

//请定义函数divide()，对除0操作引发异常
int divide(int i, int e)
{
    if (e == 0) throw e;
    else return i / e;
}

int main()
{
    int  id, k;
    cin >> id;
    char  a;
    string  s = "hello";
    try
    {
        switch (id)
        {
        case  1:
            throw  MyException1();
            break;
        case  2:
            throw  MyException2();
            break;
        case  3:
            k = divide(8, 0);
            break;
        case  4:
            a = s.at(10);
            cout << a << endl;
            break;
        default:
            break;
        }
    }
    catch (MyException1& e)
    {
        cout << "exception: " << e.what() << endl;
    }
    catch (MyException2& e)
    {
        cout << "exception: " << e.what() << endl;
    }
    catch (int& e)
    {
        cout << "exception: " << e << endl;
    }
    catch (exception& e)
    {
        cout << "exception: " << e.what() << endl;
    }
    cout << "Return  to  main()" << endl;
	return 0;
}
/*【输入形式】
输入为一个1个整数，取值在1-4。
【输出形式】
输出包括两行
第一行为输出的异常信息
第二行为：Return to main()

【样例输入1】
1
【样例输出1】
exception: 12MyException1
Return to main()

【样例输入2】
2
【样例输出2】
exception: 12MyException2
Return to main()

【样例输入3】
3
【样例输出3】
exception: 0
Return to main()

【样例输入4】
4
【样例输出4】
exception: basic_string::at: __n (which is 10) >= this->size() (which is 5)
Return to main()*/