
#include <bits/stdc++.h>
using namespace std;
int dp[101][101][1001];
vector<int> a;
int kt(int n, int x)
{
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k <= 1000; k++)
            {
                dp[i + 1][j + 1][k + a[i]] += dp[i][j][k];
                dp[i + 1][j][k] += dp[i][j][k];
            }
        }
    }
    int cnt = 0;
    for (int j = 1; j <= n; j++)
    {
        cnt += dp[n][j][x * j];
    }
    return cnt;
}
int main()
{
    vector<int> a;
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cout << kt(n, x);
}
