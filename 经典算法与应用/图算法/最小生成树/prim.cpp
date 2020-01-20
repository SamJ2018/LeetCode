/*
    prim   集合闭圈   V集合  V-U集合
*/
#include <iostream>
using namespace std;

const int INF = 0x3fffffff;
const int N = 100;

bool s[N]; //判断属于S 还是V-S集合
int closest[N];
int lowcost[N];

/*
使用邻接矩阵描述：
n -- 顶点的个数
u -- 开始顶点
c[N][N] -- 带权邻接矩阵
s[i]   如果s[i]=true 说明顶点i已经加入到了最小生成树中
       否则顶点i属于集合V-U中
将最后相关的最小权值传递到数组lowcost中
*/
void prim(int n, int u, int c[N][N])
{
    s[u] = true; //初始的时候，集合U中只有一个元素，即顶点u
    int i, j;
    //初始化s[] lowcost[] closest[]
    for (i = 1; i <= n; i++)
    {
        if (i != u)
        {
            lowcost[i] = c[u][i]; //将与顶点u邻接的点的权值加入到lowcost数组中
            closest[i] = u;
            s[i] = false; //
        }
        else
            lowcost[i] = 0;
    }

    for (i = 1; i <= n; i++) //在集合V-U中寻找距离集合U最近的顶点t
    {
        int temp = INF, t = u;
        for (j = 1; j <= n; j++)
            if (!s[j] && lowcost[j] < temp) //如果顶点j属于V-U 并且权值小于与U中邻接的权值
                t = j, temp = lowcost[j];
        if (t == u)
            break;               //找不到最近的顶点t，跳出循环
        s[t] = true;             //找到，将t加入到集合U中
        for (j = 1; j <= n; j++) //更新lowcost和closest
        {
            if (!s[j] && c[t][j] < lowcost[j]) //在集合v-u中寻找，与t邻接并且小于当前边权值
            {
                lowcost[j] = c[t][j];
                closest[j] = t;
            }
        }
    }
} //O(n^2)

int main()
{
    int n, c[N][N], m, u, v, w; //顶点数、邻接矩阵、边数、结点数u、邻接点v，权值w
    int u0;                     //源点
    cout << "输入结点数和边数m：" << endl;
    cin >> n >> m;
    int sumcost = 0; //最小权值

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = INF;
    cout << "输入结点数u，v和边值w：" << endl;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        c[u][v] = c[v][u] = w;
    }

    cout << "输入任一结点u0:" << endl;
    cin >> u0;

    prim(n, u0, c);
    cout << "数组lowcost的内容为" << endl;
    for (int i = 1; i <= n; i++)
        cout << lowcost[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        sumcost += lowcost[i];
    cout << "最小的花费是：" << sumcost << endl;

    return 0;
}