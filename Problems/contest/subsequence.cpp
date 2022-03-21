/*
 Detailed Explanations: Describe the algorithm you used to solve this problem. Include any insights you used to solve this problem.
 Images that help explain the algorithm.
 Language and Code you used to pass the problem.
 Time and Space complexity analysis.


An integer array is called arithmetic if it consists of at least three elements
and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.
*/

/*
Approach 1: Brute Force

Approach 2: Better Brute Force

Approach 3: Using Recursion

Approach 4: Dynamic Programming

Approach 5: Constant Space Dynamic Programming

Approach 6: Using Formula
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Brute Force

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int count = 0;
        for (int s = 0; s < nums.size() - 2; s++) {
            int d = nums[s + 1] - nums[s];
            for (int e = s + 2; e < nums.size(); e++) {
                int i = 0;
                for (i = s + 1; i <= e; i++)
                    if (nums[i] - nums[i - 1] != d)
                        break;
                if (i > e)
                    count++;
            }
        }
        return count;
    }
};

// Approach 2: Better Brute Force

/*
    that if we are currently considering the range bound by the elements, let's say,
    A[s]A[s](start) and A[e]A[e](end), we have checked the consecutive elements in
    this range to have the same difference. Now, when we move on to the next range
    between the indices ss and e+1e+1, we again perform a check on all the elements
    in the range s:es:e, along with one additional pair A[e+1]A[e+1] and A[e]A[e].
    We can remove this redundant check in the range s:es:e and just check the last
    pair to have the same difference as the one used for the previous range(same
    ss, incremented ee).
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        if (nums.size() < 3)
            return 0;
        int count = 0, d;
        for (int i = 0; i < nums.size() - 2; ++i) {
            d = nums[i + 1] - nums[i];
            for (int j = i + 2; j < nums.size(); ++j) {
                if (nums[j] - nums[j - 1] == d)
                    ++count;
                else
                    break;
            }
        }
        return count;
    }
};

/*
Complexity Analysis

Time complexity : O(n^2)O(n2). Two for loops are used.

Space complexity : O(1)O(1). Constant extra space is used.
*/

// Approach 3 : Using Recursion Algorithm

// public

class Solution {
    int sum = 0;

public:
    int numberOfArithmeticSlices(vector<int> &A) {
        slices(A, A.size() - 1);
        return sum;
    }

public:
    int slices(vector<int> &A, int i) {
        if (i < 2)
            return 0;
        int ap = 0;
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            ap = 1 + slices(A, i - 1);
            sum += ap;
        } else
            slices(A, i - 1);
        return ap;
    }
};

// Approach 4 : Dynamic Programming

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        vector<int> dp;
        int sum = 0;
        for (int i = 2; i < dp.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = 1 + dp[i - 1];
                sum += dp[i];
            }
        }
        return sum;
    }
};

// Approach 5 : Constant Space Dynamic Programming
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int dp = 0;
        int sum = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp = 1 + dp;
                sum += dp;
            } else
                dp = 0;
        }
        return sum;
    }
};
// Approach 6 : Using Formula

// public
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int count = 0;
        int sum = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                count++;
            } else {
                sum += (count + 1) * (count) / 2;
                count = 0;
            }
        }
        return sum += count * (count + 1) / 2;
    }
};