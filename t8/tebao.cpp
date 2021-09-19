#include <bits/stdc++.h>
using namespace std;
int m, n, t;
vector<vector<int>> a(201, vector<int>(201, 0)), b(201, vector<int>(201, 0));
void dao(int i, int j)
{
    if (a[i][j] == 1)
        a[i][j] == 0;
    else
        a[i][j] == 1;
}
void dichuyen(int w, int i, int j, bool flag)
{
    if (w == 1 && i > 1 && j > 0 && flag == true)
    {
        dao(i - 1, j);
        dao(i, j);
    }
    if (w == 2 && i < n)
    {
        dao(i + 1, j);
        dao(i, j);
    }
}
int main()
{
    cin >> m >> n >> t;
    string s;
    cin >> s;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int k = 0; k < s.length(); k++)
    {
        if (s[k] == 1)
        {
            a[1][1] = 0;
            for (int i = 1; i <= m; i++)
        }
    }
}