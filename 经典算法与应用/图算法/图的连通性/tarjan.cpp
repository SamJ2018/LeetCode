/*
    连通图：  任何 vi- >vj有路径 （注意不一定直接邻接）
    连通分量：极大连通子图：子图是G的连通子图，如果再加入一个顶点，子图不连通
    注意强连通和连通分量区别！

**  无向图的桥和割点   去掉一条边  分裂为2个不连通的子图 连通分量增大
    生活中的桥    

    割边、割点     分裂的点为割点  边为割边
    应用：路由器的桥断了，网络不再连通

    有割点不一定有桥！！！  如沙漏  
    桥一定是割点依附的边！！！   因为删除割点，桥也会断，桥依附于割点

    *双连通分量   如果无向图中不存在桥，则成为边双连通图（回路没有桥）
     边连通图中，任意两个点间，存在两条或以上路径，且路径上的边互不重复

     如果无向图中不存在割点，点双连通图  边连通图中，任意两个点间，存在两条或以上路径，且路径上的边互不重复
     
     极大    边/点 双连通      双连通分量

     缩点： 如果把边双连通分量看做一个点，把桥看作连接两个缩点的无向边  ——>得到一棵树（连通无回路） 

     tarjan最近公共祖先离线算法   强连通分量

     时间戳：dfn[u] 表示u结点深度优先遍历的序号
     追溯点：low[u]表示u结点或u的子孙能通过非父子边追溯到dfn最小的结点序号，即回到最早的过去。

     非父子边不能更新low值
     子孙能达到的最小过去，双亲也可以   ->更新low
     深度优先搜索树  起点就是根

     怎么判断桥？？  一个孩子的low值比双亲low值大（即孩子不能回到双亲的过去，桥！）
*/
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
int n, m;
int head[maxn], cnt;

struct Edge
{
    int to, next;
} e[maxn << 1]; //一般可设置为maxn*maxn

int low[maxn], dfn[maxn], num; //dfn是访问过的结点，low是能追溯回到最小的结点

void add(int u, int v)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void tarjan(int u, int fa) //fa是父结点
{
    dfn[u] = low[u] = ++num; //初始化
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                cout << u << "- " << v << "是桥" << endl;
        }
        else
            low[u] = min(low[u], dfn[v]);
    }
}

void init()
{
    memset(head, 0, sizeof(head));
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    cnt = num = 0;
}

int main()
{
    while (cin >> n >> m)
    {
        init();
        int u, v;
        while (m--)
        {
            cin >> u >> v;
            add(u, v);
            add(v, u); //无向图
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(1, 0);
        return 0;
    }
}