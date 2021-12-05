#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll int64_t
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;
#define MAXN 100100
vector<vector<int>> a;
int critNode[MAXN];
int critEdge = 0;
int cnt = 0;
int num[MAXN], low[MAXN];
void visit(int u, int p)
{
    int numchild = 0;
    num[u] = low[u] = ++cnt;
    for (int v : a[u])
    {
        if (v != p)
        {
            if (num[v] != 0)
            {
                low[u] = min(low[u], num[v]);
            }
            else
            {
                visit(v, u);
                numchild++;
                low[u] = min(low[u], low[v]);
                if (low[v] >= num[v])
                    critEdge++;
                if (u == p)
                {
                    if (numchild >= 2)
                        critNode[u] = true;
                }
                else if (low[v] >= num[u])
                    critNode[u] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("khopcau.inp", "r", stdin);
    freopen("khopcau.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    a.resize(n + 10);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
        {
            visit(i, i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (critNode[i])
            count++;
    }
    cout << count << " " << critEdge;
}
