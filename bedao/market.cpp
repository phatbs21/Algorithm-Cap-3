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
ll dp[50][50][100001];
vector<ll> a(10005);
ll kt(ll n, ll x)
{
    dp[0][0][0] = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            for (ll k = 0; k <= 1000; k++)
            {
                dp[i + 1][j + 1][k + a[i]] += dp[i% 1000][j% 1000][k% 1000] % 1000;
                dp[i + 1][j][k] += dp[i% 1000][j% 1000][k% 1000] % 1000;
            }
        }
    }
    ll cnt = 0;
    for (ll j = 1; j <= n; j++)
    {
        cnt += dp[n][j][x % 1000 * j % 1000] % 1000;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #if ONLINE_JUDGE
    // #else
    //     freopen("input.inp", "r", stdin);
    //     //freopen("output.out", "w", stdout);
    // #endif
    ll n, x;
    cin >> n >> x;
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a[i] = temp % 1000;
    }
    cout << kt(n, x);
}
