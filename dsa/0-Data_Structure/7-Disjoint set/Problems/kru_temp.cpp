#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parents;
    vector<int> ranks;

public:
    DisjointSet(int n) : parents(n), ranks(n) {
        for (int i = 0; i < n; i++) {
            parents[i] = 0;
            ranks[i] = 0;
        }
    }

    int find(int x) {
        if (x == parents[x]) {
            return x;
        }
        return parents[x] = find(parents[x]);
    }
    void Union(int u, int v) {
        int uP = find(u);
        int vP = find(v);

        if (uP != vP) {
            if (ranks[uP] > ranks[vP]) {
                parents[vP] = uP;
            } else if (ranks[uP] < ranks[vP]) {
                parents[uP] = vP;
            } else {
                parents[uP] = vP;
                ranks[vP]++;
            }
        }
    }
};

long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) {

    DisjointSet DS(n);
    int v = n;
    sort(adj, adj + v);
    int cost = 0;
    long long int minCost = 0;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int u = i;
            int v = adj[i][j].first;
            cost = adj[i][j].second;
            // cout << u << " "<< v << " "<<cost<<endl;
            if (DS.find(u) != DS.find(v)) {

                minCost += cost;
                DS.Union(u, v);
            }
        }
    }
    return minCost;
}

int main() {
    int t = 1;
    // cin >> t;
    vector<pair<int, long long int>> adj[100009];
    while (t--) {

        int n = 5, m = 6;
        // cin >> n >> m;

        int u, v;
        long long w;
        vector<vector<int>> edges{{1, 2, 4}, {1, 3, 3}, {2, 4, 1}, {2, 5, 1}, {4, 5, 3}, {3, 4, 2}};

        for (int i = 0; i < m; i++) {
            u = edges[i][0];
            v = edges[i][1];
            w = edges[i][2];
            // cin >> u >> v >> w;

            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        cout << kruskalDSU(adj, n, m) << endl;

        for (int i = 0; i <= n; i++) {
            if (adj[i].size())
                for (auto x : adj[i]) {
                    cout << i << " x.fisrst : " << x.first << " "
                         << "x.second : " << x.second << endl;
                }
            // adj[i].clear();
        }
    }
    return 0;
}
// } Driver Code Ends