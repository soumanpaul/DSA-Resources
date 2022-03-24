#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {

        vector<vector<int>> adjList(n);

        for (vector<int> edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        stack<int> stack;
        vector<bool> visited(n);
        stack.push(source);

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();

            if (current == destination)
                return true;
            if (visited[current])
                continue;
            visited[current] = true;

            for (int neighbor : adjList[current]) {
                stack.push(neighbor);
            }
        }
        return false;
    }
};