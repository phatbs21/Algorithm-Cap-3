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
#define mp make_pair
typedef pair<int, int> pii;
#define N 5005000
vector<int> cha(N, 0);
vector<int> sau(N, 0);
int n, m;
void init()
{
    for (int i = 1; i <= N; i++)
    {
        cha[i] = i;
        sau[i] = 0;
    }
}
int find(int u)
{
    if (cha[u] != u)
        cha[u] = find(cha[u]);
    return cha[u];
}
bool join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (sau[u] == sau[v])
        sau[u]++;
    if (sau[u] < sau[v])
        cha[u] = v;
    else
        cha[v] = u;
    return true;
}

struct canh
{
    int u, v, w, pos;
    canh()
    {
        u = 0, v = 0, w = 0, pos = 0;
    }
    canh(int uu, int vv, int ww, int poss)
    {
        u = uu, v = vv, w = ww, pos = poss;
    }
};
vector<canh> a;
int dd[N];

bool cmp(canh x, canh y)
{
    return x.w < y.w;
}
void process()
{
    int t;
    scanf("%d", &t);
    scanf("%d%d", &n, &m);
    a.resize(m);
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2, temp3;
        scanf("%d%d%d", &temp1, &temp2, &temp3);
        a[i] = canh(temp1, temp2, temp3, i + 1);
    }
    sort(a.begin(), a.end(), cmp);
    init();
    int j = 1;
    for (canh &e : a)
    {
        if (join(e.u, e.v) == true)
        {
            dd[j] = e.pos;
            ++j;
        }
    }
    sort(dd + 1, dd + j);
    for (int i = 1; i <= j - 1; i++)
    {
        printf("%d ", dd[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#if ONLINE_JUDGE
    freopen("mst.inp", "r", stdin);
    freopen("mst.out", "w", stdout);
#else
    freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
#endif
    process();
}