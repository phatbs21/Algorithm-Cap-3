#include <bits/stdc++.h>
using namespace std;
int quaylui(int u)
{
    
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<vector<pair<int, int>>> p(n + 1);
    int x[305][305];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
                temp = a[i];
            p[i].push_back({j, temp});
            x[i][j] = temp;
        }
    
}