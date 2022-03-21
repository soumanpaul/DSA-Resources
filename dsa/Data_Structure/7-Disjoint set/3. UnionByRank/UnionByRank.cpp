#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = i;
        }
    }
    int find(int x) {
        while (x != root[x])
            x = root[x];
        return x;
    }
    void unionSet(int x, int y) {
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
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};