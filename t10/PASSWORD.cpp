#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    int n, s;
    cin >> s >> n;
    if (n == 0)
    {
        if (s == 1)
            cout << 0;
        else
            cout << -1;
        return 0;
    }
    if (n > 9 * s)
    {
        cout << -1;
        return 0;
    }
    int so[s + 1];
    for (int i = 0; i < s; i++)
    {
        if (n >= 9)
        {
            so[i] = 9;
            n -= 9;
        }
        else
        {
            so[i] = n;
            n = 0;
        }
    }
    for (int i = 0; i < s; i++)
        cout << so[i];
}