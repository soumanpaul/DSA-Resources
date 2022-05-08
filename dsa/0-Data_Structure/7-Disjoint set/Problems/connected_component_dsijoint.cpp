#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
    int count;

public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = i;
        }
        count = sz;
    }
    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }
    int find(int x) {
        if (x == root[x])
            return x;
        root[x] = find(root[x]);
        return root[x];
    }
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
    int getCount() {
        return count;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>> &edges) {
        vector<int> vec;
        UnionFind uf(n);
        for (int i = 0; i < edges.size(); i++) {
            uf.Union(edges[i][0], edges[i][1]);
        }
        return uf.getCount();
    }
};