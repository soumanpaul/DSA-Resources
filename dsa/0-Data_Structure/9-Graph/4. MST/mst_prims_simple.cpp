#include <bits/stdc++.h>
using namespace std;
int V = 10;
int minKey(int key[], bool mstSet[]) {
    int min_key = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min_key) {
            min_key = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[][], int v) {
    int parent[v];
    int key[v];
    bool mstSet[v];

    for (int i = 0; i < v; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < v - 1; i++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        // Update key value and parent index of // the adjacent vertices of the picked vertex. // Consider only those vertices which are not // yet included in MST
        for (int j = 0; j < v; j++) {
            if (graph[u][j] && mstSet[j] == false && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    // printMST(parent, graph);
}

int main() {
    int vec[10][10];
    primMST(vec, 5);
    return 0;
}