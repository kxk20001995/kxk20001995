#include<iostream>
#include<iomanip>
#include<cmath>
using  namespace  std;

const  double  PI = 3.1415926;

//���ڴ˴�����������
class cylinder
{
private:
    double r, h;
public:
    void init(double inith, double initr)
    {
        h = inith;
        r = initr;
    }
    double getvolumn()
    {
        return PI * r * r * h;
    }
    double getarea()
    {
        return 2 * PI * r * r + 2 * PI * r * h;
    }
};

int  main()
{
    double  d, h;
    cin >> d >> h;
    cylinder can;
    can.init(h, d / 2);
    cout << fixed << setprecision(6);
    cout << "��Ͱ���ݻ���" << can.getvolumn() << "  " << endl;
    cout << "��Ƥ�������" << can.getarea() << endl;
}
/*ĳ����ʹ��һ��Բ���ε���Ͱ������ɫ���ͣ����ǹ��ڸ���Ͱ�������Ѿ�ģ�������ڹ����ǲ������Ͱֱ���͸ߣ��ɼ������룩����﹤���Ǽ���һ����Ͱ�������������Ͱ��Ҫ����Ƥ�����

ע�������Ͱ���иǵġ���Ƥ�ĺ�Ⱥ��Բ��ơ�

�����һ����cylinder���������˽�г�Ա r��h��r��ʾ�뾶��h��ʾ�ߡ����໹��3�����г�Ա������ݸ����Ĵ��벿�֣���������ƹ��к�����



��������ʽ��

�������һ�У����������������ֱ��ʾ��Ͱ��ֱ���͸ߣ��м��ÿո�տ�
�������ʽ��

����������У����������������ֱ�Ϊ��Ͱ����������Ƥ���������6λС��

���������롿

2.5 3

�����������

��Ͱ���ݻ���14.726215

��Ƥ�������33.379421*/