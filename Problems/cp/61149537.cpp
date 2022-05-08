#include<bits/stdc++.h>
namespace {
using namespace std;
// https://github.com/atcoder/ac-library/
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int li = 0, lj = 0;
    VVI d(n, VI(m));
    d[0][0] = k;
    for(int t = 0; t <= (n - 1) + (m - 1); t++) {
      int i = 0, j = t - i;
      if (j >= m) {
        int x = j - (m - 1);
        i += x;
        j -= x;
      }
      for(; i < n && j >= 0; i++, j--) {
        int c = d[i][j];
        if (i == n - 1) {
          if (j == m - 1) break;
          if (s[i][j] == '0') {
            if (c >= 1) {
              d[i][j+1]++;
              if (c == 1 && i == li && j == lj) {
                lj++;
              }
            }
          }
        } else if (j == m - 1) {
          if (s[i][j] == '1') {
            if (c >= 1) {
              d[i+1][j]++;
              if (c == 1 && i == li && j == lj) {
                li++;
              }
            }
          }
        } else {
          if (c % 2 == 0) {
            d[i+1][j] += c / 2;
            d[i][j+1] += c / 2;
            if (i == li && j == lj) {
              if (s[i][j] == '1') lj++;
              else li++;
            }
          } else {
            if (s[i][j] == '1') {
              d[i+1][j] += (c + 1) / 2;
              if (i == li && j == lj) li++;
              d[i][j+1] += c / 2;
            } else {
              d[i+1][j] += c / 2;
              d[i][j+1] += (c + 1) / 2;
              if (i == li && j == lj) lj++;
            }
          }
        }
      }
    }
    cout << li + 1 << ' ' << lj + 1 << '\n';
  }
}