#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll long long
#define fi first
#define se second
#define pb push_back
#define MAXN 10001000
const ll MOD = 998244353;
const long long INF = (long long)1e14 + 7LL;
typedef pair<ll, ll> pii;
bool notPrime[MAXN];
pair<ll, ll> queries[100105];
ll answer[100105];
vector<pair<ll, ll>> value;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("primelcm.inp", "r", stdin);
    freopen("primelcm.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    notPrime[0] = notPrime[1] = true;
    for (ll i = 2; 1LL * i * i < MAXN; i++)
    {
        if (!notPrime[i])
        {
            for (ll j = i * i; j < MAXN; j += i)
            {
                notPrime[j] = true;
            }
        }
    }
    for (ll p = 1; p < MAXN; p++)
    {
        if (!notPrime[p])
        {
            ll tmp = p;
            while (INF / tmp >= p)
            {
                tmp *= p;
                value.push_back(make_pair(tmp, p));
                //cout << tmp << " ";
            }
        }
    }
    sort(value.begin(), value.end());

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << value[i].first << " ";
    // }
    // cout << endl;
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        ll h;
        scanf("%lld", &h);
        queries[i].first = h;
        queries[i].second = i;
    }
    sort(queries + 1, queries + n + 1);
    ll res = 1;
    ll j = 0;
    for (ll i = 1; i <= n; i++)
    {
        while (j < value.size() && value[j].first <= queries[i].first)
        {
            res = ((res % MOD) * (value[j++].second % MOD)) % MOD;
        }
        answer[queries[i].second] = res;
    }
    for (ll i = 1; i <= n; i++)
    {
        printf("%lld ", answer[i]);
    }
}