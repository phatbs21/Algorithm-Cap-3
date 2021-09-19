#include <bits/stdc++.h>
using namespace std;
int lis(vector<int> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    n = n * 2;
    int c[100001];
    map<int, int> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        a[c[i]] = i;
    }
    vector<int> b;
    int maxxx = 1;
    //int f[100001];
    int mang[100001];
    for (int k = 1; k < n; k++)
    {
        b.clear();
        for (int i = 1; i <= n - k; i++)
        {
            int dem = 0;
            for (int j = n - k + 1; j <= n; j++)
            {
                if (c[i] + d >= c[j] && c[i] - d <= c[j])
                {
                    dem++;
                    mang[dem] = a[c[j]];
                }
            }
            if (dem > 1)
                sort(mang + 1, mang + dem + 1, greater<int>());
            if (dem > 0)
                for (int j = 1; j <= dem; j++)
                {
                    b.push_back(mang[j]);
                }
        }
        maxxx = max(lis(b), maxxx);
    }
    cout << maxxx;
}
//4 1 1 5 3 7 2 8 6 4