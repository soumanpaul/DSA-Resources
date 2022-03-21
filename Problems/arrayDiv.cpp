#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int mian() {

    int n;
    cin >> n;
    vector<int> A(n+5,0);
    long long s =0;
    for(int i = 0; i< n ; i++) cin >> A[i], s+= A[i];
    if (s & 1){
        cout << "NO";
        return 0;
    }
    map<long long, int> first, second;

    first[A[0]] = 1;

    for(int i = 1; i < n; i++) second[A[i]]++;

    long long sdash = 0;

    for(int i = 0; i < n; i++){
        sdash += A[i]; // first i numbers
        if (sdash == s / 2){
            cout << "YES\n";
            return 0;
        }
        if (sdash < s/2){
            long long x = s/2 - sdash;
            // delete from  second half, and insert into first half
            if(second[x] > 0) {
                cout << "YES\n";
                return 0; 
            }
        } else {
            long long y = sdash - s/2;
            if(first[y] > 0){
                cout << "YES\n";
                return 0;
            }
        }
        //i+1
        first[A[i+1]]++;
        second[A[i+1]]--;
    }
    cout << "NO\n";
}