#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pb push_back
typedef pair<ll, ll> pii;
#include <bits/stdc++.h>
using namespace std;
const ll oo = 1e18;
bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void in(ll n)
{
    while (true)
    {
        if (isPrime(n) == true)
        {
            cout << n * n;
            break;
        }
        n++;
    }
}
int main()
{
    ll n = 20;
    cin >> n;
    int i = n;
    n = sqrt(n);
    if (n * n != i)
        n++;
    //cout << n << " ";
    in(n);
    return 0;
}
