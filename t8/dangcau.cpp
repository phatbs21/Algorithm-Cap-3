#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("dangcau.inp", "r", stdin);
    freopen("dangcau.out", "w", stdout);
#endif
    int x, dem = 0, kq = 0, n, tong = 0, bairerachdevl[10];
    string s = "", so[10];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        s = to_string(i);
        for (int j = 0; j < 10; j++)
            bairerachdevl[j] = -1;
        bairerachdevl[s[0] - '0'] = 1;
        s[0] = '1';
        dem = 0;
        for (int j = 1; j < s.length(); j++)
        {
            x = s[j] - '0';
            if (bairerachdevl[x] == -1)
            {
                bairerachdevl[x] = dem;
                s[j] = dem + '0';
                dem++;
                if (dem == 1)
                {
                    dem++;
                }
            }
            else
            {
                s[j] = bairerachdevl[x] + '0';
            }
        }
        kq = kq + stoll(s, nullptr);
        tong = tong + kq;
        kq = 0;
    }
    cout << tong;
}