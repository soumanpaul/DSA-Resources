#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
        bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        int l1 = s.length(), l2 = t.length();
        int i = 0;

        while (l1--) {
            char ch = s[i];
            if (ch == '#') {
                if (!s1.empty())
                    s1.pop();
            } else
                s1.push(ch);
            i++;
        }

        i = 0;
        while (l2--) {
            char ch = t[i];
            if (ch == '#') {
                if (!s2.empty())
                    s2.pop();
            } else
                s2.push(ch);
            i++;
        }

        if (s1.size() != s2.size())
            return false;

        while (!s1.empty()) {
            char c1 = s1.top();
            char c2 = s2.top();
            if (c1 != c2)
                return false;
            s1.pop();
            s2.pop();
        }

        return true;
    }
};