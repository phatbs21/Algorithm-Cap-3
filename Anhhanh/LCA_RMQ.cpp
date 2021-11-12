#include <bits/stdc++.h>
using namespace std;
#define MAX 300300
#define LOG 19
#define mask(i) (1LL << (i))
vector<int> par(MAX, 0), high(MAX, 0), node(MAX, 0), pos(MAX, 0);
vector<vector<int>> a, rmq(MAX, vector<int>(LOG + 2, 0));
int cnt = 0;
void dfs(int u)
{
    node[++cnt] = u;
    pos[u] = cnt;
    for (int v : a[u])
    {
        if (v != par[u])
        {
            par[v] = u;
            high[v] = high[u] + 1;
            dfs(v);
            node[++cnt] = u;
        }
    }
}
#define MIN_HIGH(x, y) (high[x] < high[y] ? (x) : (y))
int lca(int u, int v)
{
    int l = pos[u], r = pos[v];
    if (l > r)
        swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return MIN_HIGH(rmq[l][k], rmq[r - mask(k) + 1][k]);
}
int main()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++)
        rmq[i][0] = node[i];
    for (int j = 1; j <= LOG; j++)
        for (int i = 1; i <= cnt - mask(j) + 1; i++)
        {
            rmq[i][j] = MIN_HIGH(rmq[i][j - 1], rmq[i + mask(j - 1)][j - 1]);
        }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cout << lca(temp1, temp2) << " ";
    }
}