#include<iostream>
using namespace std;
const int MaxSize = 100;
template <class T>
class SortList
{
public:
    SortList() { length = 0; } // 置空表
    ~SortList() {}
    void Insert(T x); // 非递减有序表的插入x，使序列仍有序
    void DispList(); // 输出表
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

// 构造有序表A：函数声明
template <class T>
void CreateSort(SortList<T> &A);
// 主函数
int main()
{
    SortList<int> A; // 整型数据表A
    // 生成一个有序表A
    CreateSort(A);
    SortList<char> B; // 字符型数据表B
    CreateSort(B);
    A.DispList();
    B.DispList();
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
        catch (const char *wrong)
        {
            cout << wrong << endl;
        }
    }
}