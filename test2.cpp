#include <bits/stdc++.h>
using namespace std;
ifstream f1("triprime.inp");
ofstream f2("triprime.out");
#define cin f1
#define cout f2
bool nt(long long n)
{
    if (n == 1 || n == 0)
        return false;
    for (long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    long long n, u, v;
    cin >> n;
    if (n < 10467397)
    {
        cout << "NO";
        exit(0);
    }
    if (nt(n))
    {
        cout << "NO";
        exit(0);
    }
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            u = i;
            n /= i;
            break;
        }
    }
    if (nt(n))
    {
        cout << "NO";
        exit(0);
    }
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            v = i;
            n /= i;
            break;
        }
    }
    if (u == v || nt(n) == false)
        cout << "NO";
    else
        cout << "YES";
}
