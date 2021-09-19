#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> s(200, vector<int>(200, 0));
int n, m, a, b, c, d;
int dem = 0;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int visit[20][20][20][20];
int flag = 0;
char vitri[100001];
string noi = "LURD";
void dfs(int a, int b, int c, int d)
{
    if (flag == 1 || visit[a][b][c][d] == 1)
        return;
    visit[a][b][c][d] = 1;
    if (a == 0 && b == 0 && c == 0 && d == 0)
    {
        flag = 1;
        cout << dem << endl;
        for (int k = 1; k <= dem; k++)
        {
            cout << vitri[k];
        }
    }
    for (int h = 0; h <= 3; h++)
    {
        int aa = a + dx[h], bb = b + dy[h], cc = c + dx[h], dd = d + dy[h];
        if (aa < 0 || bb < 0 || aa >= n || bb >= m || s[aa][bb] == 1)
        {
            aa = a;
            bb = b;
        }
        if (cc < 0 || dd < 0 || cc >= n || dd >= m || s[cc][dd] == 1)
        {
            cc = c;
            dd = d;
        }
        dem++;
        vitri[dem] = noi[h];
        dfs(aa, bb, cc, dd);
        dem--;
    }
}

int main()
{
    cin >> n >> m >> a >> b >> c >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == 1)
                dem++;
        }
    for (int i = 0; i <= 12; i++)
        for (int j = 0; j <= 12; j++)
            for (int k = 0; k <= 12; k++)
                for (int w = 0; w <= 12; w++)
                    visit[i][j][k][w] = 0;
   // visit[a][b][c][d] = 1;
    dfs(a, b, c, d);
}
//2 2 1 0 0 1 0 0 0 1