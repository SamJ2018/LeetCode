/*
用堆优化Dijkstra
*/
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define N 100
typedef pair<int, int> PII;

int n;                            //顶点数量
int h[N], w[N], e[N], ne[N], idx; //邻接表存储所有边
int dist[N];                      //存储所有点到源点的最短距离
bool st[N];                       //存储每个点的最短距离是否确定

//求源点到n点的最短距离，若不存在 返回-1

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist); //初始化
    dist[1] = 0;                     //源点1
    //优先级队列
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1}); //first存储距离，second存储结点编号

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;

        if (st[ver]) //最短距离已有，进入下一次循环
            continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}