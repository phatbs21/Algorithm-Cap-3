
#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1 + sqrt(5)) / 2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template <class T>
int getbit(T s, int i) { return (s >> 1) & 1; }
template <class T>
T onbit(T s, int i) { return s | (T(1) << i); }
template <class T>
T offbit(T s, int i) { return s & (~(T(1) << i)); }
template <class T>
int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/
struct Node
{
    i64 val = 0;
    i64 lazy = 0;
};

/** -----GLOBAL VARIABLES----- **/
i64 n, m;
vector<Node> tree(666666);

void update(i64 i, i64 l, i64 r, i64 u, i64 v, i64 k)
{
    if (tree[i].lazy > 0)
    {
        tree[i].val += tree[i].lazy;
        if (l != r)
        {
            tree[i * 2].lazy += tree[i].lazy;
            tree[i * 2 + 1].lazy += tree[i].lazy;
        }
        tree[i].lazy = 0;
    }
    if (l > r || l > v || r < u)
        return;
    if (u <= l && r <= v)
    {
        tree[i].val += k;
        if (l != r)
        {
            tree[i * 2].lazy += k;
            tree[i * 2 + 1].lazy += k;
        }
        return;
    }
    update(i * 2, l, (l + r) / 2, u, v, k);
    update(i * 2 + 1, (l + r) / 2 + 1, r, u, v, k);
    tree[i].val = max(tree[i * 2].val, tree[i * 2 + 1].val);
}

i64 get(i64 i, i64 l, i64 r, i64 u, i64 v)
{
    if (l > r || l > v || r < u)
        return -LINF;
    if (tree[i].lazy > 0)
    {
        tree[i].val += tree[i].lazy;
        if (l != r)
        {
            tree[i * 2].lazy += tree[i].lazy;
            tree[i * 2 + 1].lazy += tree[i].lazy;
        }
        tree[i].lazy = 0;
    }
    if (u <= l && r <= v)
        return tree[i].val;
    i64 p1 = get(i * 2, l, (l + r) / 2, u, v);
    i64 p2 = get(i * 2 + 1, (l + r) / 2 + 1, r, u, v);
    return max(p1, p2);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput()
{
    cin >> n >> m;
}

void ProSolve()
{
    while (m--)
    {
        i64 cmd, l, r;
        cin >> cmd >> l >> r;
        if (cmd == 0)
        {
            i64 value;
            cin >> value;
            update(1, 1, n, l, r, value);
        }
        else
            cout << get(1, 1, n, l, r) << endl;
    }
    // for (int i = 1; i <= 4 * n; i++)
    //     cout << tree[i].lazy<<" ";
}

/** -----MAIN FUNCTION----- **/
int main()
{
    freopen("QMAX2.INP", "r", stdin);
    //freopen("FILE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    VarInput();
    ProSolve();
    return 0;
}