// #pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define nn "\n"
#define sci(x) scanf("%d", &x)
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (!!(x & (1LL << k)))
#define mod 998244353
#define N 1000006


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;

        int x[n][m];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c;
                cin >> c;
                x[i][j] = c-'0';
            }
        }

        int val[n+1][m+1];
        memset(val, 0, sizeof val);
        val[0][0] = k-1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int z1 = (val[i][j]+1)/2;
                int z2 = val[i][j]/2;

                if(x[i][j]==0){
                    val[i][j+1] += z1;
                    val[i+1][j] += z2;
                }
                else {
                    val[i+1][j] += z1;
                    val[i][j+1] += z2;
                }


                if(i==n-1 || j==m-1){
                    if(i==n-1 && j!=m-1){
                        if(val[i][j]){
                            x[i][j] = 1;
                        }
                    }
                    if(i!=n-1 && j==m-1){
                        if(val[i][j]){
                            x[i][j] = 0;
                        }
                    }
                }
                else if(val[i][j]%2) x[i][j] = !x[i][j];
            }
        }

        int px = 0, py = 0;
        while(1){
            if(x[px][py]==0 && py+1>=m) break;
            if(x[px][py]==1 && px+1>=n) break;

            if(x[px][py]==0) py++;
            else px++;
        }

        px++;
        py++;

        cout << px << " " << py << nn;
    }


    return 0;
}