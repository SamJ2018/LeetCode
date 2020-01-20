/*

*/
#define N 100
#include <algorithm>
const int INF = 0x3fffffff;
using namespace std;

const int n = 100;
int d[N][N];

void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = i == j ? 0 : INF;
}

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}