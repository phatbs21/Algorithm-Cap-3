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
map<ll, bool> factor;
vector<ll> oddFactor;
void laymu(ll a)
{
    ll x = a;
    for (ll i = 2; i * i <= x; i++)
    {
        if (a % i == 0)
        {
            while (a % i == 0)
            {
                factor[i] ^= 1;
                a /= i;
            }
        }
    }

    if (a > 1)
        factor[a] ^= 1;
    return;
}
void muchan()
{
    for (__typeof(factor.begin()) it = factor.begin(); it != factor.end(); it++)
    {
        if (it->se)
            oddFactor.push_back(it->fi);
        //cout << it->fi << " ";
    }
    //cout << endl;
}
void process()
{
    factor.clear();
    oddFactor.clear();
    ll a, b;
    cin >> a >> b;
    laymu(a);
    laymu(b);
    muchan();
    ll tong = 2e9 + 5;
    ll a_temp, b_temp;
    for (ll i = 1; i <= (1LL << oddFactor.size()); i++)
    {
        ll a = b = 1;
        for (ll j = 0; j < oddFactor.size(); j++)
        {
            if ((i >> j) % 2)
                a *= oddFactor[j];
            else
                b *= oddFactor[j];
        }
        if (tong > a + b)
        {
            tong = a + b;
            a_temp = a;
            b_temp = b;
        }
    }
    cout << a_temp << " " << b_temp << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        process();
    }
}
