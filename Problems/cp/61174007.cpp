#include<bits/stdc++.h>
using namespace std; 
 
#define fast            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli             long long int
#define ld              long double
#define pll             pair<lli,lli>
#define ve              vector<lli>
#define vep             vector<pll>
#define pb              push_back
#define mp              make_pair
#define all(x)          (x).begin(),(x).end()
#define fr(i,a,n)       for(lli i=a;i<(n);i++)
#define frx(i,a,n)      for(lli i=a;i>(n);i--)
#define lb              lower_bound
#define ub              upper_bound
#define F               first
#define S               second
#define endl            '\n'
#define op(x)           cout<<x<<endl
#define op2(x,y)        cout<<x<<" "<<y<<endl
#define parr(arr,a,n)   fr(u,a,n) cout<<arr[u]<<" "; cout<<endl
#define yes             cout<<"YES"<<endl
#define no              cout<<"NO"<<endl
#define mem(a,x)        memset(a,x,sizeof(a))
#define sz(a) 		    ((lli) a.size())
#define INF             (lli)4e18

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

//-----------------------------------------CODE_BEGINS----------------------------//

lli n,m,k;

lli f(lli r,lli c,char x){
    if(r==n-1 && x=='1')return 0;
    if(c==m-1 && x=='0')return 0;
    return 1;
}

void solve(){
    cin>>n>>m>>k;
    string c[n];
    fr(i,0,n)cin>>c[i];
    lli cnt[n+5][m+5]={0};
    mem(cnt,0);
    k--;
    cnt[0][0]=k;
    fr(i,1,n){
        if(m==1){
            if(c[i-1][0]=='1' && cnt[i-1][0])cnt[i][0]++;
        }
        else{
            if(c[i-1][0]=='1')cnt[i][0]=(1+cnt[i-1][0])/2;
            else cnt[i][0]=(cnt[i-1][0])/2;
        }
    }
    fr(i,1,m){
        if(n==1){
            if(c[0][i-1]=='0' && cnt[0][i-1])cnt[0][i]++;
        }
        else{
            if(c[0][i-1]=='0')cnt[0][i]=(1+cnt[0][i-1])/2;
            else cnt[0][i]=cnt[0][i-1]/2;
        }
    }
    fr(i,1,n){
        fr(j,1,m){
            if(j==m-1){
                if(c[i-1][j]=='0' || !cnt[i-1][j]);
                else cnt[i][j]++;
            }
            else{
                if(c[i-1][j]=='1')cnt[i][j]+=(1+cnt[i-1][j])/2;
                else cnt[i][j]+=(cnt[i-1][j])/2;
            }
            if(i==n-1){
                if(c[i][j-1]=='1' || !cnt[i][j-1]);
                else cnt[i][j]++;
            }
            else{
                if(c[i][j-1]=='0')cnt[i][j]+=(1+cnt[i][j-1])/2;
                else cnt[i][j]+=cnt[i][j-1]/2;
            }
        }
    }
    // fr(i,0,n){
    //     fr(j,0,m)cout<<cnt[i][j]<<" ";
    //     cout<<endl;
    // }
    fr(i,0,n){
        fr(j,0,m){
            if(cnt[i][j]==0)continue;
            else if(i==n-1)c[i][j]='1';
            else if(j==m-1)c[i][j]='0';
            else{
                if(cnt[i][j]%2){
                    if(c[i][j]=='1')c[i][j]='0';
                    else c[i][j]='1';
                }
            }
        }
    }
    lli r=0,cc=0;
    while(1){
        if(c[r][cc]=='0'){
            if(cc==m-1)break;
            else cc++;
        }
        else{
            if(r==n-1)break;
            else r++;
        }
    }
    op2(r+1,cc+1);
}

int main(){
    fast;
    lli test=1;
    cin>>test;
    while(test--){
        solve();
    }
}