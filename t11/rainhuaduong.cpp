#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll long long int
#define fi first
#define se second
#define pb push_back
typedef pair<ll, ll> pii;
const ll N = 10e5 + 4;
const ll INF = 2e18;
vector<vector<pair<ll, ll>>> a(N);
vector<ll> d(N, INF);
vector<bool> p(N, 0);
vector<ll> path;
void dijkstra(ll s)
{
    path.assign(N, -1);
    d.assign(N, INT_MAX);
    priority_queue<pair<ll, ll>> q;
    q.push({0, s});
    d[s] = 0;
    while (!q.empty())
    {
        ll u = q.top().second;
        q.pop();
        for (ll i = 0; i < a[u].size(); i++)
        {
            ll v = a[u][i].first;
            ll w = a[u][i].second;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                q.push({(-d[v]), v});
                path[v] = u;
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
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
#else
    freopen("input.INP", "r", stdin);
#endif
    ll n, x;
    cin >> n >> x;
    ll t, y, u;
    while (cin >> t >> y >> u)
    {
        a[t].pb(make_pair(y, u));
        a[y].pb(make_pair(t, u));
    }
    dijkstra(x);
    map<ll, ll> duong;
    for (ll i = 1; i <= n; i++)
    {
        if (duong[i] != 1)
        {
            stack<ll> s;
            ll k = i;
            while (k != x)
            {
                //cout << k << " ";
                s.push(k);
                k = path[k];
            }
            while (!s.empty())
            {
                duong[s.top()]++;
                s.pop();
                //cout << sum << " ";
            }
            //cout << "\n";
        }
    }
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (duong[i] == 1)
        {
            sum += d[i];
        }
    }
    cout << sum;
}
