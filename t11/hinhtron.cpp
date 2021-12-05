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
typedef pair<ll, ll> pii;
bool checkInside(ll x, ll y, ll xx, ll yy, ll r)
{
    if (((x - xx) * (x - xx) + (y - yy) * (y - yy)) <= r * r)
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("SPID.inp", "r", stdin);
    freopen("SPID.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    ll dem = 0;
    ll n, m, r;
    cin >> n >> m >> r;
    vector<pair<ll, ll>> a(n + 1), b(m + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    for (ll i = 1; i <= m; i++)
    {
        cin >> b[i].fi >> b[i].se;
    }
    map<pair<int, int>, int> q;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (checkInside(a[j].fi, a[j].se, b[i].fi, b[i].se, r) == true && q[mp(a[j].fi, a[j].se)] == 0)
            {
                dem++;
                q[mp(a[j].fi, a[j].se)]++;
            }
        }
    }
    cout << dem;
}
