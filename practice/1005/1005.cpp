#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    Node<T> *next;
};
template <class T>
class LinkSortList
{
public:
    LinkSortList(); // 建立只有头结点的空链表
    ~LinkSortList(); // 析构函数
    void Insert(T x); // 在有序单链表中插入元素x使序列仍有序
    int Length(); // 求表长
    int DeleteOdd(); // 在单链表中删除所有奇数，返回值为奇数个数
    void DispList(); // 遍历有序单链表，按序号依次输出各元素
private:
    Node<T> *first; // 单链表的头指针
};

template <class T>
LinkSortList<T>::LinkSortList()
{
    first = new Node<T>;
    first->next = NULL;
}

template<class T>
LinkSortList<T>::~LinkSortList()
{
    Node<T> *q = first;
    first = first->next;
    delete q;
}

template<class T>
void LinkSortList<T>::Insert(T x)
{
    
}
int main()
{
    LinkSortList<int> sa;
    int x;
    while (1)
    {
        cin >> x;
        if (!x)
            break;
        sa.Insert(x);
    }
    sa.DispList();
    int count = sa.DeleteOdd();
    cout << "Count of deleted odds:" << count << endl;
    sa.DispList();
    return 0;
}