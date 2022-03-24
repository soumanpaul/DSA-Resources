// quick find implementation

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> root;

public:
    UnionFind(int sz) : root(sz) {
        for (int i = 0; i < sz; i++)
            root[i] = i;
    }

    int find(int x) { return root[x]; }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            for (int i = 0; i < root.size(); i++) {
                if (root[i] == rootY)
                    root[rootY] = rootX;
            }
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {

    UnionFind uf(10);

    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);

    cout << uf.connected(1, 5) << endl;

    uf.unionSet(9, 4);

    return 0;
}