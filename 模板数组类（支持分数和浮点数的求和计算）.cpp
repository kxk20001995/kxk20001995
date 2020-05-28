/*��װһ��ģ��������Array��֧�����²�����
1. ���캯��Array(int n)���������ʼ��Ϊn���洢�ռ䣬����ʹ��vector��
2. ����input(int n)��ʹ�ò��������<<��ȡ���ݣ�����ȡn��Ԫ�أ������ܳ�������洢�ռ�����ޣ�
3. �����±�����������������Ԫ�ء�

��װһ��������Fract����������������ܺ����㣬��֧�����Array��ʹ�á�
1. ���죺������������n��m����ʾn/m�������ڹ���ʱ����ת������������
��ʾ������������ר�ŵ��㷨�������е���
2. show()�������������Ϊ��a/b����-a/b������ʽ��a��b�����޷���������
��aΪ0��bΪ1��ֻ������źͷ��ӣ��������/���ͷ�ĸ��
3. �ڷ�����������+=����������з����ļӷ����㡣*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Array
{
    //�����������
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
    //�����������
private:
    int n, m;
public:
    Fract(){}
    Fract(int n, int m)
    {
        if (n != 0 && m != 0)
        {
            //շת�����
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
        Fract temp(n, m);//�򻯷���
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
��������
4
6 8 7 5 
9 
1 3 20 -15 80 150 -9 1 6 6 12 16 -33 -48 6 11 0 -10

�������
26 
-17117/2640*/