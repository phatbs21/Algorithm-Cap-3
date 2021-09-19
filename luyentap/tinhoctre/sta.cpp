#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[101], b[101], c[101], e[101];
    double aa = 0, bb = 0, cc = 0, ee = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> e[i];
        aa += a[i], bb += b[i], cc += c[i], ee += e[i];
    }
    aa = aa / double(n);
    bb = bb / double(n);
    cc = cc / double(n);
    ee = ee / double(n);
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (double(a[i]) > aa && double(b[i]) > bb && double(c[i]) > cc && double(e[i]) > ee)
        {
            dem++;
        }
    }
    cout << dem;
}