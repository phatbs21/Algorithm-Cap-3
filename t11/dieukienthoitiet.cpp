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
#define N 100005
typedef pair<int, int> pii;
int time_dfs;
vector<int> num(N, 0), low(N, 0), tail(N, 0);
// num[] cho biet thu tu duyet
// low[] voi moi dinh u, low[u] cho biet thu tu (num) nho nhat co the di den tu u bang cach di xuoi xuong theo cac canh net lien(cac cung tren cay dfs)
// va ket thuc di nguoc len khong qua 1 lan theo canh net dut. ngoai ra cung co the hieu low[u] la thu tu tham  cua dinh co thu tu tham som nhat nam trong
// cay con goc u hoac ke canh  voi 1 dinh bat ki nam trong do
// tail[] thoi diem ket thuc duyet dfs cua moi cung
// cac dinh co thu tu nam trong khoang num[u] -> tail[u] chinh la thoi diem duyet xong dinh do
vector<vector<int>> a;
void dfs(int u, int pre)
{
    num[u] = low[u] = ++time_dfs;
    for (int v : a[u])
    {
        if (v == pre)
            continue;
        if (!num[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], num[v]);
    }
    tail[u] = time_dfs;
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
    int n, m;
    cin >> n >> m;
}
