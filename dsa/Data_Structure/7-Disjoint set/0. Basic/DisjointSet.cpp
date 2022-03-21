#include <bits/stdc++.h>
using namespace std;
#define n 5

class UnionFind {
    vector<int> root;

public:
    // Constructor of Union-find. The size is the length of the root array.
    UnionFind(int sz) : root(sz) {}
    int find(int x);
    void unionSet(int x, int y);
    bool connected(int x, int y);
};

int UnionFind::find(int x) {
    while (x != root[x]) {
        x = root[x];
    }
    return x;
}
void UnionFind::unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        root[rootY] = rootX;
    }
}

bool UnionFind::connected(int x, int y) {
    return find(x) == find(y);
}

// The find function – optimized with path compression:
/*int find(int x) {
    if (x == root[x]) {
        return x;
    }
    return root[x] = find(root[x]);
} */

// The union function – Optimized by union by rank:
/*
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            root[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
        } else {
            root[rootY] = rootX;
            rank[rootX] += 1;
        }
    }
}
*/

int main() {
    return 0;
}