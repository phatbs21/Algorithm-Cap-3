#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    if (s > 9 * n)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s > 9)
        {
            cout << 9;
            s -= 9;
        }
        else if (s > 0)
        {
            cout << s;
            s -= s;
        }
        else
            cout << 0;
    }
}