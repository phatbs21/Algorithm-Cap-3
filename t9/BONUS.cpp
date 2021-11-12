#include <bits/stdc++.h>
using namespace std;
bool prime[10000000];

void tih(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
int main()
{
    //tih(10000000);
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        int flag = false;
        for (int j = 2; j <= k; j++)
        {
            if (i % j == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            dem++;
    }
    cout << dem;
}