#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("qbselect.inp", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector<vector<long long>> A(4, vector<long long>(n));
    for (long long i = 0; i < 4; i++)
        for (long long j = 0; j < n; j++)
            cin >> A[i][j];
    vector<vector<long long>> adjacent(1 << 4);
    vector<long long> possible_states;
    for (long long u = 0; u < (1 << 4); u++)
    {
        bool invalid_state = false;
        for (long long i = 0; i < 4 - 1; i++)
            if ((u & (1 << i)) && (u & (1 << (i + 1))))
            {
                invalid_state = true;
                break;
            }
        if (invalid_state)
            continue;
        possible_states.push_back(u);
    }
    for (auto u : possible_states)
        for (auto v : possible_states)
        {
            bool invalid_state = false;
            for (long long i = 0; i < 4; i++)
                if ((u & (1 << i)) && (v & (1 << i)))
                {
                    invalid_state = true;
                    break;
                }
            if (invalid_state)
                continue;
            adjacent[u].push_back(v);
        }
    auto reward = [&](long long state, long long column)
    {
        long long sum = 0;
        for (long long i = 0; i < 4; i++)
            if (state & (1 << i))
                sum += A[i][column];
        return sum;
    };
    vector<vector<long long>> M(n, vector<long long>(1 << 4, -1));
    function<long long(long long, long long)> bt = [&](long long i, long long state)
    {
        if (M[i][state] != -1)
            return M[i][state];
        if (i == n - 1)
            return M[i][state] = reward(state, i);
        long long maxn = -0x3f3f3f3f3f3f3f3f;
        for (auto next : adjacent[state])
            maxn = max(maxn, bt(i + 1, next));
        return M[i][state] = maxn + reward(state, i);
    };
    long long maxn = -0x3f3f3f3f3f3f3f3f;
    for (auto state : possible_states)
        maxn = max(maxn, bt(0, state));
    if (maxn == 0)
    {
        long long adjusted = -0x3f3f3f3f3f3f3f3f;
        for (auto row : A)
            adjusted = max(adjusted, *max_element(row.begin(), row.end()));
        cout << adjusted;
        return 0;
    }
    cout << maxn;
}