#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int ntc;
	cin >> ntc;
	while (ntc--) {
		int n, m;
		cin >> n >> m;
		long long k;
		cin >> k;
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == '0') {
					a[i][j] = 0;
				} else {
					a[i][j] = 1;
				}
			}
		}
		function<void()> dbg = [&]() {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << a[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		};
		
		vector<vector<long long>> dp(n, vector<long long>(m));
		dp[0][0] = k - 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				long long cur = dp[i][j];
				long long R = 0;
				long long D = 0;
				if (a[i][j] == 1) {
					// down
					D = (cur + 1) / 2;
					R = cur - D;
				} else {
					// right
					R = (cur + 1) / 2;
					D = cur - R;
				}
				if (i == (n - 1) || j == (m - 1)) {
					if (cur >= 1) {
						if (i == (n - 1)) {
							a[i][j] = 1;
						}
						if (j == (m - 1)) {
							a[i][j] = 0;
						}
					}
					continue;
				}
				// down
				if (i < (n - 1)) {
					dp[i + 1][j] += D;
					if (D & 1) {
						a[i][j] ^= 1;
					}
				}
				// right
				if (j < (m - 1)) {
					dp[i][j + 1] += R;
					if (R & 1) {
						a[i][j] ^= 1;
					}
				}
			}
		}
		// dbg();
		
		int x = 0;
		int y = 0;
		while (true) {
			if (a[x][y] == 1) {
				x++;
				if (x == n) {
					x--;
					break;
				}
			} else {
				y++;
				if (y == m) {
					y--;
					break;
				}
			}
			if (x == n || y == m) {
				break;
			}
		}
		cout << (x + 1) << " " << (y + 1) << "\n";
	}
	return 0;
} 
