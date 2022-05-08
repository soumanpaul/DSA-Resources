#include<bits/stdc++.h>
using namespace std;
#include <unordered_set>
#include <random>
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
//#define vec vector<ll>
//#define mat vector<vector<ll> >
#define fi first
#define se second
#define double long double
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
//typedef long double ld;
typedef complex<double> Complex;
const ll INF=1e9+7;
const ll MOD=998244353;
const ll inf=INF*INF;
const ll mod=MOD;
const ll MAX=200010;
const double PI=acos(-1.0);
typedef vector<vector<ll> > mat;
typedef vector<ll> vec;




void solve(){
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        ll k;cin>>k;
        k--;
        vector<string>s(n);
        rep(i,n)cin>>s[i];
        ll res=k;
        vector<vector<ll> >dp(n,vector<ll>(m));
        dp[0][0]=k;
        rep(i,n){
            rep(j,m){
                if(s[i][j]=='0'){
                    if(j==m-1)continue;
                    else if(i==n-1){
                        if(dp[i][j]>=1){
                            dp[i][j+1]++;
                        }
                    }else{
                        dp[i+1][j]+=dp[i][j]/2;
                        dp[i][j+1]+=dp[i][j]-dp[i][j]/2;
                    }
                }else{
                    if(i==n-1)continue;
                    else if(j==m-1){
                        if(dp[i][j]>=1){
                            dp[i+1][j]++;
                        }
                    }else{
                        dp[i][j+1]+=dp[i][j]/2;
                        dp[i+1][j]+=dp[i][j]-dp[i][j]/2;
                    }
                }
            }
        }
        ll x=0,y=0;
        while(1){
            if(s[x][y]=='0'){
                if(y==m-1)break;
                else if(x==n-1){
                    if(dp[x][y]>=1){
                        break;
                    }else{
                        y++;
                    }
                }else{
                    if(dp[x][y]%2==0){
                        y++;
                    }else{
                        x++;
                    }
                }
            }else{
                if(x==n-1)break;
                else if(y==m-1){
                    if(dp[x][y]>=1){
                        break;
                    }else{
                        x++;
                    }
                }else{
                    if(dp[x][y]%2==0){
                        x++;
                    }else{
                        y++;
                    }
                }
            }
        }
        cout<<x+1<<' '<<y+1<<endl;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}