/*���дһ������ʵ�����¹���
a.txt�ļ����Ѿ�Ԥ�ȴ洢��һ�����ݣ��Կո�ָ������ݵĸ�����ȷ����
��a.txt�ļ��ж�ȡ���ݣ�������С�������������������b.txt�ļ�
b.txt�ļ��������Կո�ָ�*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int i = 0;
	double j = 0;
	vector<double>a;
	ifstream fin("a.txt");
	//do
	//{
	//	fin >> j;
	//	a.push_back(j);
	//} while (fin.eof() == 0);
	while(fin>>j) a.push_back(j);
	sort(a.begin(), a.end());
	fin.close();

	ofstream fout("b.txt");
	for (i = 0; i < (int)a.size(); i++) fout << a[i] << ' ';
	fout.close();

	return 0;
}
/*������ʽ
�����ļ�����a.txt

�����ʽ
����ļ�����b.txt*/