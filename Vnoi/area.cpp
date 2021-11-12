#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
struct dt
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    dt(int _x1, int _x2, int _y1, int _y2)
    {
        x1 = _x1;
        x2 = _x2;
        y1 = _y1;
        y2 = _y2;
    }
    bool checkVaild()
    {
        return (x1 <= x2 && y1 <= y2);
    }
};

vector<dt> a;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        a.pb(dt(x1, x2, y1, y2));
    }
}