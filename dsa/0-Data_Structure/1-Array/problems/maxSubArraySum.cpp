#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = nums[0];
        int maxEnding = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxEnding = max(maxEnding + nums[i], nums[i]);
            sum = max(sum, maxEnding);
        }
        return sum;
    }
};

// DP solution
class Solution {

public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int maxi = dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
            maxi = max(dp[i], maxi);
        }
        return maxi;
    }
};

// ALL
class Solution {
public:
    int helper(vector<int> &nums, int lo, int hi) {
        if (lo == hi)
            return nums[lo];
        int sum = 0;
        int mid = (lo + hi) / 2;
        int leftSum = INT_MIN, rightSum = INT_MIN;
        for (int i = mid; i >= lo; i--) {
            sum += nums[i];
            leftSum = max(sum, leftSum);
        }
        sum = 0;
        for (int i = mid + 1; i <= hi; i++) {
            sum += nums[i];
            rightSum = max(sum, rightSum);
        }
        int maxSum = max(helper(nums, lo, mid), helper(nums, mid + 1, hi));
        int ans = max(maxSum, leftSum + rightSum);
        return ans;
    }
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();

        // Approach:1 Kadane's Algo.
        // int maxSum=INT_MIN,sum=0;
        // for(int i=0;i<n;i++)
        // {
        //     sum+=nums[i];
        //     maxSum=max(sum,maxSum);
        //     if(sum<0)
        //         sum=0;
        // }
        // return maxSum;

        // Approach:2 DP
        // vector<int> dp(n,0);
        // int maxSum=nums[0];
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++)
        // {
        //     dp[i]=max(dp[i-1]+nums[i],nums[i]);
        //     maxSum=max(dp[i],maxSum);
        // }
        // return maxSum;

        // Approach:3 Divide and Conquer
        return helper(nums, 0, n - 1);
    }
};