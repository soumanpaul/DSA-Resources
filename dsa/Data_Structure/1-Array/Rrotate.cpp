#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void reverseArray(vector<int>& arr, int start,int end){
        while (start < end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
 
    void rightRotate(vector<int>& arr, int d, int n){
        // if in case d>n,this will give segmentation fault.
        d=d%n;
        reverseArray(arr, 0, n-1);
        reverseArray(arr, 0, d-1);
        reverseArray(arr, d, n-1);
    }

    void rotate(vector<int>& nums, int k) {
        rightRotate(nums,k,nums.size());
    }
};