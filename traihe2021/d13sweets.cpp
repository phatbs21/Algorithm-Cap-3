#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1] + a[i];
    }
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if(b[i]-b[k] )
            }
        }
    }
}