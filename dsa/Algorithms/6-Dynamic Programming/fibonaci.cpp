#include <cmath>
#include <iostream>
using namespace std;

// Recursion
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// Top-Down Approach using Memoization
class Solution {
    int dp[31];

public:
    int fib(int n) {
        if (n < 2)
            return n;
        if (!dp[n])
            dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
};

// Approach 2 : Bottom - Up Approach using Tabulation
class Solution {
public:
    int fib(int n) {
        int dp[31];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Approach 4 : Iterative Bottom - Up Approach
class Solution {
public:
    int fib(int n) {
        int current = 0;
        int prev1 = 1, prev2 = 0;
        if (n <= 1)
            return n;
        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};
// 4. Matrix Exponentatioin

class Solution {
public:
    int fib(int n) {
        int F[2][2] = {{1, 1}, {1, 0}};
        if (n == 0)
            return 0;
        power(F, n - 1);
        return F[0][0];
    }
    // void power(int F[2][2], int n) {
    //     int M[2][2] = {{1, 1}, {1, 0}};

    //     for (int i = 2; i <= n; i++)
    //         multiply(F, M);
    // }

    // Optimized
    void power(int F[2][2], int n) {
        if (n == 0 || n == 1)
            return;
        int M[2][2] = {{1, 1}, {1, 0}};

        power(F, n / 2);
        multiply(F, F);
        if (n % 2 != 0)
            multiply(F, M);
    }

    void multiply(int F[2][2], int M[2][2]) {
        int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
        int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
        int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
        int w = F[1][0] * M[1][1] + F[1][1] * M[1][1];

        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
    // Math formula
    int fib(int N) {
        double goldenRatio = (1 + sqrt(5)) / 2;
        return round(pow(goldenRatio, N) / sqrt(5));
    }
};