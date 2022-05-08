#include <iostream>
#include <queue>
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

//  Recursion + memo
class Solution {
    vector<vector<int>> ans;
    int target;
    int graph;
    unordered_map<int, vector<vector<int>>> memo;

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

// BFS  Time : 2^V. v

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> paths;
        if (graph.size() == 0) {
            return paths;
        }

        vector<int> path;
        queue<vector<int>> q;
        path.push_back(0);
        q.push(path);

        while (!q.empty()) {
            vector<int> currentPath = q.front();
            q.pop();
            int node = currentPath.back();
            for (int nextNode : graph[node]) {
                vector<int> tmpPath(currentPath.begin(), currentPath.end());
                tmpPath.push_back(nextNode);
                if (nextNode == graph.size() - 1) {
                    paths.push_back(tmpPath);
                } else {
                    q.push(tmpPath);
                }
            }
        }
        return paths;
    }
};