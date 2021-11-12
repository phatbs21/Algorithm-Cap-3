#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    freopen("SQROOT.INP", "r", stdin);
    freopen("SQROOT.out", "w", stdout);
    long long int n = 10000000000;
     cin >> n;
    /**
    long long int tong = 0;
    for (int i = 1; i <= n; i++)
        tong = tong % 2021 + ((i * i) % 2021);
        
    cout << tong;**/
    cout << (((n % 2021) * ((n + 1) % 2021) * ((2 * n + 1) % 2021)) / 6) % 2021;
}
