/*�����ģ�⡰������Ϸ���Ĳ��׺ͱ�ע���׹��ܣ������Ҫ��Ϊ����ָ���������У�������϶�ŵ��ף�Ҫ����ʾʱ������*�ű�ʾ����Ȼ���������ڵ��׵����׷����б�ע�����ڵ��׵ĸ�������������ע��Ľ����������������ʵ�ֵ�Ҫ�����£�
�����Ĵ�С�ڳ������й�����ָ����
���׵ĸ����ڳ������й�����ָ����
���׹���ʹ���������ʵ�֣�
���׹��ܡ���ע���ף����ף����ܺ�������ܾ�ʹ�ö����ĺ�����ɣ�
[��ʾ]ʹ�ö�ά��̬�����ʾ����
*/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

//����
void mines_disposal(vector<vector<char> >& a, int const &width, int const &length, int const &num)
{
	vector<int>b;
	vector<int>c;

	srand((unsigned)time(NULL));
	int m, n, flag = 1;	//flag�����ж����������λ���Ƿ��Ѿ����ף�1��ʾ���ף�0��ʾ����

	for (int i = 0; i < num;flag = 1)	//i��ʾ ���� ���õڼ�����
	{
		m = rand() % width;		//���ȷ������
		n = rand() % length;	//���ȷ������

		if (i == 0)
		{
			a[m][n] = '*';

			//��¼�Ѱ��õ��ף����ڽ�����else������ж�
			b.push_back(m);
			c.push_back(n);

			i++;
		}
		else
		{
			for (int j = 0; j < i; j++)	//�жϴ�λ���Ƿ�����
			{
				if (m == b[j] && n == c[j]) flag = 0;
			}

			if (flag == 1)	//�����λ������
			{
				a[m][n] = '*';

				//��¼��λ��
				b.push_back(m);
				c.push_back(n);

				i++;
			}
			else continue;	//�����������һ��λ��
		}
	}
}

//��ע����
void marking_mines(vector<vector<char> >& a, int const& width, int const& length)	//�˴�&�� ����
{
	for (int i = 0, sum = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++, sum = 0)
		{
			if (a[i][j] == '*') continue;	//���a[i][j]λ�����ף�ֱ�ӽ�����һ��λ�õ��ж�

			if (i == 0)	//��һ��
			{
				if (j == 0)	//���Ͻǵ�һ��
				{
					if (a[i][j + 1] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i + 1][j + 1] == '*') sum++;
				}
				else if (j == length - 1)	//���Ͻ����һ��
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i + 1][j - 1] == '*') sum++;
				}
				else
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i][j + 1] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i + 1][j + 1] == '*') sum++;
					if (a[i + 1][j - 1] == '*') sum++;
				}
			}
			else if (i == width - 1)	//���һ��
			{
				if (j == 0)	//���½ǵ�һ��
				{
					if (a[i][j + 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i - 1][j + 1] == '*') sum++;
				}
				else if (j == length - 1)	//���½����һ��
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i - 1][j - 1] == '*') sum++;
				}
				else
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i][j + 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i - 1][j + 1] == '*') sum++;
					if (a[i - 1][j - 1] == '*') sum++;
				}
			}
			else	//��һ�������һ���м䲿��
			{
				if (j == 0)	//��һ��
				{
					if (a[i][j + 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i - 1][j + 1] == '*') sum++;
					if (a[i + 1][j + 1] == '*') sum++;
				}
				else if (j == length - 1)	//���һ��
				{
					if (a[i][j - 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i - 1][j - 1] == '*') sum++;
					if (a[i + 1][j - 1] == '*') sum++;
				}
				else	//��һ�������һ���м䲿��
				{
					if (a[i - 1][j - 1] == '*') sum++;
					if (a[i - 1][j] == '*') sum++;
					if (a[i - 1][j + 1] == '*') sum++;
					if (a[i][j - 1] == '*') sum++;
					if (a[i][j + 1] == '*') sum++;
					if (a[i + 1][j - 1] == '*') sum++;
					if (a[i + 1][j] == '*') sum++;
					if (a[i + 1][j + 1] == '*') sum++;
				}
			}
			a[i][j] = 48 + sum;	//a��char���ͣ�sum��int�ͣ�������Ҫǿ������ת��
		}
	}
}

//���
void output_a(vector<vector<char> >& a, int const& width, int const& length)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	//width���������������ж��١��С���length������������������ж��١��С�; num�ǵ��׸���
	int width, length, num;
	cin >> width >> length >> num;
	vector<vector<char> >a(width);
	//��ʼ������
	for (int i = 0; i < width; i++)
	{
		a[i].resize(length);
		for (int j = 0; j < length; j++)
		{
			a[i][j] = 0;
		}
	}

	//����
	mines_disposal(a, width, length, num);

	//��ע����
	marking_mines(a, width, length);

	//���
	output_a(a, width, length);
	return 0;
}