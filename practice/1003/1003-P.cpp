#include <iostream>
using namespace std;
const int MaxSize = 100;
template <class T>
class SortList
{
public:
    SortList() { length = 0; }
    ~SortList() {}
    void Insert(T x); // 有序表的插入，使序列仍有序
    void DispList(); // 输出表
    /*成员函数Merge实现两个有序表的合并，使序列仍有序，
       将A表和B表合并到当前类中，要求：A表，B表的元素保持不变*/
    void Merge(SortList<T> &A, SortList<T> &B);
private:
    T data[MaxSize]; // 存储元素
    int length; // 顺序表实际长度
};

template<class T>
void SortList<T>::Insert(T x)
{
    data[length] = x;
    for (int j = length; j >= 0;j--)
    {
        if(data[j]>x)
        {
            data[j + 1] = data[j];
            data[j] = x;
        }
    }
    length++;
}

template<class T>
void SortList<T>::DispList()
{
    cout << "The length:" << length << endl;
    cout << "The elements:" << endl;
    for (int k = 0; k < length;k++)
    {
        cout << data[k] << " ";
    }
    cout << endl;
}

template<class T>
void SortList<T>::Merge(SortList <T> &A,SortList <T> &B)
{
    for (int l = 0; l < A.length;l++)
    {
        Insert(A.data[l]);
    }
    for (int m = 0; m < B.length;m++)
    {
        Insert(B.data[m]);
    }
}

// 构造有序表A：函数声明
template <class T>
void CreateSort(SortList<T> &A);
int main()
{
    SortList<int> A, B, C;
    // 生成一个有序表A
    CreateSort(A);
    // 生成一个有序表B
    CreateSort(B);
    try
    {
        C.Merge(A, B); // 合并A,B表为C表
    }
    catch (const char *wrong)
    {
        cout << wrong; // 如失败提示失败信息
    }
    A.DispList();
    B.DispList();
    C.DispList(); // 显示合并后的结果
    return 0;
}

// 构造有序表A：函数定义
template <class T>
void CreateSort(SortList<T> &A)
{
    int i, n;
    T x;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        try
        {
            A.Insert(x);
        }
        catch (char *wrong)
        {
            cout << wrong << endl;
        }
    }
}