#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long power(long long a, long long b, long long c)
{
    if (b == 0)
    {
        return 1;
    }

    if (b % 2 == 0)
    {
        long long w = power(a, b / 2, c);
        return (w * w) % c;
    }
    else
    {
        int w = power(a, b - 1, c);
        return (a * w) % c;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        cout << pow(a, b)<<"\n";
        cout << power(a, b, e) << "\n";
    }
}