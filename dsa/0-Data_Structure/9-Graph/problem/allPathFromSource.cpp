#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
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
            temp.pop_back(); // backtracking
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<int> vec;
        dfs(graph, vec, 0);
        return ans;
    }
};

class Solution {
    vector<vector<int>> ans;
    int target;
    int graph;
    unordered_map < int, vector<vector<int>> memo;

public:
    vector<vector<int>> allPathsToTarget(int currentNode) {
        // memoization. check the result in the cache first
        if (memo.find(currentNode))
            return memo[currentNode];

        vector<vector<int>> results;

        // base case
        if (currentNode == this.target) {
            vector<int> list;
            list.push_back(target);
            results.push_back(list);
            return results;
        }
        // Iterate through path starting from each neighbor
        for (int nextNode : this.graph[currentNode]) {
            for (vector<int> path : allPathsToTarget(nextNode)) {
                vector<int> newPath;
                newPath.psuh_back(currentNode);
                newpath.push_back(path);
                results.push_back(newPath);
            }
        }
        memo.add(currNode, results);
        return results;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        this.target = raph.size();
        this.graph = graph;

        return allPathsToTarget(0);
    }
};