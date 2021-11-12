#include <bits/stdc++.h>
using namespace std;
vector<double> a;
int n, k;
double tim()
{
    double mi = *min_element(a.begin(), a.end());
    double ma = *max_element(a.begin(), a.end());
    vector<double> tong(n + 2, 0);
    while (ma - mi > 0.000001)
    {
        double mid = mi + (ma - mi) / 2; //gia tri trung binh lon nhat
        //cout<<mid;
        for (int i = 0; i < n; i++)
        {
            tong[i + 1] = tong[i] + a[i] - mid;
            // cout << tong[i + 1] << " ";
        }
        double maxs = INT_MIN;
        double mins = 0;
        // tong lon nhat
        for (int i = k; i <= n; i++)
        {
            maxs = max(maxs, tong[i] - mins);
            mins = min(mins, tong[i - k + 1]);
            //cout<<maxs<<mins;
        }
        if (maxs >= 0)
            mi = mid;
        else
            ma = mid;
        //cout << ma << " " << mi << " " << mid << "\n";
    }
    return ma;
}
int main()
{
    freopen("AVERAGE.INP", "r", stdin);
    freopen("AVERAGE.OUT", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    for (auto &i : a)
        cin >> i;
    cout << setprecision(3) << fixed << tim() << " ";
    //cout << setprecision(3) << fixed << w / (double)(k - z + 1);
}