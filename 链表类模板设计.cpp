#include <iostream>
#include <iomanip>
using namespace std;

typedef struct listNode
{
    int data;
    listNode* next;
}listNode, *plistNode;

template<typename T>
class linkedList
{
private:
    plistNode head;
   int l;
public:
    bool initiate();
    void insert(int val);
    int Length();
    void print();
    bool remove(int n, int &val);
};

template<typename T>
bool linkedList<T>::initiate()
{
    head = (plistNode)malloc(sizeof(listNode));
    head->next = NULL;
    if (head->next == NULL) return true;
    else return false;
}

template<typename T>
void linkedList<T>::insert(int val)
{
    plistNode node = new listNode;
    node->data = val;
    node->next = NULL;

    plistNode p = head;
    while (p->next != NULL) p = p->next;
    
    node->next = p->next;
    p->next = node;
}

template<typename T>
bool linkedList<T>::remove(int n, int &val)
{
    if (n > this->Length())
    {
        cout << "pos > len, failed" << endl;
        return false;
    }
      else if (n <= 0)
    {
        cout << "pos <= 0, failed" << endl;
        return false;
    }
    else
    {
        plistNode p = head, q = head->next;
        int x = 1;
        while (x < n)
        {
            p = q;
            q = q->next;
            x++;
        }
        val = q->data;
        p->next = q->next;
        //q = q->next;  //若是此句，结果出错

        return true;
    }
}

template<typename T>
void linkedList<T>::print()
{
    if (head->next == NULL) return;

    plistNode p = head;
    while (p->next != NULL)
    {
        p = p -> next;
        cout << p->data << ' ';
    }
    cout << endl;
}
template<typename T>
int linkedList<T>::Length()
{
    plistNode p = head;
    l = 0;
    while (p->next != NULL)
    {
        p = p->next;
        l++;
    }
    return l;
}





int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}



