#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<int> adj[], int v, int s) {
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty()) {
        int u = q.front();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void addEgde(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v) {
    for (int i = 0; i < v; i++) {
        for (int x : adj[i])
            cout << x << " ";
    }
}

int main() {
    int v = 4;
    vector<int> adj[v];
    // addEdge(adj, 0, 1)
    // addEdge(adj, 0, 2)
    // addEdge(adj, 1, 2)

    printGraph(adj, v);
    return 0;
}