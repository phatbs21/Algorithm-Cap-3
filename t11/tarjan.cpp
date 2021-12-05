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
typedef pair<ll, ll> pii;
#define MAXN 100100
ll n, m, num[MAXN], low[MAXN], cnt = 0;
vector<vector<ll>> a;
stack<ll> st;
ll Count = 0;
void visit(ll u)
{
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (ll v : a[u])
    {
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u])
    {
        Count++;
        ll v;
        do
        {
            v = st.top();
            st.pop();
            num[v] = low[v] = INT_MAX;
        } while (v != u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("tarjan.inp", "r", stdin);
    freopen("tarjan.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    a.resize(n + 10);
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!num[i])
            visit(i);
    }
    cout << Count;
}
