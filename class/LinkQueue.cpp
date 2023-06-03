#include<iostream>
using namespace std;
template<class T>
struct Node
{
    T data;
    Node<T>* next;
};

template<class T>
class LinkQueue
{
private:
    Node<T>* front;
    Node<T>* rear;
public:
    LinkQueue();
    ~LinkQueue();
    void EnQueue(T x);//入队
    T DeQueue();//出队
    T GetQueue();//取队头元素
    int Empty();//判空
    void PrintQueue();//输出队列
};

template<class T>
LinkQueue<T>::LinkQueue()
{
    front = new Node<T>;
    front->next = NULL;
    rear = front;
}

template<class T>
LinkQueue<T>::~LinkQueue()
{
    Node<T>* p;
    while(front != NULL)//循环删除队列中的元素
    {
        p = front;
        front = front->next;//front指向下一个元素
        delete p;
    }
}

template<class T>
void LinkQueue<T>::EnQueue(T x)
{
    //入队：插入到队尾--rear
    Node<T>* s = new Node<T>;
    s->data = x;
    s->next = rear->next;//s->next = NULL
    rear->next = s;
    rear = rear->next; // rear = s, rear随时指向队尾
}

template<class T>
T LinkQueue<T>::DeQueue()
{
    //出队：删除队头元素--front->next
    if(front == rear)
    {
        throw "队空";
    }
    Node<T>* s = front->next;//s指向队头元素,即要删除的元素
    T x = s->data;//保存要删除的元素
    if(s->next == NULL)//如果s是队尾元素，删除后队列为空
    {
        rear = front;
    }
    front->next = s->next;//删除s
    delete s;
    return x;
}

template<class T>
T LinkQueue<T>::GetQueue()
{
    //取队头元素
    if(front == rear)
    {
        throw "队空";
    }
    return front->next->data;//返回队头元素
}

template<class T>
void LinkQueue<T>::PrintQueue()
{
    cout << "队列中的元素为：";
    Node<T>* p = front->next;//p指向队头元素
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template<class T>
int LinkQueue<T>::Empty()
{
    //判空
    if(front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    try
    {
        LinkQueue<int> Q;
        int x;
        cin >> x;
        while (x != 0)
        {
            Q.EnQueue(x);
            cin >> x;
        }
        Q.PrintQueue();
        cout << "出队元素为：" << Q.DeQueue() << endl;
        Q.PrintQueue();
        cout << "取队头的元素为：" << Q.GetQueue() << endl;
        Q.PrintQueue();
        x = Q.Empty();
        if(x == 1)
        {
            cout << "队列元素为空" << endl;
        }
        else if(x == 0)
        {
            cout << "队列元素不为空" << endl;
        }
    }
    catch(const char* ms)
    {
        cerr << ms << endl;
    }
    return 0;
}