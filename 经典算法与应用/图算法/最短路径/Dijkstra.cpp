/*
    注意：求最短路径需要是有向带权图 非负的！

    Dijkstra算法是解决单源最短路径问题的贪心算法
    先求出长度最短的路径，再参照该路径求出长度次短的路径，知道求出源点到其它各个顶点的最短路径
*/
#include <stack>
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

#define MaxVnum 100     //最大的顶点数
const int INF = 0xffff; //无穷大

int dist[MaxVnum], p[MaxVnum]; //最短距离和前驱数组
bool flag[MaxVnum];            //如果flag[i]等于true，说明顶点i已经加入到集合S，否则顶点i属于V-S

typedef string VexType; //顶点的数据类型
typedef int EdgeType;   //边上权值的数据类型，若不带权，则取0/1

typedef struct
{
    VexType Vex[MaxVnum];
    EdgeType Edge[MaxVnum][MaxVnum];
    int vexnum, edgenum; //顶点数，边数
} AMGraph;               //邻接矩阵

int locatevex(AMGraph G, VexType e)
{
    for (int i = 0; i < G.vexnum; i++) //查找顶点信息的下标
        if (e == G.Vex[i])
            return i;
    return -1;
}

void CreateAMGraph(AMGraph &G)
{
    int i, j, w;
    VexType u, v;
    cout << "请输入顶点数： " << endl;
    cin >> G.vexnum;
    cout << "请输入边数： " << endl;
    cin >> G.edgenum;

    cout << "请输入顶点信息" << endl;
    for (i = 0; i < G.vexnum; i++) //输入顶点信息，存入顶点信息数组
        cin >> G.Vex[i];

    for (i = 0; i < G.vexnum; i++) //初始化化邻接矩阵为无穷大
        for (j = 0; j < G.vexnum; j++)
            G.Edge[i][j] = INF;

    cout << "请输入每条边依附的两个顶点以及权值" << endl;

    while (G.edgenum--)
    {
        cin >> u >> v >> w;
        i = locatevex(G, u); //查找顶点u的存储下标
        j = locatevex(G, v); //查找顶点v的存储下标
        if (i != -1 && j != -1)
            G.Edge[i][j] = w; //有向图邻接矩阵
        else
        {
            cout << "输入顶点信息错误！请重新输入" << endl;
            G.edgenum++; //本次输入不算
        }
    }
}

void Dijkstra(AMGraph G, int u)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        dist[i] = G.Edge[u][i]; //初始化源点u到其它各个顶点的最短路径长度
        flag[i] = false;
        if (dist[i] == INF)
            p[i] = -1; //说明源点到该点路径长度为无穷大，不相邻
        else
            p[i] = u; //说明顶点i与源点u相邻，设置i的前驱为  p[i]=u
        //tc  O(n)

        dist[u] = 0;
        flag[u] = true; //初始化时，集合S中只有一个元素；源点u  相当于加入集合S中

        for (int i = 0; i < G.vexnum; i++)
        {
            int temp = INF, t = u;
            for (int j = 0; i < G.vexnum; j++) //在集合V-S中寻找距离源点u最近的顶点t
                if (!flag[j] && dist[t] < temp)
                    t = j, temp = dist[j]; //更新最短距离
            if (t == u)
                return; //找不到最近顶点t

            flag[t] = true;                    //找到最近t，加入S集合中
            for (int j = 0; j < G.vexnum; j++) //更新与t相邻的顶点到源点u的距离
                if (!flag[j] && G.Edge[t][j] < INF)
                    if (dist[j] > dist[t] + G.Edge[t][j])
                    {
                        dist[j] = dist[t] + G.Edge[t][j];
                        p[j] = t;
                    }
        }
    }
}

void findpath(AMGraph G, VexType u)
{
    int x;
    stack<int> s;
    cout << "源点为：" << u << endl;

    for (int i = 0; i < G.vexnum; i++)
    {
        x = p[i];
        if (x == -1 && u != G.Vex[i])
        {
            cout << "源点到其它各顶点最短路径为：" << u << "---" << G.Vex[i] << " 无路可达!" << endl;
            continue;
        }
        while (x != -1)
        {
            s.push(x);
            x = p[x];
        }
        cout << "源点到其它个顶点最短路径为：";
        while (!s.empty())
        {
            cout << G.Vex[s.top()] << "---";
            s.pop();
        }

        cout << G.Vex[i] << " 最短距离为：" << dist[i] << endl;
    }
}

int main()
{
    AMGraph G;
    int st;
    VexType u;
    CreateAMGraph(G);

    cout << "请输入源点的信息" << endl;
    cin >> u;

    st = locatevex(G, u); //查找源点u的下标
    Dijkstra(G, st);
    cout << "小明所在位置为:" << u << endl;

    for (int i = 0; i < G.vexnum; i++)
    {
        cout << "小明：" << u << "-"
             << "要去的位置：" << G.Vex[i];
        if (dist[i] == INF)
            cout << "sorry,无路可达" << endl;
        else
            cout << "最短距离为：" << dist[i] << endl;
    }
    findpath(G, u);
    return 0;
}