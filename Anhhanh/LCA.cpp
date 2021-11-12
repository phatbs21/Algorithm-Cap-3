#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
vector<int> adj[2000];
int n;
int high[2000];
int par[2000];
int lowLca(int u, int v)
{
    if (high[u] < high[v])
        return lowLca(v, u);
    while (high[u] > high[v])
        u = par[u];
    if (u == v)
        return u;
    while (u != v)
    {
        u = par[u];
        v = par[v];
    }
}
void dfs(int u)
{
    for (int v : adj[u])
    {
        if (v != par[u])
        {
            par[v] = u;
            high[v] = high[u] + 1;
            dfs(v);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
}