/*�����ʵ�ֹ��ܣ��������50��������λ������λС����ʵ�����ݣ�������Щ����д�뵽ָ���ļ��У�
Ҫ��д���ļ�����������֮���ÿո�ָ���
	[��ʾ]
	ָ��д��ʵ����setiosflags(ios::fixed)
	ָ��2λС���� setprecision(2)
���������Ƴ���ʵ�ֹ��ܣ�����ʵ�飨һ�����ֲ����������ļ�����������������Ϊż�������ݽ����޸ģ�
����Щ���ݵ����������޸�Ϊǡ�ñ�ԭ����С��������*/
#include<iostream>
#include<iomanip>
#include<random>
#include<ctime>
#include<fstream>
using namespace std;

int main()
{
	default_random_engine e(time(0));//���棬����������С�time(0)�����õ����ӣ���֤ÿ�β��������в�ͬ
	uniform_real_distribution<double> u(-1000, 1000);//�ֲ�

	double a;

	ofstream fout("b.txt");//������ļ����ڣ���򿪲����� д �������������ڣ��򴴽����ļ�
	ifstream fin("b.txt");//���ж�ȡ�ļ�����

	for (int i = 0, x = 0; i < 50; i++)
	{
		a = u(e);

		if (a<100.0 && a>-100.0)//�����������ΪС����λ�������������������
		{
			i--;
			continue;
		}

		x = int(a);//ǿ������ת����ȡ���������������
		if (x % 2 == 0) a = a - 1;//����������Ϊż���������������޸�Ϊǡ�ñ�ԭ����С������
		fout << setiosflags(ios::fixed) << setprecision(2) << a << endl;
	}

	fout.close();//�رմ��ļ�
	fin.close();
	return 0;
}