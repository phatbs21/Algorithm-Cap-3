#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("bai5.inp", "r", stdin);
    freopen("bai5.out", "w", stdout);
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n + 5];
    for (int i = 0; i < n; i++)
        b[i] = a[i] * a[i];
    sort(a, a + n);
    sort(b, b + n);
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        int p = i + 1;
        int q = i + 1;
        for (int j = i + 1; j < n; j++)
        {
            while (p < n - 1 && b[i] + b[j] >= b[p + 1])
                p++;
            q = max(q, p);
            while (q < n - 1 && a[i] + a[j] > a[q + 1])
                q++;
            if (b[i] + b[j] == b[p])
            {
                x += max(p - j - 1, 0);
                y++;
                z += q - p;
            }
            else
            {
                x += max(p - j, 0);
                z += q - p;
            }
        }
    }
    cout << x << " " << y << " " << z << "\n";
}
