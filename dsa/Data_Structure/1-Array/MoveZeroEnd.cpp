#include<bits/stdc++.h>
using namespace std;

void moveZero(int arr[], int n) {
    int count = 0;
    for(int i =0; i <n; i++) {
        if(arr[i]!=0){
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

void rotate(vector<int>& v, int k) {
        int n = v.size();
        while(k>n) k -= n;
        std::reverse(v.begin()+n-k, v.end());
        std::reverse(v.begin(), v.begin()+n-k);
        std::reverse(v.begin(), v.end());
    }