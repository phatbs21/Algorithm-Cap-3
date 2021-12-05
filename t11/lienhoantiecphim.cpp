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
ll ways(ll n)
{
    return (n * (n - 1) / 2);
}
bool cmp(pii x, pii y)
{
    return x.first < y.first;
}
ll f[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("FESTIVAL.inp", "r", stdin);
    freopen("FESTIVAL.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(m + 1);
    map<ll, ll> q;
    for (ll i = 0; i <= 1000; i++)
    {
        for (ll j = 0; j <= 1000; j++)
            f[i][j] = 0;
    }
    for (ll i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
        f[a[i].first][a[i].second] = 1;
    }
    sort(a.begin() + 1, a.end(), cmp);
    ll dem = 0;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = i + 1; j <= n; j++)
        {
            ll d = 0;
            for (ll k = 1; k <= n; k++)
            {
                if (f[i][k] == 1 && f[j][k] == 1)
                {
                    //cout << i << " " << j << " " << k << "\n";
                    d++;
                }
            }
            d = d;
            //cout << ways(d) << "*\n";
            dem += ways(d);
        }
    }
    cout << dem;
}
