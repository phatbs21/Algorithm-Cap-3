#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
vector<vector<pii>> a(100005);
vector<int> path(100006, -1);
vector<int> d;
int dem = 1;
map<int, int> duong;
void dijkstra(int s)
{
    d.assign(100005, INT_MAX);
    priority_queue<pii> q;
    q.push({0, s});
    d[s] = 0;
    while (!q.empty())
    {
        int u = q.top().fi;
        int du = q.top().se;
        q.pop();
        if (du != d[u])
            continue;
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].fi;
            int w = a[u][i].se;
            if (d[u] + w <= d[v])
            {
                d[v] = true;
                q.push({-d[v], v});
                path[v] = u;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++)
    {
        int temp, temp2;
        cin >> temp >> temp2;
        a[temp].pb(mp(temp, 1));
        a[temp2].pb(mp(temp2, 1));
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= x; i++)
    {
        int temp, temp2;
        cin >> temp >> temp2;
        cout << abs(duong[temp] - duong[temp2]) << "\n";
    }
}
