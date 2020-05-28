/*�����main��������exception��̳в����������쳣��MyException1��MyException2��
Ҫ����what��Ա��������what�����У�Ҫ��ʹ��typeid�����ص�ǰ�������ʱ�����͡�
����Ժͷ����ó����������չ����쳣������Ƶ�ʹ�á�*/

//�벹����ʵ�ͷ�ļ�
#include<iostream>
#include<exception>
#include<string>
#include<typeinfo>
using namespace std;

//�붨���쳣��MyException1
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

//�붨���쳣��MyException2
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

//�붨�庯��divide()���Գ�0���������쳣
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
/*��������ʽ��
����Ϊһ��1��������ȡֵ��1-4��
�������ʽ��
�����������
��һ��Ϊ������쳣��Ϣ
�ڶ���Ϊ��Return to main()

����������1��
1
���������1��
exception: 12MyException1
Return to main()

����������2��
2
���������2��
exception: 12MyException2
Return to main()

����������3��
3
���������3��
exception: 0
Return to main()

����������4��
4
���������4��
exception: basic_string::at: __n (which is 10) >= this->size() (which is 5)
Return to main()*/