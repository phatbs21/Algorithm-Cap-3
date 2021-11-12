#include <bits/stdc++.h>
using namespace std;
int main()
{
    double u1 = 2, d = -2, un = -6;
    cin >> u1 >> d >> un;
    double n = (un - u1) / d;
    if (n < 0)
    {
        cout << -1;
        return 0;
    }
    if (u1 == un)
    {
        cout << 1;
        return 0;
    }
    if (n == (int)((un - u1) / d))
    {
        cout << (abs(((un - u1) / d)) + 1);
    }
    else
    {
        cout << -1;
    }
}