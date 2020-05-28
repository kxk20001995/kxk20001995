/*封装一个模板数组类Array，支持以下操作：
1. 构造函数Array(int n)，将数组初始化为n个存储空间，建议使用vector；
2. 函数input(int n)，使用插入运算符<<读取数据，最多读取n个元素，但不能超过数组存储空间的上限；
3. 重载下标运算符，返回数组的元素。

封装一个分数类Fract，用来处理分数功能和运算，能支持你的Array类使用。
1. 构造：传入两个参数n和m，表示n/m；分数在构造时立即转化成最简分数。
提示：分数化简有专门的算法，可自行调研
2. show()函数：分数输出为“a/b”或“-a/b”的形式，a、b都是无符号整数。
若a为0或b为1，只输出符号和分子，不输出“/”和分母。
3. 在分数类上重载+=运算符，进行分数的加法运算。*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array
{
    //请完成类的设计
private:
    vector<T> a;
    unsigned int l;
public:
    Array(unsigned int n)
    {
        l = n;
    }

    void input(unsigned int n)
    {
        for (unsigned int i = 0; i < n && i < l; i++)
        {
            T x;
            cin >> x;
            a.push_back(x);
        }

    }

    T &operator[] (unsigned int &i)
    {
        return a[i];
    }
};

class Fract
{
    //请完成类的设计
private:
    int n, m;
public:
    Fract(){}
    Fract(int n, int m)
    {
        if (n != 0 && m != 0)
        {
            //辗转相除法
            int temp_n = n, temp_m = m, r;
            if (n < 0) temp_n = 0 - n;
            if (m < 0) temp_m = 0 - m;
            if (temp_n < temp_m) swap(temp_n, temp_m);
            while (temp_m > 0)
            {
                r = temp_n % temp_m;
                temp_n = temp_m;
                temp_m = r;
            }

            if ((n < 0 && m < 0)||(n > 0 && m < 0))
            {
                this->n = 0 - n / temp_n;
                this->m = 0 - m / temp_n;
            }
            else
            {
                this->n = n / temp_n;
                this->m = m / temp_n;
            }
        }
        else
        {
            this->n = n;
            this->m = m;
        }
    }

    void show()
    {
        if (n == 0) cout << 0 << endl;
        else if (m == 1) cout << n << endl;
        else cout << n << '/' << m << endl;
    }

    Fract &operator+= (Fract &p)
    {
        if (p.n != 0)
        {
            this->n = n * p.m + m * p.n;
            this->m = m * p.m;
        }
        Fract temp(n, m);//简化分数
        this->n = temp.n;
        this->m = temp.m;
        return *this;
    }

    friend istream& operator>>(istream& in, Fract& p);
};

istream& operator>>(istream& in, Fract& p)
{
    int i, j;
    in >> i >> j;
    Fract temp(i, j);
    p.n = temp.n;
    p.m = temp.m;
    return in;
}

int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
    {
        frsum += fr[i];
//        cout << frsum.n <<' '<<frsum.m << "   " << fr[i].n<<' '<<fr[i].m <<endl;
    }
    
    frsum.show();
}
/*
样例输入
4
6 8 7 5 
9 
1 3 20 -15 80 150 -9 1 6 6 12 16 -33 -48 6 11 0 -10

样例输出
26 
-17117/2640*/