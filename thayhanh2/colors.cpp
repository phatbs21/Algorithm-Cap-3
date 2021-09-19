#include <bits/stdc++.h>
using namespace std;
#define cin f1
#define cout f2
ifstream f1("diameter.inp");
ofstream f2("diameter.out");
using namespace std;
vector<vector<long long int>> a;
vector<bool> visited;
vector<long long int> dai;
long long int len, dinh;
void BFS(long long int s)
{
    fill(visited.begin(), visited.end(), 0);
    visited[s] = true;
    len = 0;
    dai[s] = len;
    queue<long long int> q;
    q.push(s);
    while (!q.empty())
    {
        long long int w= q.empty();
        long long int u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t;
    cin >> t;
    if (t != 1 && t != 2 && t != 3)
    {
        cout << 0;
        return 0;
    }

    if (t == 1)
    {
        dai.resize(301);
        visited.resize(301);
    }
    else
    {
        dai.resize(300001);
        visited.resize(300001);
    }
    long long int n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    a = vector<vector<long long int>>(n);
    long long int p, q;
    for (long long int i = 0; i < n - 1; ++i)
    {
        cin >> p >> q;
        p--;
        q--;
        a[p].push_back(q);
        a[q].push_back(p);
    }
    BFS(0);
    long long int maxx = 0, dinh;
    for (long long int i = 0; i < n; ++i)
    {
        if (dai[i] > maxx)
        {
            maxx = dai[i];
            dinh = i;
        }
    }
    BFS(dinh);
    maxx = 0;
    for (long long int i = 0; i < n; ++i)
    {
        if (dai[i] > maxx)
        {
            maxx = dai[i];
            dinh = i;
        }
    }
    cout << maxx;
}