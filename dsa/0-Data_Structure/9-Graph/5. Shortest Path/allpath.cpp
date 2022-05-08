#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;

public:
    void dfs(vector<vector<int>> &graph, vector<int> &temp, int node) {
        temp.push_back(node);

        // Base Case
        if (node == graph.size() - 1) {
            ans.push_back(temp);
            return;
        }

        for (auto x : graph[node]) {
            dfs(graph, temp, x);
            temp.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<int> vec;
        dfs(graph, vec, 0);
        return ans;
    }
};