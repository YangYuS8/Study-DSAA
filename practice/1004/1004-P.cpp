#include <iostream>
using namespace std;
template<class T>
struct Node
{
    T data;
    Node<T> *next;
};
template <class T>
class LinkList
{
public:
    LinkList(); // 建立只有头结点的空链表
    ~LinkList(); // 析构函数
    int Length(); // 求单链表的长度
    int Locate(T x); // 求单链表中值为x的元素序号
    void Insert(int i, T x); // 在单链表中第i个位置插入元素值为x的结点
    void Reverse(); // reverse list
    void DispList(); // 遍历单链表，按序号依次输出各元素
private:
    Node<T> *first; // 单链表的头指针
};

template<class T>
LinkList<T>::LinkList()
{
    first = new Node<T>;
    first->next = NULL;
}

template<class T>
LinkList<T>::~LinkList()
{
    Node<T> *q = first;
    first = first->next;
    delete q;
}

template<class T>
int LinkList<T>::Length()
{
    int i = 0;
    Node<T> *p = first->next;
    while(p)
    {
        p = p->next;
        i++;
    }
    return i;
}

template<class T>
int LinkList<T>::Locate(T x)
{
    int j = 1;
    Node<T> *p = first->next;
    while(p)
    {
        if (p->data == x)
            return j;
        j++;
        p = p->next;
    }
    return 0;
}

template<class T>
void LinkList<T>::Insert(int i,T x)
{
    Node<T> *p = first;
    int count = 0;
    while(p&&count<i-1)//条件中有p是为了应对目标在链外的情况
    {
        p = p->next;
        count++;
    }//这个while循环是用来找i这个位置并确定其是否存在的
    //也就是说，这个循环会在找到目标位置的时候结束
    if(p==NULL)
        throw "None";
    //当上面的p指针发现已经空了都没找到目标时返回错误信息
    else
    {
        Node<T> *s = new Node<T>;//固定句式，为结点s分配空间
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

template<class T>
void LinkList<T>::Reverse()
{
    Node<T> *p = first->next;
    first->next = NULL;
    while(p)
    {
        Node<T> *q = p->next;
        p->next = first->next;
        first->next = p;
        p = q;
    }
}

template<class T>
void LinkList<T>::DispList()
{
    Node<T> *p = first->next;
    cout << "The length:" << Length() << endl;
    cout << "The elements:" << endl;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    LinkList<int> L1;
    int n;
    while(cin>>n&&n)
    {
        L1.Insert(1, n);
    }
    L1.DispList();
    int pos;
    cin >> pos;
    if(L1.Locate(pos))
        cout << "Found position:" << L1.Locate(pos) << endl;
    else
        cout << "No found" << endl;
    L1.Reverse();
    L1.DispList();
    return 0;
}