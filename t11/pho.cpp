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
#define N 300005
typedef pair<ll, ll> pii;
vector<vector<ll>> a(N);
ll n, m;
vector<ll> d;
ll high[N], par[N];
ll kq = 0;
vector<ll> queries(N, 0);
map<ll, ll> check;
ll goc;
void dfs(ll u)
{
    for (ll i = 0; i < (ll)a[u].size(); i++)
    {
        ll v = a[u][i];
        if (v != par[u])
        {
            par[v] = u;
            high[u] = high[v] + 1;
            dfs(v);
        }
    }
}
void lca(ll v)
{
    if (goc == v || check[v] > 0)
        return;
    if (check[v] == 0)
        kq++;
    check[v]++;
    // cout << v << " ";

    while (goc != v && check[par[v]] == 0)
    {
        v = par[v];
        // cout << v << " ";
        if (check[v] == 0)
            kq++;
        check[v]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("pho.inp", "r", stdin);
    freopen("pho.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        cin >> queries[i];
    }
    for (ll i = 1; i <= n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    goc = queries[1];
    par[goc] = goc;
    dfs(queries[1]);
    check[queries[1]]++;
    for (ll i = 2; i <= m; i++)
    {
        lca(queries[i]);
    }
    cout << kq << "\n";
}
