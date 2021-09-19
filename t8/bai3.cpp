#include <bits/stdc++.h>
using namespace std;
#define cin f1
#define cout f2
ifstream f1("sodps.inp");
ofstream f2("sodps.out");
int main()
{
    long long int n, dem, p, s, d, num;
    cin >> n;
    dem = 0;
    for (int i = 1; i <= 1000000000; i++)
    {
        p = 1, s = 0;
        num = i;
        while (num > 0)
        {
            d = num % 10;
            p = p * d;
            s = s + d;
            num = num / 10;
        }
        if ((p % s) == 0)
        {
            dem++;
        }
        if (n == dem)
        {
            cout << i;
            break;
        }
    }
}