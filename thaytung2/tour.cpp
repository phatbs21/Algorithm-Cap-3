#include <bits/stdc++.h>
using namespace std;
int llen = 0, prh = 1e9, lh = 1e9, lmin = 1e9, ans1 = 0, ans2 = 0;

int main()
{
    int n;
    cin >> n;
    int h;

    for (int i = 1; i <= n; i++)
    {
        cin >> h;
        if (h == lh)
            ++llen;
        else
        {
            if (prh < lh && lh > h && llen < lmin)
            {
                lmin = llen;
                ans1 = i - llen - 1;
                ans2 = i;
                if (lmin == 1)
                    break;
            }
            prh = lh;
            lh = h;
            llen = 1;
        }
    }
    if (ans1 == 0)
        cout << 0;
    else
    {
        cout << ans1 << endl
             << ans2;
    }
}