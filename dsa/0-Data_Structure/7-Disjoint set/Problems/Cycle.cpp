#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Edge {
    int src, dest;
};

class Graph {

public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int n) {
        adjList.resize(n);
        for (auto &edge : edges) {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

// Disjoint set Data Structure
class DisjointSet {
    unordered_map<int, int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = i;
        }
    }
    int Find(int k) {
        if (parent[k] == k) {
            return k;
        }
        return parent[k] = Find(parent[k]);
    }
    void Union(int a, int b) {
        int x = Find(a);
        int y = Find(b);
        if (x != y) {
            if (rank[x] > rank[y]) {
                parent[y] = x;
            } else if (rank[x] < rank[y]) {
                parent[x] = y;
            } else {
                parent[x] = y;
                rank[y]++;
            }
        }
    }
};

// Returns true if the graph has a cycle
bool findCycle(Graph const &graph, int n) {

    DisjointSet ds(n);

    // consider every edge (u, v)
    for (int u = 0; u < n; u++) {
        // Recur for all adjacent vertices
        for (int v : graph.adjList[u]) {
            // find the root of the sets to which elements `u` and `v` belongs
            int x = ds.Find(u);
            int y = ds.Find(v);

            // if both `u` and `v` have the same parent, the cycle is found
            if (x == y) {
                return true;
            } else {
                ds.Union(x, y);
            }
        }
    }
    return false;
}

// Union–find algorithm for cycle detection in a graph

int main() {
    vector<Edge> edges = {{0, 1}, {0, 6}, {0, 7}, {1, 2}, {1, 5}, {2, 3}, {2, 4}, {7, 8}, {7, 11}, {8, 9}, {8, 10}, {10, 11}};
    int n = 12;
    Graph graph(edges, n);
    if (findCycle(graph, n))
        cout << "Cycle Found";
    else
        cout << "No Cycle Found";
    return 0;
}
