#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
#define ll int64_t
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;
#define MAX 100100
#define LOG 17
#define INF INT_MAX
struct Edge
{
    int u, v, w, inTree;
    Edge(int _u = 0, int _v = 0, int _w = 0)
    {
        u = _u, v = _v, w = _w;
        inTree = false;
    }
};
int numNode, numEdge, numQuery;
Edge edges[MAX];
vector<int> adj[MAX];
int dsu[MAX];
int find(int u)
{
    return dsu[u] < 0 ? u : dsu[u] = find(dsu[u]);
}
bool join(int u, int v)
{
    int u = find(u);
    int v = find(v);
    if (u == v)
        return false;
    if (dsu[v] > dsu[u])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
    return true;
}
void buildSpanningTree()
{
    for (int i = 0; i < MAX; i++)
        dsu[i] = -1;
    for (int i = 1; i <= numEdge; i++)
        edges[i].inTree = join(edges[i].u, edges[i].v);
}
int par[MAX][LOG + 1];
int high[MAX];
ll distRoot[MAX];
void dfs(int u)
{
    for (int i : adj[u])
    {
        if (edges[i].inTree)
        {
            int v = u == edges[i].u ? edges[i].v : edges[i].u;
            if (v == par[u][0])
                continue;
            par[v][0] = u;
            high[v] = high[u] + 1;
            distRoot[v] = distRoot[u] + edges[i].w;
            dfs(v);
        }
    }
}
int lca(int u, int v)
{
    if (high[u] < high[v])
        return lca(v, u);
    for (int i = LOG; i >= 0; i--)
    {
        if (high[par[u][i]] >= high[v])
        {
            u = par[u][i];
        }
    }
    if (v == u)
        return u;
    for (int i = LOG; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[u][v];
        }
    }
    return par[v][0];
}
long long distTree(int u, int v)
{
    return distRoot[u] + distRoot[v] - 2 * distRoot[lca(u, v)];
}
vector<int> nodes;
void xuliChinh()
{
    nodes.clear();
    for (int i = 1; i <= numEdge; i++)
    {
        if (!edges[i].inTree)
            nodes.push_back(edges[i].u);
    }
    sort(nodes.begin(), nodes.end());
    nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
}
vector<long long> dist[MAX];
void dijkstra(int s)
{
    dist[s].assign(numNode + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    dist[s][s] = 0;
    while (!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first;
        if (du != dist[s][u])
        {
            continue;
        }
        for (int i = 0; i < adj[u].size(); i++)
        {
            //tutu
        }
    }
}
long long queries(int s, int e)
{
    long long result = distTree(e, s);
    for (int u : nodes)
    {
        result = min(result, dist[u][s] + dist[u][e]);
    }
    return result;
}
void loadGraph()
{
    cin >> numNode >> numEdge >> numQuery;
    for (int i = 1; i <= numNode; i++)
        adj[i].clear();
    for (int j = 1; j <= numEdge; j++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[j] = Edge(u, v, w);
        adj[u].push_back(j);
        adj[v].push_back(j);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("terrorists.inp", "r", stdin);
    freopen("terrorists.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    loadGraph();
    buildSpanningTree();
    xuliChinh();
}
