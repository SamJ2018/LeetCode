/*
    ��ͨͼ��  �κ� vi- >vj��·�� ��ע�ⲻһ��ֱ���ڽӣ�
    ��ͨ������������ͨ��ͼ����ͼ��G����ͨ��ͼ������ټ���һ�����㣬��ͼ����ͨ
    ע��ǿ��ͨ����ͨ��������

**  ����ͼ���ź͸��   ȥ��һ����  ����Ϊ2������ͨ����ͼ ��ͨ��������
    �����е���    

    ��ߡ����     ���ѵĵ�Ϊ���  ��Ϊ���
    Ӧ�ã�·�������Ŷ��ˣ����粻����ͨ

    �и�㲻һ�����ţ�����  ��ɳ©  
    ��һ���Ǹ�������ıߣ�����   ��Ϊɾ����㣬��Ҳ��ϣ��������ڸ��

    *˫��ͨ����   �������ͼ�в������ţ����Ϊ��˫��ͨͼ����·û���ţ�
     ����ͨͼ�У�����������䣬��������������·������·���ϵı߻����ظ�

     �������ͼ�в����ڸ�㣬��˫��ͨͼ  ����ͨͼ�У�����������䣬��������������·������·���ϵı߻����ظ�
     
     ����    ��/�� ˫��ͨ      ˫��ͨ����

     ���㣺 ����ѱ�˫��ͨ��������һ���㣬���ſ���������������������  ����>�õ�һ��������ͨ�޻�·�� 

     tarjan����������������㷨   ǿ��ͨ����

     ʱ�����dfn[u] ��ʾu���������ȱ��������
     ׷�ݵ㣺low[u]��ʾu����u��������ͨ���Ǹ��ӱ�׷�ݵ�dfn��С�Ľ����ţ����ص�����Ĺ�ȥ��

     �Ǹ��ӱ߲��ܸ���lowֵ
     �����ܴﵽ����С��ȥ��˫��Ҳ����   ->����low
     �������������  �����Ǹ�

     ��ô�ж��ţ���  һ�����ӵ�lowֵ��˫��lowֵ�󣨼����Ӳ��ܻص�˫�׵Ĺ�ȥ���ţ���
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
} e[maxn << 1]; //һ�������Ϊmaxn*maxn

int low[maxn], dfn[maxn], num; //dfn�Ƿ��ʹ��Ľ�㣬low����׷�ݻص���С�Ľ��

void add(int u, int v)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void tarjan(int u, int fa) //fa�Ǹ����
{
    dfn[u] = low[u] = ++num; //��ʼ��
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
                cout << u << "- " << v << "����" << endl;
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
            add(v, u); //����ͼ
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(1, 0);
        return 0;
    }
}