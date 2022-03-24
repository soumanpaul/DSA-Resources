#include <iostream>
#include <vector>
using namespace std;

//  0 ms, faster than 100.00% of C++ online submissions for House Robber.
class Solution {
    vector<int> dp;

public:
    Solution() : dp(100, -1) {
    }
    int rob(vector<int> &nums) {
        return robRecurr(nums, nums.size() - 1);
    }
    int robRecurr(vector<int> &nums, int n) {
        if (n <= 0)
            return nums[0];
        if (n == 1)
            return max(nums[0], nums[1]);
        if (dp[n] == -1)
            dp[n] = max(robRecurr(nums, n - 1), robRecurr(nums, n - 2) + nums[n]);
        return dp[n];
    }
};

class Solution {
public:
    int rob(vector<int> &nums) {

        int i, n = nums.size();

        // dp[i] be the max robbery from the 1st i houses
        vector<int> dp(n + 2, 0);
        int ppMax, pMax, cMax;
        ppMax = pMax = cMax = 0;

        for (int i = 0; i < n; i++) {
            cMax = pMax;

            cMax = max(pMax, nums[i] + ppMax);
            ppMax = pMax;
            pMax = cMax;
            // dp[i + 2] = dp[i + 1];
            // dp[i + 2] = max(dp[i + 1], nums[i] + dp[i]);
        }
        return cMax;
    }
};