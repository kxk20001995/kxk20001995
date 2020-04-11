#include <iostream>
#include <string>
using namespace std;

class CStudent
{
private:
    string name;
    int year;
public:
    static int count;
    CStudent(string name = "\0", int year = 0)
    {
        count += 1;
        this->name = name;
        this->year = year;
        if (year == 0) cout << "noname is contructing" << endl;
        else cout << name << " is contructing" << endl;
    }
    void printname()
    {
        if (this->year == 0) cout << "name:noname" << endl;
        else cout << "name:" << name << endl;
    }
    static int getcount()
    {
        return count;
    }
    ~CStudent()
    {
        count -= 1;
        if (this->year == 0) cout << "noname is destructing" << endl;
        else cout << name << " is destructing" << endl;
    }

};
//请在这里初始静态成员变量
int CStudent::count = 0;


int main()
{
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuB[5];
		stuB[4].printname();
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuA[2] = {CStudent("Tom", 3), CStudent("Jerry", 2)};
		for (int i = 0; i < 2; i++)
		{
			stuA[i].printname();
		}
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;

	return 0;
}

