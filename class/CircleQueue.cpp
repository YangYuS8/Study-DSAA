#include<iostream>
using namespace std;
const int QueueSize = 10;
template<class T>
class CircleQueue
{
private:
    T data[QueueSize];
    int front, rear;
    //front指向队头元素的前一个位置，rear指向队尾元素
public:
    CircleQueue();
    ~CircleQueue(){}
    void EnQueue(T x);//入队
    T DeQueue();//出队
    T GetQueue();//取队头元素
    int Empty();//判空
    void PrintQueue();//输出队列
};

template<class T>
CircleQueue<T>::CircleQueue()
{
    front = 0;
    rear = 0;
}

template<class T>
void CircleQueue<T>::EnQueue(T x)
{
    //入队：插入到队尾--rear
    if((rear+1)%QueueSize == front)
    {
        throw "队满";
    }
    rear = (rear+1)%QueueSize;//rear指向下一个元素
    data[rear] = x;//入队
}

template<class T>
T CircleQueue<T>::DeQueue()
{
    //出队：删除队头元素--front->next
    if(rear == front)
    {
        throw "队空";
    }
    front = (front+1)%QueueSize;//front指向下一个元素
    T x = data[front];//保存队头元素
    return x;
}

template<class T>
T CircleQueue<T>::GetQueue()
{
    //取队头元素
    if(rear == front)
    {
        throw "队空";
    }
    int i = (front+1)%QueueSize;//i指向队头元素
    return data[i];
}

template<class T>
int CircleQueue<T>::Empty()
{
    //判空
    if(rear == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template<class T>
void CircleQueue<T>::PrintQueue()
{
    //输出队列
    if(rear == front)
    {
        throw "队空，队内无元素";
    }
    else if(rear > front)
    {
        cout << "队内元素为：";
        for(int i = front+1; i <= rear; i++)
        {
            cout << data[i] << " ";
        }
    }
    else if(rear < front)
    {
        cout << "队内元素为：";
        //front开始
        for(int i = front+1; i < QueueSize; i++)
        {
            cout << data[i] << " ";
        }
        for(int i = 0; i <= rear; i++)
        {
            cout << data[i] << " ";
        }
    }
    cout << endl;
}
/*
int main()
{
    try
    {
        CircleQueue<int> Q;
        int x;
        cin >> x;
        while(x != 0)
        {
            Q.EnQueue(x);
            cin >> x;
        }
        Q.PrintQueue();
        cout << "出队的元素为：" << Q.DeQueue() << endl;
        Q.PrintQueue();
        // cout << "取队头的元素为：" << Q.GetQueue() << endl;
        cout<<"请输入要入队的元素：";
        cin>>x;
        Q.EnQueue(x);
        Q.PrintQueue();
        x = Q.Empty();
        if(x == 1)
        {
            cout << "队内无元素" << endl;
        }
        else
        {
            cout << "队内有元素" << endl;
        }
    }
    catch (const char* ms)
    {
        cout << ms << endl;
    }
    return 0;
}
*/