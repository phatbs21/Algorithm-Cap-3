#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
#define cin f1
#define cout f2
ifstream f1("diameter.inp");
ofstream f2("diameter.out");
void dfs(int temp, int truoc, int &dai, vector<bool> &visite)
{
    visite[temp] = 1;
    int tem = 0;
    int q;
    for (int i = 0; i < a[temp].size(); i++)
    {
        q = a[temp][i];
        if (!visite[q])
        {
            tem = truoc + 1;
            dfs(q, tem, dai, visite);
        }
        if (dai < tem)
            dai = tem;
        tem = 0;
    }
}
int main()
{
    int t;
    cin >> t;
    int n, m;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int dai = INT_MIN;
    vector<bool> visite(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        visite.assign(n + 1, 0);
        dfs(i, 0, dai, visite);
    }
    cout << dai;
}
