#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int src, dest; 
};

class Graph {
    public:
        vector<vector<int>> adjList;
    
    Graph(vector<Edge> const &edges, int n){
        adjList.resize(n);
        for(auto &edge : edges){
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

void printGraph(Graph const &graph, int v){
    
    for(int i = 0; i < v; i++){
        	cout << i << " ——> ";
        for(int x : graph.adjList[i])
            cout << x<< " ";
        	cout << endl;
        }
}
 
int main () {
    int v = 4;
    vector<Edge> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}, {3, 3}};
    int n = 4;
    // construct graph
    Graph graph(edges, n);

    printGraph(graph,v);
    return 0;
}