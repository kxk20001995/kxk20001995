#include<iostream>
#include<iomanip>
#include<cmath>
using  namespace  std;

const  double  PI = 3.1415926;

//请在此处完善类的设计
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
    cout << "油桶的容积是" << can.getvolumn() << "  " << endl;
    cout << "铁皮的面积是" << can.getarea() << endl;
}
/*某工厂使用一种圆柱形的铁桶来运输色拉油，但是关于该油桶的容量已经模糊，现在工人们测得了油桶直径和高（由键盘输入），请帮工人们计算一下油桶容量和制造该油桶需要的铁皮面积。

注意这个油桶是有盖的。铁皮的厚度忽略不计。

请设计一个类cylinder，该类具有私有成员 r和h，r表示半径，h表示高。该类还有3个公有成员，请根据给出的代码部分，分析并设计公有函数。



【输入形式】

输入包括一行，有两个浮点数，分别表示油桶的直径和高，中间用空格空开
【输出形式】

输入包括两行，有两个浮点数，分别为油桶的容量和铁皮面积，保留6位小数

【样例输入】

2.5 3

【样例输出】

油桶的容积是14.726215

铁皮的面积是33.379421*/