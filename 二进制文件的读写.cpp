/*���дһ������ʵ�����¹���
1������ṹ��student, ����stu_id,score 2������������stu_id��һ��short�ͱ�����scoreΪshort�ͱ�����
2���Ӽ�������ѧ������n��n��ѧ�������ݣ��洢��new����������a��
3��ʹ��write�������Զ�������ʽ����a�����д�ŵ�n��ѧ��һ��д��out.txt�ļ��У���Ҫʹ��ѭ����
4��ʹ��read�������Զ�������ʽ��ʹ��ѭ����ʽ����out.txt��ÿ�ζ���һ��ѧ����Ϣ���洢��new����������b��
5��ʹ��write���������ı���ʽ����b�����д�ŵ�n��ѧ��һ��д��out.txt�ļ��У�
Ҫ����ӵ��ļ�ĩβ����Ҫʹ��ѭ����*/
#include<iostream>
#include<fstream>
#include<cassert>
using namespace std;

//����ṹ��student, ����stu_id,score 2������������stu_id��һ��short�ͱ�����scoreΪshort�ͱ�����
struct student
{
	short stu_id;
	short score;
};

int main()
{
	//�Ӽ�������ѧ������n��n��ѧ�������ݣ��洢��new����������a��
	int n, i;
	cin >> n;
	student * a = new student[n];
	for (i = 0; i < n; i++) cin >> a[i].stu_id >> a[i].score;

	//ʹ��write�������Զ�������ʽ����a�����д�ŵ�n��ѧ��һ��д��out.txt�ļ��У���Ҫʹ��ѭ����
	ofstream fout("out.txt", ios::out | ios::binary);
	fout.write(reinterpret_cast<char*>(a), sizeof(a));
	fout.close();

//ʹ��read�������Զ�������ʽ��ʹ��ѭ����ʽ����out.txt��ÿ�ζ���һ��ѧ����Ϣ���洢��new����������b��
	student* b = new student[n];
	ifstream fin("out.txt", ios::out | ios::binary);
	for (int i = 0; i < n; i++)
	{
		
		fin.read(reinterpret_cast<char*>(&b[i]), sizeof(a[i]));
	}
	fin.close();

	//ʹ��write���������ı���ʽ����b�����д�ŵ�n��ѧ��һ��д��out.txt�ļ��У�
	//Ҫ����ӵ��ļ�ĩβ����Ҫʹ��ѭ����
	ofstream fout2("out.txt");
	fout.seekp(-1, ios::end);
	fout2.write(reinterpret_cast<char*>(b), sizeof(b));
	fout.close();

	return 0;
}
/*������ʽ
�����һ������������ʾ��n��ѧ��
�����2��n+1����ѧ����Ϣ��ÿ�б�ʾһ��ѧ����stu_id,score
�����ʽ
����ļ�����out.txt�����а���2�������Ϣ
���뷶��
2
1011 90
1012 68
�������
��*/