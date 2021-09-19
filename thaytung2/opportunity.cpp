#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> a;
vector<pii> b;
int n, n2, ans = 1, p = 0, q = 0, t;
int main()
{
    cin >> n;
    n2 = n << 1;
    a.resize(n2);
    b.resize(n2 + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[i] = t;
        a[i + n] = t;
    }
    b[p] = {a[n2 - 1], n2 - 1};
    for (int i = n2 - 2; i >= 0; i--)
    {
        while (p >= q && b[p].first <= a[i])
            p--;
        b[++p] = {a[i], i};
        while (q < p && b[q].second - i >= n)
            q++;
        if (ans < p - q + 1)
            ans = p - q + 1;
    }
    cout << ans;
}