#include<iostream>
#include "CircleQueue.cpp"
using namespace std;
const int MaxSize = 100;
int visited[MaxSize];
template<class T>
class MGraph
{
private:
    T vertex[MaxSize];
    int arc[MaxSize][MaxSize];
    int vertexNum, arcNum;
public:
    MGraph(T a[], int vn, int en);
    ~MGraph(){}
    void DFS(int v);//深度优先遍历：从顶点Vv出发
    void BFS(int v);//广度优先遍历
};
//初始化
//图初始化：1.数据元素：vertex
//          2.关系：arc--邻接矩阵
template <class T>
MGraph<T>::MGraph(T a[], int vn, int en)
{
    //1.顶点个数，边个数初始化
    vertexNum = vn;
    arcNum = en;
    //2.顶点数组初始化
    for (int i = 0; i < vertexNum; i++)
    {
        vertex[i] = a[i];
    }
    //3.边关系数组，即邻接矩阵初始化
    //将所有位置的数据设置为0
    for (int i = 0; i < vertexNum; i++)
    {
        for (int j = 0; j < vertexNum; j++)
        {
            arc[i][j] = 0;
        }
    }
    //将有边关系的位置设置为1：键盘输入有关系的顶点下标
    int vi, vj;
    cout << "请输入有边的顶点序号：" << endl;
    for(int k = 0; k < arcNum; k++)
    {
        cin >> vi >> vj;
        arc[vi][vj] = 1;
        arc[vj][vi] = 1;//无向图的时候是对称的
    }
}

//深度优先遍历
template <class T>
void MGraph<T>::DFS(int v)
{
    //1.访问顶点Vv，访问即为输出，输出即设标识位
    cout << vertex[v] << " ";
    visited[v] = 1;
    //4.循环：把v的所有邻接点都访问完
    for(int w = 0; w < vertexNum; w++)
    {
        //2.找v的未被访问的邻接点w
        if (arc[v][w] == 1 && visited[w] == 0)
        {
            //3.对w进行深度优先遍历
            DFS(w);
        }
    }
}

//广度优先遍历
template <class T>
void MGraph<T>::BFS(int v)
{
    //1.访问顶点Vv，设置标识位
    cout << vertex[v] << " ";
    visited[v] = 1;
    //创建队列
    CircleQueue<int> Q;//顶点元素所在的下标
    //v入队
    Q.EnQueue(v);
    while(!Q.Empty())
    {
        v = Q.DeQueue();//出队
        //2.访问v的所有的未访问的邻接点w
        for(int w = 0; w < vertexNum; w++)
        {
            if (arc[v][w] == 1 && visited[w] == 0)
            {
                //3.输出Vw，设置标识位
                cout << vertex[w] << " ";
                visited[w] = 1;
                Q.EnQueue(w);//w入队
            }
        }
    }
}

int main()
{
    char v[] = {'A', 'B', 'C', 'D', 'E'};
    MGraph<char> G(v, 5, 4);
    //visited数组初始化
    for (int i = 0; i < 5; i++)
    {
        visited[i] = 0;
    }
    cout << "深度优先遍历：";
    G.DFS(0);
    cout << endl;
    //visited数组初始化
    for (int i = 0; i < 5; i++)
    {
        visited[i] = 0;
    }
    cout << "广度优先遍历：";
    G.BFS(0);
    cout << endl;
    return 0;
}