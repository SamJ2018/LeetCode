/*
    ע�⣺�����·����Ҫ�������Ȩͼ �Ǹ��ģ�

    Dijkstra�㷨�ǽ����Դ���·�������̰���㷨
    �����������̵�·�����ٲ��ո�·��������ȴζ̵�·����֪�����Դ�㵽����������������·��
*/
#include <stack>
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

#define MaxVnum 100     //���Ķ�����
const int INF = 0xffff; //�����

int dist[MaxVnum], p[MaxVnum]; //��̾����ǰ������
bool flag[MaxVnum];            //���flag[i]����true��˵������i�Ѿ����뵽����S�����򶥵�i����V-S

typedef string VexType; //�������������
typedef int EdgeType;   //����Ȩֵ���������ͣ�������Ȩ����ȡ0/1

typedef struct
{
    VexType Vex[MaxVnum];
    EdgeType Edge[MaxVnum][MaxVnum];
    int vexnum, edgenum; //������������
} AMGraph;               //�ڽӾ���

int locatevex(AMGraph G, VexType e)
{
    for (int i = 0; i < G.vexnum; i++) //���Ҷ�����Ϣ���±�
        if (e == G.Vex[i])
            return i;
    return -1;
}

void CreateAMGraph(AMGraph &G)
{
    int i, j, w;
    VexType u, v;
    cout << "�����붥������ " << endl;
    cin >> G.vexnum;
    cout << "����������� " << endl;
    cin >> G.edgenum;

    cout << "�����붥����Ϣ" << endl;
    for (i = 0; i < G.vexnum; i++) //���붥����Ϣ�����붥����Ϣ����
        cin >> G.Vex[i];

    for (i = 0; i < G.vexnum; i++) //��ʼ�����ڽӾ���Ϊ�����
        for (j = 0; j < G.vexnum; j++)
            G.Edge[i][j] = INF;

    cout << "������ÿ�������������������Լ�Ȩֵ" << endl;

    while (G.edgenum--)
    {
        cin >> u >> v >> w;
        i = locatevex(G, u); //���Ҷ���u�Ĵ洢�±�
        j = locatevex(G, v); //���Ҷ���v�Ĵ洢�±�
        if (i != -1 && j != -1)
            G.Edge[i][j] = w; //����ͼ�ڽӾ���
        else
        {
            cout << "���붥����Ϣ��������������" << endl;
            G.edgenum++; //�������벻��
        }
    }
}

void Dijkstra(AMGraph G, int u)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        dist[i] = G.Edge[u][i]; //��ʼ��Դ��u������������������·������
        flag[i] = false;
        if (dist[i] == INF)
            p[i] = -1; //˵��Դ�㵽�õ�·������Ϊ����󣬲�����
        else
            p[i] = u; //˵������i��Դ��u���ڣ�����i��ǰ��Ϊ  p[i]=u
        //tc  O(n)

        dist[u] = 0;
        flag[u] = true; //��ʼ��ʱ������S��ֻ��һ��Ԫ�أ�Դ��u  �൱�ڼ��뼯��S��

        for (int i = 0; i < G.vexnum; i++)
        {
            int temp = INF, t = u;
            for (int j = 0; i < G.vexnum; j++) //�ڼ���V-S��Ѱ�Ҿ���Դ��u����Ķ���t
                if (!flag[j] && dist[t] < temp)
                    t = j, temp = dist[j]; //������̾���
            if (t == u)
                return; //�Ҳ����������t

            flag[t] = true;                    //�ҵ����t������S������
            for (int j = 0; j < G.vexnum; j++) //������t���ڵĶ��㵽Դ��u�ľ���
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
    cout << "Դ��Ϊ��" << u << endl;

    for (int i = 0; i < G.vexnum; i++)
    {
        x = p[i];
        if (x == -1 && u != G.Vex[i])
        {
            cout << "Դ�㵽�������������·��Ϊ��" << u << "---" << G.Vex[i] << " ��·�ɴ�!" << endl;
            continue;
        }
        while (x != -1)
        {
            s.push(x);
            x = p[x];
        }
        cout << "Դ�㵽�������������·��Ϊ��";
        while (!s.empty())
        {
            cout << G.Vex[s.top()] << "---";
            s.pop();
        }

        cout << G.Vex[i] << " ��̾���Ϊ��" << dist[i] << endl;
    }
}

int main()
{
    AMGraph G;
    int st;
    VexType u;
    CreateAMGraph(G);

    cout << "������Դ�����Ϣ" << endl;
    cin >> u;

    st = locatevex(G, u); //����Դ��u���±�
    Dijkstra(G, st);
    cout << "С������λ��Ϊ:" << u << endl;

    for (int i = 0; i < G.vexnum; i++)
    {
        cout << "С����" << u << "-"
             << "Ҫȥ��λ�ã�" << G.Vex[i];
        if (dist[i] == INF)
            cout << "sorry,��·�ɴ�" << endl;
        else
            cout << "��̾���Ϊ��" << dist[i] << endl;
    }
    findpath(G, u);
    return 0;
}