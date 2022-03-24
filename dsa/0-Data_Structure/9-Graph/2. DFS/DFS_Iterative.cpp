#include <iostream>
using namespace std;

class DFS_Iterative {
public:
    void dfsIterative(vector<int> &adjList, int source, int destination) {

        stack<int> nodes;
        vector<bool> visited(adjList.size());
        nodes.push(source);

        while (!nodes.empty()) {
            int current = nodes.top();
            nodes.pop();

            // do anything with current

            for (int x : adjList[current]) {
                nodes.push(x);
            }
        }
    }
};