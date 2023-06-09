#include<iostream>
using namespace std;
const int Max = 10;
class List
{
private:
    int data[Max];
    int length;
public:
    List(int a[], int n);
    ~List(){}
    void Print();
    //折半查找
    //递归
    int BinSearch(int low, int high, int k);
    //非递归
    int BinSearch(int k);
};
List::List(int a[], int n)//n=9, 1->9
{
    length = n;
    for(int i = 0; i < n; i++)
        data[i] = a[i];
}
void List::Print()
{
    cout << "表中的数据：";
    for(int i = 0; i < length; i++)
        cout << data[i] << " ";
    cout << endl;
}

int List::BinSearch(int low, int high, int k)
{
    //出口
    if(low > high)
        return -1;
    else
    {
        int mid = (low + high) / 2;
        // if(data[mid] == k)
        //     return mid;
        // else if(data[mid] > k)
        //     return BinSearch(low, mid - 1, k);
        // else
        //     return BinSearch(mid + 1, high, k);
        if(k<data[mid])
            return BinSearch(low, mid - 1, k);//左半区进行折半查找
        else if(k>data[mid])
            return BinSearch(mid + 1, high, k);//右半区进行折半查找
        else//k==data[mid]
            return mid;
    }
}

int List::BinSearch(int k)
{
    int low = 1, high = length-1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        // if(data[mid] == k)
        //     return mid;
        // else if(data[mid] > k)
        //     high = mid - 1;
        // else
        //     low = mid + 1;
        if(k<data[mid])
            high = mid - 1;//左半区进行折半查找
        else if(k>data[mid])
            low = mid + 1;//右半区进行折半查找
        else//k==data[mid]
            return mid;//找到
    }
    return -1;
}

int main()
{
    int a[5] = {-1, 25, 46, 78, 90};//有序
    List L(a, 5);
    L.Print();
    int x;
    cout << "请输入要查找的数：";
    cin >> x;
    cout<<"递归查找："<<L.BinSearch(1, 4, x)<<endl;//(low, high, x)
    cout<<"非递归查找："<<L.BinSearch(x)<<endl;//(x)
    system("pause");
}