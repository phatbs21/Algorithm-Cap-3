#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
template <class X, class Y>
bool minimize(X &x, Y y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    return false;
}
class disjointSet
{
private:
    vector<int> lab;
    int find(int x)
    {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }

public:
    disjointSet(int n = 0)
    {
        lab.assign(n + 7, -1);
    }
    bool join(int u, int v)
    {
        int x = find(u), y = find(v);
        if (x == y)
            return false;
        if (lab[x] > lab[y])
            swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
    bool sameSet(int u, int v)
    {
        return find(u) == find(v);
    }
};
struct edge
{
    int u, v, cost;
    edge(int _u = 0, int _v = 0, int _cost = 0)
    {
        u = _v;
        v = _v;
        cost = _cost;
    }
    void input(void)
    {
        cin >> u >> v >> cost;
    }
};
#define MAX 500500
int numNode, numEdge;
edge edges[MAX];
vector<int> blocks[MAX];
bool result[MAX];
void loadGraph(void)
{
    cin >> numNode >> numEdge;
    for (int i = 1; i <= numEdge; i++)
        edges[i].input();
}
void process()
{
    vector<int> cost;
    
}
int main()
{
}