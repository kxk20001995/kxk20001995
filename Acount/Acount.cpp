#include <iostream>
#include <iomanip>
using namespace std;
//���ڴ˴�����Account��Ķ���
class Account
{
private:
    string account;
    string name;
    string sex;
    int age;
    double money;
public:
    void init(string init_account, string init_name, string init_sex, int init_age, double init_money)
    {
        account = init_name;
        name = init_name;
        sex = init_sex;
        age = init_age;
        if (init_money * 100 > int(init_money * 100))
        {
            cout << "������Ľ��Ϸ�" << endl;
            money = 0;
        }
        else money = init_money;
    }
    void printmoney()
    {
        cout << name << "�Ĵ��Ϊ" << fixed << setprecision(2) << money << endl;
    }
    void deposit(double m)
    {
        if (m * 100 > int(m * 100)) cout << "������Ľ��Ϸ�" << endl;
        else money += m;
    }
    void withdraw(double n)
    {
        if (n * 100 > int(n * 100)) cout << "������Ľ��Ϸ�" << endl;
        else if (n > money) cout << "���Ĵ�����" << endl;
        else money -= n;
    }
};


int main()
{
    Account tom;
    tom.init("32020320011001876X", "Tom Black", "��", 19, 2000.89);
    tom.printmoney();//�����Tom Black�Ĵ��Ϊ2000.89
    tom.deposit(89.471);//�����������Ľ��Ϸ�
    tom.printmoney();//�����Tom Black�Ĵ��Ϊ2000.89
    tom.deposit(10000);
    tom.printmoney();//�����Tom Black�Ĵ��Ϊ12000.89
    tom.withdraw(10001);
    tom.printmoney();//�����Tom Black�Ĵ��Ϊ1999.89
    tom.withdraw(10000.123);//�����������Ľ��Ϸ�
    tom.printmoney();//�����Tom Black�Ĵ��Ϊ1999.89
    tom.withdraw(10000.9);//��������Ĵ�����
    tom.printmoney();//�����Tom Black�Ĵ��Ϊ1999.89
    Account jerry;
    jerry.init("320203200910116569", "Jerry Black", "Ů", 11, 100.956);//�����������Ľ��Ϸ�
    jerry.printmoney();//�����Jerry Black�Ĵ��Ϊ0.00
}
