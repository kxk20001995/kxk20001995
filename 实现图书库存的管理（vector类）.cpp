#include <iostream>
#include <vector>
using namespace std;
class Book
{
//请在此处补充Book类的定义
private:
    unsigned int m_ID, m_Page;
    string m_Name, m_Introduction, m_Author, m_Date;
public:
    Book();
    ~Book();

    void SetID(unsigned int id);
    unsigned int GetID();

    void SetName(string name);
    string GetName();

    void SetAuthor(string author);
    string GetAuthor();

    void SetIntroduction(string introduction);
    string GetIntroduction();

    void SetDate(string date);
    string GetDate();

    void SetPage(unsigned int page);
    unsigned int GetPage();

};
//请在此处补充Book类的成员函数实现
Book::Book() { this->m_ID = 0; }
Book::~Book() {}

void Book::SetID(unsigned int id) { this->m_ID = id; }
unsigned int Book::GetID() { return this->m_ID; }

void Book::SetName(string name) { this->m_Name = name; }
string Book::GetName() { return this->m_Name; }

void Book::SetAuthor(string author) { this->m_Author = author; }
string Book::GetAuthor() { return this->m_Author; }

void Book::SetIntroduction(string introduction) { this->m_Introduction = introduction; }
string Book::GetIntroduction() { return this->m_Introduction; }

void Book::SetDate(string date) { this->m_Date = date; }
string Book::GetDate() { return this->m_Date; }

void Book::SetPage(unsigned int page) { this->m_Page = page; }
unsigned int Book::GetPage() { return this->m_Page; }

class Store
{
//请在此处补充Store类的定义
private:
    vector<Book> m_pBook;
    unsigned int m_Count;
public:
    Store();
    Store(int n);
    ~Store();

    unsigned int GetCount();
    void in(Book& b);
    void out(string name);
    Book findbyName(string name);
    Book findbyID(int ID);
    void printList();

};
//请在此处补充Store类的成员函数实现
 #include<algorithm>
void Store::printList()
{
    cout << "There are totally " << this->m_Count << " Books:" << endl;
    for (unsigned int i = 0; i < this->m_Count; i++)
    {
        cout << "ID=" << m_pBook[i].GetID() << ";  " << "Name:" << m_pBook[i].GetName() << ";  " \
            << "Author:" << m_pBook[i].GetAuthor() << ";  "<<"Date:" << m_pBook[i].GetDate() \
           <<";" << endl;
    }
}

Book Store::findbyID(int ID)
{
   
    /*for (unsigned int i = 0; i < this->m_Count; i++)
    {
        if (ID == m_pBook[i].GetID())    return m_pBook[i];
    }*/
    vector<int> a;
    for (unsigned int i = 0; i < this->m_Count; i++) a.push_back(m_pBook[i].GetID());
    vector<int>::iterator result = find(a.begin(), a.end(), ID);
    if (result != a.end())
    {
        
        short int n = distance(a.begin(), result);
        return m_pBook[n];
    }
    else
    {
        Book a;
        a.SetID(0);
        return a;
    }
}

void Store::out(string name)
{
    for (unsigned int i = 0; i < this->m_Count; i++)
    {
        if (name == m_pBook[i].GetName())
        {
            for (; i < this->m_Count; i++)
            {
                if (i < this->m_Count - 1)   m_pBook[i] = m_pBook[i + 1];
            }
            this->m_Count--;
            return;
        }
    }
}

Book Store::findbyName(string name)
{
    /* for (unsigned int i = 0; i < this->m_Count; i++)
    {
        if (name == m_pBook[i].GetName())   return m_pBook[i];
    }*/
    vector<string> b;
    for (unsigned int i = 0; i < this->m_Count; i++) b.push_back(m_pBook[i].GetName());
    vector<string>::iterator result = find(b.begin(), b.end(), name);
    if (result == b.end())
    {
        Book a;
        a.SetID(0);
        return a;
    }
    else
    {
        short int n = distance(b.begin(), result);
        return m_pBook[n];
    }
}

void Store::in(Book& b) 
{
    m_Count++;
    m_pBook.push_back(b);
    /*m_pBook[m_Count - 1].SetID(b.GetID());
    m_pBook[m_Count - 1].SetName(b.GetName());
    m_pBook[m_Count - 1].SetAuthor(b.GetAuthor());
    m_pBook[m_Count - 1].SetIntroduction(b.GetIntroduction());
    m_pBook[m_Count - 1].SetDate(b.GetDate());
    m_pBook[m_Count - 1].SetPage(b.GetPage());*/
}

Store::Store()
{
    this->m_Count = 0;
    cout << "Store default constructor called!" << endl;
}

unsigned int Store::GetCount() { return this->m_Count; }

Store::Store(int n)
{
    this->m_Count = n;
    cout << "Store constructor with (int n) called!" << endl;
}

Store::~Store()
{
    m_Count = 0;
    {
        std::vector<Book>tmp;
        m_pBook.swap(tmp);
    }
    cout << "Store destructor called!" << endl;
}

int main()
{
    Store s;
    Book b1,b2,b3;
    b1.SetID(1);
    b1.SetName("C++ 语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout<<"第一本书入库"<<endl;
    s.in(b1);
    cout<<"第二本书入库"<<endl;
    s.in(b2);
    cout<<"第三本书入库"<<endl;
    s.in(b3);
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;
    cout <<"查找并出库图书：离散数学" << endl;
    Book tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
    {
        s.out("离散数学");
        cout <<"离散数学 已成功出库" << endl;
    }
    else
        cout<<"没有找到name为离散数学的书"<<endl;
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;

    cout <<"查找图书 ID：3" << endl;
    tmpbook=s.findbyID(3);
    if(tmpbook.GetID()!=0)
        cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
    else
        cout<<"没有找到ID为"<<3<<"的书"<<endl;

    cout <<"查找图书 name：离散数学" << endl;
    tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
        cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
    else
        cout<<"没有找到name为离散数学的书"<<endl;

    cout<<"输出所有库存图书的信息"<<endl;
    s.printList();
    cout<<"程序运行结束"<<endl;
    return 0;
}


