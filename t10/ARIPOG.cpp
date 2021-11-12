#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    freopen("ARIPOG.INP", "r", stdin);
    freopen("ARIPOG.OUT", "w", stdout);
    ll u1, d, x;
    cin >> u1 >> d >> x;
    double check = ((double)x - (double)u1) / (double)d + 1;
    if ((((double)((ll)check) * (double)d + (double)u1 == (double)x)) or (((double)((ll)check - 1) * (double)d + (double)u1 == (double)x)))
        cout << check;
    else
        cout << -1;
}