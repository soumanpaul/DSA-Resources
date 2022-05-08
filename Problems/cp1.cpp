#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flag = false; // errorgorn
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            for(int j=1;j<a;j++){
              if(a-j > 0){
                 flag=true;
                 break; 
              }
            }
        }
    }
    return 0;
}