#include <iostream>
#include <list>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

// Approach 1 : Graph Theory + Iterative Depth - First Search
class Solution {
    list<list<int>> adj;

public:
    bool validTree(int n, vector<vector<int>> &edges) {

        for (int i = 0; i < n; i++) {
            // adj.push_back()
        }
    }
};

// Approach 2 : Advanced Graph Theory + Iterative Depth - First Search

class Solution {
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() != n - 1)
            return false;

        stack<int> stack;
        unordered_set<int> hashSet;
        stack.push(0);
        hashSet.insert(0);
    }
};

// Approach 3: Advanced Graph Theory + Union Find

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
    bool validTree(int n, vector<vector<int>> &edges) {
        UnionFind uf(n);
        for (int i = 0; i < edges.size(); i++) {
            int x = uf.find(edges[i][0]);
            int y = uf.find(edges[i][1]);
            if (x == y) {
                return false;
            } else {
                uf.Union(edges[i][0], edges[i][1]);
            }
        }
        return true && uf.getCount() == 1;
    }
};