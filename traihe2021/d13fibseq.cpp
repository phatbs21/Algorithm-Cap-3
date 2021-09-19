#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(long long int x)
{
    long long int s = sqrt(x);
    return (s * s == x);
}

bool isFibonacci(long long int n)
{
    return isPerfectSquare(5 * n * n + 4) ||
           isPerfectSquare(5 * n * n - 4);
}

int main()
{
    long long int n, P, Q;
    cin >> n >> P >> Q;
    vector<long long int> a(n + 1);
    for (long long int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
    {
        //sub1;
        if (isFibonacci(a[1]) == true)
            cout << 1;
        else
            cout << 0;
    }
    else
    {
        //sub2,3
        vector<long long int> b(n + 1, 0);
        for (long long int i = 1; i <= n; i++)
        {
            b[i] += b[i - 1] + a[i];
        }
        long long int dem = 0;
        for (long long int i = 1; i <= n; i++)
        {   
            for (long long int j = 1; j <= i; j++)
            {
                if (i - j + 1 >= P && i - j + 1 <= Q)
                {
                    if (isFibonacci(b[i] - b[j - 1]) == true)
                    {
                        dem++;
                        //cout << i << " " << j << " " << b[i] - b[j - 1] << " " << i - j + 1 << "\n";
                    }
                }
            }
        }
        cout << dem;
    }
}
/**
5 1 2
1 1 1 1 1
**/
