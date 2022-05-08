// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
#include <bits/stdc++.h>
using namespace std;

// ...........................Union Find.....................
class subset {
public:
    int parent;
    int rank;
};

int find(subset subsets[], int i) {
    // find root and make root as parent of i
    // (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// (uses union by rank)
void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high
    // rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // If ranks are same, then make one as root and
    // increment its rank by one
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

//  .................Graph......................DS

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    Edge *edge;
};
Graph *createGraph(int V, int E) {
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void *a, const void *b) {
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->weight > b1->weight;
}

void KruskalMST(Graph *graph) {
    int V = graph->V;
    Edge result[V]; // Tnis will store the resultant MST
    int e = 0;      // An index variable, used for result[]
    int i = 0;      // An index variable, used for sorted edges

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    subset *subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; ++v) { // Create V subsets with single elements
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int res = 0;
    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edge[i++]; // Step 2: Pick the smallest edge.
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) { // If including this edge does't cause cycle,
            result[e++] = next_edge;
            Union(subsets, x, y);
            res += next_edge.weight;
        }
    }
    cout << "Weight of MST is: " << res << endl;
    return;
}

// Driver code
int main() {
    int V = 5; // Number of vertices in graph
    int E = 7; // Number of edges in graph
    Graph *graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 8;

    // add edge 0-3
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 3;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    // add egde 2-4
    graph->edge[5].src = 2;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 12;

    // add edge 3-4
    graph->edge[6].src = 3;
    graph->edge[6].dest = 4;
    graph->edge[6].weight = 15;

    KruskalMST(graph);

    return 0;
}

// This code is contributed by rathbhupendra
