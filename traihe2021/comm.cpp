#include <bits/stdc++.h>
using namespace std;
#define ft first
#define se second
#define mp make_pair
#define pb push_back
struct te
{
    int to, c, d;
};
vector<te> a[151];
vector<int> d(151, 0);
int dijsktra(int s)
{
    d.assign(151,0x3f3f3f3f);
    priority_queue<pair<int,int>> q;
    d[s]=0;
    q.push(mp(0,s));
    while(q.size())
    {
        int u=q.top().second;
        int 
        q.pop();
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int s, t, w;
    cin >> s >> t >> w;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        a[u].pb({v, c, d});
        a[v].pb({u, c, d});
    }
}