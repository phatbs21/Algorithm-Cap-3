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
typedef pair<int, int> pii;
bool tinh(int x1, int y1, int x2, int y2, int x, int y)
{
    if (x > x1 and x < x2 and y > y1 and y < y2)
        return true;
    return false;
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
    int x1, y1, x2, y2, xm, ym, xn, yn;
    cin >> x1 >> y1 >> x2 >> y2 >> xm >> ym >> xn >> yn;
    int dem = 0;
    if (x1 > x2 && y1 > y2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    else if (x1 > x2)
    {
        int temp1 = x1;
        x1 = x2;
        x2 = temp1;
    }
    else if (y1 > y2)
    {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }
    dem += tinh(x1, y1, x2, y2, xm, ym);
    dem += tinh(x1, y1, x2, y2, xn, yn);
    cout << dem;
}
