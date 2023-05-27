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
            return i;
        i++;
        p = p->next;
    }
    return 0;
}

template<class T>
void LinkList<T>::Insert(int i,T x)
{
    
}