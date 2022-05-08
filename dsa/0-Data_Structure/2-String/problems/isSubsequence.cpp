#include <cmath>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

// Approach 1: Divide and Conquer with Greedy

class Solution {
    string source, target;
    int leftBound, rightBound;

private:
    bool rec_isSubsequence(int leftIndex, int rightIndex) {
        // base cases
        if (leftIndex == leftBound)
            return true;
        if (rightIndex == rightBound)
            return false;
        // consume both strings or just the target string
        if (source.at(leftIndex) == target.at(rightIndex))
            ++leftIndex;
        ++rightIndex;

        return rec_isSubsequence(leftIndex, rightIndex);
    }

    bool isSubsequence(string s, string t) {
        this->source = s;
        this->target = t;
        this->leftBound = s.length();
        this->rightBound = t.length();

        return rec_isSubsequence(0, 0);
    }
};

// Approach 2 : Two -Pointers

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int leftBound = s.length();
        int rightBound = t.length();
        int pLeft = 0;
        int pRight = 0;

        while (pLeft < leftBound && pRight < rightBound) {
            if (s.at(pLeft) == t.at(pRight)) {
                pLeft += 1;
            }
            pRight += 1;
        }
        return pLeft == leftBound;
    }
};

// Approach 3: Greedy Match with Character Indices Hashmap
class Solution {
public:
    bool isSubsequence(string s, string t) {

        // precomputation, build the hashmap out of the target string
        unordered_map<char, list<int>> letterIndicesTable;
        for (int i = 0; i < t.length(); ++i) {
            if (letterIndicesTable.find(t.at(i)))
                letterIndicesTable.find(t.at(i)).push_back(i);
            else {
                vector<int> indices;
                indices.push_back(i);
                letterIndicesTable.insert(make_pair(t.at(i), indices));
            }
        }

        int currMatchIndex = -1;
        for (char letter : s.toCharArray()) {
            if (!letterIndicesTable.containsKey(letter))
                return false; // no match, early exist

            bool isMatched = false;
            // greedy match with linear search
            for (int matchIndex : letterIndicesTable.get(letter)) {
                if (currMatchIndex < matchIndex) {
                    currMatchIndex = matchIndex;
                    isMatched = true;
                    break;
                }
            }
            if (!isMatched)
                return false;
        }
        // consume all characters in the source string
        return true;
    }
};

// Approach 4: Dynamic Programming

class Solution {

public:
    bool isSubsequence(string s, string t) {

        int sourceLen = s.length(), targetLen = t.length();
        if (sourceLen == 0)
            return true;

        int dp[sourceLen + 1][targetLen + 1];
        // DP calculation, we fill the matrix column by column, bottom up
        for (int col = 1; col <= targetLen; ++col) {
            for (int row = 1; row <= sourceLen; ++row) {
                if (s.at(row - 1) == t.at(col - 1))
                    // find another match
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                else
                    // retrieve the maximal result from previous prefixes
                    dp[row][col] = math.max(dp[row][col - 1], dp[row - 1][col]);
            }
            // check if we can consume the entire source string,
            // with the current prefix of the target string.
            if (dp[sourceLen][col] == sourceLen)
                return true;
        }
        // matching failure
        return false;
    }
};

class Solution {
    int isSubSequence(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] = 1 + isSubSequence(s1, s2, i - 1, j - 1, dp);
        } else {
            return dp[i][j] = isSubSequence(s1, s2, i, j - 1, dp);
        }
    }

public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m > n) {
            return false;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        if (isSubSequence(s, t, m, n, dp) == m) {
            return true;
        } else {
            return false;
        }
    }
};