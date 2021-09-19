#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &i : a)
    {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int ans = -1;
    for (int i = 0, q = n - 1; i < n; i++)
    {
        while (q > i && a[i] + a[q] > x)
            q--;
        if (q > i)
            ans = max(ans, a[i] + a[q]);
    }
    cout << ans;
}