#include <bits/stdc++.h>
using namespace std;
long long int fib(long long int n)
{
    const long long int kPisanoSize = 60;
    long long int rest = n % kPisanoSize;
    long long int preparedNumbers[kPisanoSize] = {0, 1, 2, 4, 7, 2, 0, 3, 4, 8, 3, 2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7, 6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1, 4, 6, 1, 8, 0, 9, 0};
    return preparedNumbers[rest];
}
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int m, n;
        cin >> m >> n;
        long long int final = fib(n) - fib(m - 1);
        if (final < 0)
            final = 10 + final;
        cout << final % 10 << endl;
    }
}
