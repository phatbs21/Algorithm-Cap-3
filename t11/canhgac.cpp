#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll int64_t
#define s first.first
#define c second
#define t first.second
#define pb push_back
#define mp make_pair
typedef pair<pair<ll, ll>, ll> pii;
bool cmp(pii x, pii y)
{
    return x.t < y.t || (x.t == y.t && x.s < y.s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("canhgac.inp", "r", stdin);
    freopen("canhgac.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    vector<pii> a;
    a.push_back(mp(mp(0, 0), 0));
    for (ll i = 1; i <= m; i++)
    {
        ll ss, tt, cc;
        cin >> ss >> tt >> cc;
        a.push_back(mp(mp(ss, tt), cc));
    }
    sort(a.begin(), a.end(), cmp);
    for (ll i = 0; i <= m; i++)
    {
        cout << a[i].s << " " << a[i].t << " " << a[i].c << "\n";
    }
    cout << "*\n";
    ll dp[n + 1];

    for (ll i = 0; i <= n + 1; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[1] = 0;
    for (ll i = 1; i <= m; i++)
    {
        int flag = true;
        for (ll j = 0; j < i; j++)
        {
            if (a[i].s <= a[j].t)
            {
                dp[i] = min(dp[i], dp[j] + a[i].c);
                cout << i << " " << j << " " << dp[i] << " " << dp[j] << "\n";
                flag == false;
            }
        }

    }
    cout << endl;
    for (ll i = 1; i <= m; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    ll minn = INT_MAX;
    for (ll i = 1; i <= m; i++)
        if (a[i].t >= n)
        {
            minn = min(minn, dp[i]);
        }
    cout << minn;
}
