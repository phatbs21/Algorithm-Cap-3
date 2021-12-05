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
double log_a_to_base_b(double a, double b)
{
    return log(a) / log(b);
}
void primeFactors(ll n, ll m)
{
    //cout << "*" << n << " " << m << endl;
    map<ll, ll> a;
    vector<ll> b;
    while (n % 2 == 0)
    {
        if (a[2] == 0)
            b.push_back(2);
        a[2]++;
        n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            if (a[i] == 0)
                b.push_back(i);
            a[i]++;
            n = n / i;
        }
    }
    if (n > 2)
    {
        if (a[n] == 0)
            b.push_back(n);
        a[n]++;
    }
    while (m % 2 == 0)
    {
        if (a[2] == 0)
            b.push_back(2);
        a[2]++;
        m = m / 2;
    }
    for (ll i = 3; i <= sqrt(m); i = i + 2)
    {
        while (m % i == 0)
        {
            if (a[i] == 0)
                b.push_back(i);
            a[i]++;
            m = m / i;
        }
    }
    if (m > 2)
    {
        if (a[m] == 0)
            b.push_back(m);
        a[m]++;
    }
    sort(b.begin(), b.end());
    for (ll i = 0; i < b.size(); i++)
    {
        cout << a[b[i]] << " ";
    }
    cout << endl;
    for (ll i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        double a, b, c;
        cin >> a >> b >> c;
        cout << log_a_to_base_b(b, a) << " *" << endl;
        if (log_a_to_base_b(b, a) != (double)(ll)log_a_to_base_b(b, a))
        {
            cout << -1 << "\n";
            continue;
        }
        a = log_a_to_base_b(b, a);
        primeFactors(a, c);
    }
}
