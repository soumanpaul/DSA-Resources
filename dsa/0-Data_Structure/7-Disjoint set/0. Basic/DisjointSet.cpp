#include <bits/stdc++.h>
using namespace std;
#define n 5

class UnionFind {
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int sz) : parent(sz) {
        for (int i = 0; i < sz; i++) {
            parent[i] = i;
            rank[i] = i;
        }
    }
    int find(int x);
    void unionSet(int x, int y);
    bool connected(int x, int y);
};

int UnionFind::find(int x) {

    // iterative code
    // while (x != parent[x]) {
    //     x = parent[x];
    // }
    // return x;

    // Recursive code
    if (parent[x] == x) {
        return x;
    } else {
        return find(parent[x]);
    }
}
void UnionFind::unionSet(int x, int y) {
    int parentX = find(x);
    int parentY = find(y);
    if (parentX != parentY) {
        parent[parentY] = parentX;
    }
}

bool UnionFind::connected(int x, int y) {
    return find(x) == find(y);
}

// The find function – optimized with path compression:
/*int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
} */

// The union function – Optimized by union by rank:
/*
void unionSet(int x, int y) {
    int parentX = find(x);
    int parentY = find(y);
    if (parentX != parentY) {
        if (rank[parentX] > rank[parentY]) {
            parent[parentY] = parentX;
        } else if (rank[parentX] < rank[parentY]) {
            parent[parentX] = parentY;
        } else {
            parent[parentY] = parentX;
            rank[parentX] += 1;
        }
    }
}
*/

int main() {
    return 0;
}