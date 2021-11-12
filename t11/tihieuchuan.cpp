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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("tinhieu.inp", "r", stdin);
    freopen("tinhieu.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    map<ll, ll> d;
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        if (temp == 0)
            a[i] = -1;
        else
            a[i] = 1;
    }
    ll de = 0;
    for (ll i = 2; i <= n; i++)
        a[i] += a[i - 1];
    for (ll i = 0; i <= n; i++)
        d[a[i] + 100000]++;
    for (ll i = 0; i < 100000 * 2 + 1; i++)
    {
        de += (d[i] * (d[i] - 1)) / 2;
    }
    cout << de;
}
