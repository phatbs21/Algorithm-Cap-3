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
#define mp make_pair
#define N 1005000
typedef pair<ll, ll> pii;
pair<pair<ll, ll>, ll> a[N];
ll cha[N], ran[N];
ll init()
{
    for (ll i = 0; i <= N; i++)
    {
        cha[i] = -1;
    }
    return 0;
}
ll find(ll x)
{
    return cha[x] < 0 ? x : cha[x] = find(cha[x]);
}
ll join(ll u, ll v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return 0;
    ll kq = cha[u] * cha[v] * 1LL;
    if (cha[u] > cha[v])
        swap(u, v);
    cha[u] += cha[v];
    cha[v] = u;
    return kq;
}
ll result[N];
bool cmp(pair<pair<ll, ll>, ll> x, pair<pair<ll, ll>, ll> y)
{
    return (x.second < y.second) || (x.second == y.second && x.first.first < y.first.first);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("costquery.inp", "r", stdin);
    freopen("costquery.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;

    for (ll i = 1; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a[i].first.first = x;
        a[i].first.second = y;
        a[i].second = z;
    }
    sort(a + 1, a + n, cmp);
    vector<pair<ll, ll>> q;
    for (ll i = 1; i <= m; i++)
    {
        ll l, r;
        cin >> l >> r;
        q.push_back(mp(r, i));
        q.push_back(mp(l - 1, -i));
    }
    sort(q.begin(), q.end());
    init();
    ll cnt = 0;
    ll i = 1;
    for (pair<ll, ll> e : q)
    {
        while (i < n && a[i].second <= e.first)
        {
            ll u = a[i].first.first;
            ll v = a[i].first.second;
            i++;
            ll temp = join(u, v);
            //cout << u << " " << v << " " << temp << "\n";
            cnt += temp;
        }
        if (e.second > 0)
        {
            result[e.second] += cnt;
        }
        else
        {
            result[-e.second] -= cnt;
        }
    }
    for (ll i = 1; i <= m; i++)
        cout << result[i] << " ";
}
