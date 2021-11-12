#include <bits/stdc++.h>
using namespace std;
//test dap an
int main()
{
    freopen("MAXF.INP", "r", stdin);
    freopen("MAXF.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    double mx = INT_MIN;
    int x, z;
    for (int i = 0; i - 1 < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((double)a[i] / (double)a[j] < 1)
                if (mx < (double)a[i] / (double)a[j])
                {
                    mx = (double)a[i] / (double)a[j];
                    x = a[i];
                    z = a[j];
                }
            if ((double)a[j] / (double)a[i] < 1)
                if (mx < (double)a[j] / (double)a[i])
                {
                    mx = (double)a[j] / (double)a[i];
                    x = a[j];
                    z = a[i];
                }
        }
    }
    cout << x << " " << z;
}