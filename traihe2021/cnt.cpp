#include <bits/stdc++.h>
using namespace std;
#define ft first
#define se second
#define mp make_pair
vector<vector<pair<int, int>>> a;
vector<int> d1(1001, 0);
vector<bool> p(1001, 0);
vector<int> path;
int n, m;
void dijkstra(int s)
{
    path.assign(1001, -1);
    d1.assign(1001, INT_MAX);
    priority_queue<pair<int, int>> q;
    q.push(mp(0, s));
    d1[s] = 0;
    while (!q.empty())
    {
        int u = q.top().se;
        q.pop();
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].ft;
            int w = a[u][i].se;
            if (d1[u] + w < d1[v])
            {
                d1[v] = d1[u] + w;
                q.push(mp((-d1[u]), v));
                path[v] = u;
            }
        }
    }
}
vector<int> d2(1001, 0);
vector<bool> p1(1001, 0);
vector<int> path1;
void dijkstra2(int s)
{
    path1.assign(1001, -1);
    d2.assign(1001, INT_MAX);
    priority_queue<pair<int, int>> q;
    q.push(mp(0, s));
    d2[s] = 0;
    while (!q.empty())
    {
        int u = q.top().se;
        q.pop();
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].ft;
            int w = a[u][i].se;
            if (d2[u] + w < d2[v])
            {
                d2[v] = d2[u] + w;
                q.push(mp((-d2[u]), v));
                path1[v] = u;
            }
        }
    }
}

int main()
{
    //freopen("cnt1.inp", "r", stdin);
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        temp1--;
        temp2--;
        a[temp1].push_back(mp(temp2, temp3));
        a[temp2].push_back(mp(temp1, temp3));
    }
    dijkstra(0);
    dijkstra2(1);
    int tong = 0;

    for (int i = 0; i <= n - 1; i++)
    {
        //cout << i + 1 << " " << d1[i] << " " << d2[i] << "\n";
        tong += d2[i];
        
    }
    vector<int> dd(1001, 0);
    for (int i = 0; i <= n - 1; i += 1)
    {
        dd[i] = d1[i] - d2[i];
    }
    sort(dd.begin(), dd.begin() + n);
    for (int i = 0; i < n / 2 ; i++)
    {
        //cout<<dd[i]<<" ";
        tong += dd[i];
    }
    cout << tong;
}