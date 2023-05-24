#include <iostream>
using namespace std;
const int MaxSize = 100;
template <class T>
class SeqList
{
public:
    SeqList(); // 构造函数，将表置空
    ~SeqList() {} // 析构
    int Locate(T x); // 查找元素x在表中的位置，成功返回x在表中的位置，否则返回0
    void Insert(int i, T x); // 在表的i位置插入元素x
    void Reverse(); // 逆序表中数据
    void DispList();
private:
    T data[MaxSize]; // 存储元素
    int length; // 顺序表实际长度
};

template<class T>
SeqList<T>::SeqList()
{
    length = 0;
}

template<class T>
int SeqList<T>::Locate(T x)
{
    for (int i = 1; i <= length;i++)
    {
        if(x==data[i])
            return i;
    }
    return 0;
}

template<class T>
void SeqList<T>::Insert(int i,T x)
{
    for (int j = length; j >=i-1;j--)
    {
        data[j+1] = data[j];
    }
    data[i] = x;
    length++;
}

template<class T>
void SeqList<T>::Reverse()
{
    if(length%2==0)
    {
        int m = 0, n = 1;
        for (int k = length; k > (length / 2);k--)
        {
            m = data[k];
            data[k] = data[n];
            data[n] = m;
            n++;
        }
    }
    else if(length%2!=0)
    {
        int m = 0, n = 1;
        for (int k = length; k > (length / 2) + 1;k--)
        {
            m = data[k];
            data[k] = data[n];
            data[n] = m;
            n++;
        }
    }
}

template<class T>
void SeqList<T>::DispList()
{
    cout << "The length:" << length << endl;
    cout << "The elements:" << endl;
    for (int l = 1; l <= length;l++)
    {
        cout << data[l] << " ";
    }
}

int main()
{
    int a = 1, x, i = 1, y;
    SeqList<int> L;
    while(cin>>x)
    {
        if(x==0)
            break;
        else
        {
            L.Insert(a, x);
        }
    }
    cin >> y;
    L.DispList();
    cout << endl;
    if(L.Locate(y)==0)
    {
        cout << "No found" << endl;
    }
    else
    {
        cout << "Found position:" << L.Locate(y) << endl;
    }
    L.Reverse();
    L.DispList();
}