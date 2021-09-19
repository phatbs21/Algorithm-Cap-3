#include <bits/stdc++.h>
using namespace std;
int main()
{
    int  d[26][26] = {0}, f[26][26] = {0};
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; ++i)
    {
        ++d[s[i] - 65][s[i + 1] - 65];
    }
    cin >> s;
    int ans = 0;
    n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (f[s[i] - 65][s[i + 1] - 65] == 0)
        {
            ans += d[s[i] - 65][s[i + 1] - 65];
        }
        f[s[i] - 65][s[i + 1] - 65] = 1;
    }
    cout << ans;
}