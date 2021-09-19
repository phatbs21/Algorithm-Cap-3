#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    int ans;
    for (int i = 62; i > 0; i--)
    {
        if ((n >> i) & 1)
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
    cout << 31 - __builtin_clzl(n) + 1;
}