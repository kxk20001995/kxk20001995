/*C++��дһ������ģ�⶯̬����������ڴ�ռ䡣
��������һ�����Ͳ�����������������һ����������Ԫ�صĸ����� 
����Ӧ����ɱ�Ҫ�ĳ����⣨�����Ϊ0��������
����ڴ�ռ���㣬��ô�ͷ�����Ҫ�Ŀռ䣬������ָ��ÿռ�� ָ�룻���򷵻�һ����ָ��*/
#include<iostream>
#include<cstdlib>
#include<exception>
using namespace std;

int* p;		//ȫ�ֱ���

int* ARRAY(int x)
{
	if (x <= 0)		//������
	{
		cout << "false!!!" << endl;
		exit(1);		//��ʾ���������е����˳�����
	}

	//try		
	//{
	//	p = new int[x];		//����ڴ治��������NULLָ��
	//}
	//catch (exception)
	//{
	//	int* p0 = NULL;
	//	cout << "ָ������ʧ�ܣ��ڴ治�㣡����" << endl;
	//	return p0;
	//}
	//cout << p << endl;
	//return p;

	//�����������ڴ治��ʱ�Զ���ֹ��
	if (p == NULL)
	{
		cout << "ָ������ʧ�ܣ��ڴ治�㣡����" << endl;
		cout << p << endl;
		delete[] p;		//�ͷ�pָ��

		int* p0 = NULL;
		return p0;		//����һ����ָ��
	}
	else
	{
		cout << p << endl;
		return p;
	}

	//��Ҳ����ʹ��vector����malloc����
}

int main()
{
	int x;
	cin >> x;		//ȷ��ARRAY��������ʵ��ֵ
	ARRAY(x);
	delete[]p;		//�ͷ�pָ��
	return 0;
}