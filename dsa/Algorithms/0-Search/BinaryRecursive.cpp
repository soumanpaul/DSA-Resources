#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int x) { 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 


int main() {
    int t;
    vector<int>arr;
    cin >> t;
    while(t--){
        int n, item,searchItem;
        cin >> n >> searchItem;
        for(int i=0; i< n; i++){
            cin >> item;
            arr.push_back(item);
        }
       cout << "Search item...:"<< binarySearch(arr, 0, n, searchItem);
    }    
    return 0;
}