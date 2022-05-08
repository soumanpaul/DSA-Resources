#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    list<int> *adj;

public:
    Graph(int v) {
        this->v = v;
        adj = new list<int>[v];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Return true if the graph contain cycle, else false
    bool isCyclic() {
        bool *visited = new bool[v];
        bool *recStack = new bool[v];
        memset(visited, 0, sizeof visited);
        memset(recStack, 0, sizeof recStack);

        for (int i = 0; i < v; i++) {
            if (checkCycle(i, visited, recStack))
                return true;
        }
    }

    bool checkCycle(int v, bool visited[], bool *recStack) {
        if (visited[v] == false) {
            visited[v] = true;
            recStack[v] = true;

            for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
                if (!visited[*i] && checkCycle(*i, visited, recStack)) {
                    return true;
                } else if (recStack[*i])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }
};