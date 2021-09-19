#include <bits/stdc++.h>
using namespace std;
long long int so(long long int n)
{
    long long int so = 0;
    while (n > 0)
    {
        n /= 10;
        so++;
    }
    return so;
}
int main()
{
#if ONLINE_JUDGE
    freopen("digits.inp", "r", stdin);
    freopen("digits.out", "w", stdout);
#endif
    long long int m, n, p;
    cin >> m >> n >> p;
    long long int tong = so(m);
    while (tong < p)
    {
        m += n;
        tong += so(m);
    }
    //cout << m << " " << so(m) << " " << tong << endl;
    if (tong == p)
    {
        cout << m;
    }
    else
    {
        tong -= p;
        string s = to_string(m);
        for (long long int i = 0; i < s.size() - tong; i++)
        {
            cout << s[i];
        }
    }
}