#include <bits/stdc++.h>
using namespace std;
const int d[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
int a[9][9], v[9][9], f[6];
int n, depth;
int h()
{
    int tmp = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!f[a[i][j]] && v[i][j] != 1)
            {
                f[a[i][j]] = 1;
                tmp++;
            }
    return tmp;
}
void pt(int x, int y, int c)
{
    v[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + d[i][0];
        int ty = y + d[i][1];
        if (tx < 1 || tx > n || ty < 1 || ty > n || v[tx][ty] == 1)
            continue;
        v[tx][ty] = 2;
        if (a[tx][ty] == c)
            pt(tx, ty, c);
    }
}
int fill(int c)
{
    int tmp = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == c && v[i][j] == 2)
            {
                tmp++;
                pt(i, j, c);
            }
    return tmp;
}
bool dfs(int dep)
{
    int g = h();
    if (dep + g > depth)
        return 0;
    if (!g)
        return 1;
    int rec[9][9];
    for (int i = 0; i <= 5; i++)
    {
        memcpy(rec, v, sizeof(v));
        if (fill(i) && dfs(dep + 1))
            return 1;
        memcpy(v, rec, sizeof(v));
    }
    return 0;
}
signed main()
{
    while (cin >> n, n)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        memset(v, 0, sizeof(v));
        pt(1, 1, a[1][1]);
        for (depth = 0;; depth++)
            if (dfs(0))
                break;
        printf("%d\n", depth);
    }
    return 0;
}
