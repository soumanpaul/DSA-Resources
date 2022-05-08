#include <bits/stdc++.h>
using namespace std;

#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define lli long long int
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ve vector<lli>
#define vve vector<ve>
#define vep vector<pll>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fr(i, a, n) for (lli i = a; i < (n); i++)
#define frx(i, a, n) for (lli i = a; i > (n); i--)
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
#define sci(x) scanf("%d", &x)
#define mem(a, x) memset(a, x, sizeof(a));
#define LL_INF (1LL << 62)
// #define INF (1 << 30)
#define INF (lli)4e18
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (!!(x & (1LL << k)))
#define mod 998244353
#define N 1000006

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    } else
        return false;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    } else
        return false;
}

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

// lli n, m, k;

// lli f(lli r, lli c, char x) {
//     if (r == n - 1 && x == '1')
//         return 0;
//     if (c == m - 1 && x == '0')
//         return 0;
//     return 1;
// }

int main() {
    speed;

    int ntc;
    cin >> ntc;
    while (ntc--) {
        /* code */
    }
    return 0;
}