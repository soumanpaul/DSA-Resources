#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<T, list<pair<T, int>>> l;
    void add_edge(T src, T dest, int dist = -1, bool bdir = true) {
        l[src].pb({dest, dist});
        if (bdir)
            l[dest].pb({src, dist});
    }

    bool is_bipatite(int src, unordered_map<int, bool> &visited) {
        queue<pair<int, int>> q;
        q.push({src, 1});
        unordered_map<int, int> Set;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            visited[p.first] = true;
            q.pop();
            if (Set[p.first] != 0) {
                if (Set[p.first] != p.second) {
                    return false;
                }
            } else
                Set[p.first] = p.second;
            for (auto &it : l[p.first]) {
                if (Set[it.first] == 0) {
                    if (p.second == 1) {
                        q.push({it.first, 2});
                    } else {
                        q.push({it.first, 1});
                    }
                }
            }
        }
        return true;
    }

    bool is_bipatite() {
        unordered_map<int, bool> visited;
        for (auto &it : l) {
            if (!visited[it.first]) {
                if (!is_bipatite(it.first, visited)) {
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        Graph<int> g;
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                g.add_edge(i, graph[i][j]);
            }
        }
        return g.is_bipatite();
    }
};