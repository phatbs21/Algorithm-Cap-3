#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n), b;
    for (auto &i : a)
        cin >> i;
    vector<int> d(n, false);
    int dem = 0;
    int so = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % m == 0)
        {
            dem += a[i] / m - 1;
            so += a[i] / m;
            if (so > k)
            {
                so -= a[i] / m;
                dem -= a[i] / m + 1;
                while (so < k)
                {
                    so++;
                    dem++;
                }
                cout << dem;
                exit(0);
            }
        }
        else if (a[i] > m)
        {
            b.push_back(a[i]);
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        dem += b[i] / m - 1;
        so += b[i] / m - 1;
        if (so > k)
        {
            so -= b[i] / m - 1;
            dem -= b[i] / m - 1;
            while (so < k)
            {
                so++;
                dem++;
            }
            cout << dem;
            exit(0);
        }
        if (so == k)
        {
            cout << dem;
            exit(0);
        }
    }
    cout << -1;
}