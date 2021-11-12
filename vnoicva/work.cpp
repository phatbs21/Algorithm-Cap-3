#include <bits/stdc++.h>
using namespace std;
#define oo (INT_MAX - 1)
int main()
{
    int64_t n;
    cin >> n;
    vector<int64_t> t(n + 1, 0);
    vector<int64_t> p(n + 1, 0);
    for (int64_t i = 1; i <= n; i++)
        cin >> t[i];
    for (int64_t i = 1; i < n; i++)
        cin >> p[i];
    p[0] = oo;
    vector<int64_t> d(n + 2, false);
    vector<int64_t> f(n + 2, 0);
    f[1]=t[1];
    for (int64_t i = 2; i <= n; i++)
    {
        f[i] = min(f[i - 1] + t[i], f[i - 2] + p[i - 1]);
    }
    cout << f[n];
}