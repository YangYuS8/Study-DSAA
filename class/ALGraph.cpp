#include<iostream>
#include "CircleQueue.cpp"
using namespace std;
const int MaxSize = 10;
int visited[MaxSize];//标记数组
//邻接点结构
struct ArcNode
{
    int adjvex; //邻接点在数组中的位置,即下标值
    ArcNode *next; //指向下一个邻接点的指针
};
//顶点结构
template<class T>
struct VertexNode
{
    T vertex;//顶点元素值
    ArcNode *firstedge;//指向邻接点链表的头结点
};

template<class T>
class ALGraph
{
private:
    VertexNode<T> adjList[MaxSize];//邻接表
    int vertexNum, arcNum;//顶点数和边数
public:
    ALGraph(T a[], int vn, int en);//构造函数
    ~ALGraph(){}//析构函数
    void DFS(int v);//深度优先遍历
    void BFS(int v);//广度优先遍历
};

template<class T>
ALGraph<T>::ALGraph(T a[], int vn, int en)
{
    //初始化顶点数和边数
    vertexNum = vn;
    arcNum = en;
    //初始化顶点元素
    for(int i = 0; i < vertexNum; i++)
    {
        adjList[i].vertex = a[i];//顶点元素赋值
        adjList[i].firstedge = NULL;//指针域赋值为空
    }
    //初始化邻接点链表
    int vi, vj;//接受有边关系的顶点的下标值
    ArcNode *s;//申请邻接点结点空间
    cout << "请输入有边关系的两个顶点的下标值:" << endl;
    for(int k = 0; k < arcNum; k++)
    {
        cin >> vi >> vj;
        s = new ArcNode;//申请邻接点结点空间
        s->adjvex = vj; // 邻接点在数组中的位置
        //vj插入到vi的firstedge上(头插法)
        s->next = adjList[vi].firstedge;
        adjList[vi].firstedge = s;

        //无向图，对称的边也要插入
        s = new ArcNode;
        s->adjvex = vi;
        s->next = adjList[vj].firstedge;
        adjList[vj].firstedge = s;
    }
}
//深度优先遍历
template<class T>
void ALGraph<T>::DFS(int v)
{
    //1.访问Vv，设置标志位
    cout << adjList[v].vertex << " ";
    visited[v] = 1;
    //2.查找Vv的未访问的邻接点Vw
    ArcNode *p = adjList[v].firstedge;//指向Vv的邻接点链表的头结点
    //邻接点的下标
    while(p)//遍历链表(邻接点链表
    {
        int w = p->adjvex;
        if(visited[w] == 0)//如果Vw未访问
        {
            //3.深度优先遍历
            DFS(w);//递归访问Vw
        }
        p = p->next;//指向下一个邻接点
    }
}
//广度优先遍历
template<class T>
void ALGraph<T>::BFS(int v)
{
    CircleQueue<int> Q;//定义一个队列
    //1.输出元素，设置标志位
    cout << adjList[v].vertex << " ";
    visited[v] = 1;
    //2.入队
    Q.EnQueue(v);
    while(!Q.Empty())//所有点
    {
        //3.遍历v的邻接表
        ArcNode *p;//工作指针，指向每一个v的邻接点
        //v出队，访问v的邻接点
        v = Q.DeQueue();
        p = adjList[v].firstedge;//指向v的邻接点链表的头结点
        //p指向每一个邻接点
        while(p)
        {
            int w = p->adjvex;//邻接点的下标
            if(visited[w] == 0)//如果Vw未访问
            {
                //4.输出元素
                cout << adjList[w].vertex << " ";
                //设置标志位
                visited[w] = 1;
                //5.w入队
                Q.EnQueue(w);
            }
            p = p->next;//p后移，指向下一个邻接点
        }
    }
}

int main()
{
    char v[5] = {'A', 'B', 'C', 'D', 'E'};
    ALGraph<char> ALG(v, 5, 4);
    for(int i = 0; i < 5; i++)
    {
        visited[i] = 0;
    }
    cout << "深度优先遍历:" << endl;
    ALG.DFS(1);
    cout << endl;
    for(int i = 0; i < 5; i++)
    {
        visited[i] = 0;
    }
    cout << "广度优先遍历:" << endl;
    ALG.BFS(1);
    return 0;
}