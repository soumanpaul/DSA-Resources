class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> v(26, 0);
        vector<bool> values(26, false);
        for (int i = 0; i < s.size(); i++)
            v[s[i] - 'a']++;
        string results = "";
        int n = s.size();
        for (char c : s) {
            v[c - 'a']--;
            if (results.size() == 0) {
                results.push_back(c);
                values[c - 'a'] = true;
                continue;
            }
            if (values[c - 'a'])
                continue;
            while (c < results.back() && results.size() != 0 && v[results.back() - 'a'] > 0) {
                values[results.back() - 'a'] = false;
                results.pop_back();
            }
            results.push_back(c);
            values[c - 'a'] = true;
        }
        return results;
    }
};