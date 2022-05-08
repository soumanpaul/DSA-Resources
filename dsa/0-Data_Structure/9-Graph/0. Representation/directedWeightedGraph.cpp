#include<iostream>
using namespace std;

struct Node {
    int val, cost;
    Node *next;
}
struct Edge {
    int src, dest, weight;
}

class Graph {
    Node** head;  // An array of pointers to Node to represent the adjacency list
    int numberOfNodes; // Number of nodes in the graph
    
    public:

        Graph(Edge edges[], int n, int N){
            head = new Node*[N]();
            this->numberOfNodes = N;
            for(int i = 0; i < N; i++){
                head[i] = NULL;
            }
            for(int i = 0; i < n; i++){
                int src = edges[i].src;
                int dest = edges[i].dest;
                int weight = edges[i].weight;

                Node* newNode = getAdjListNode(dest, weight, head[src]);
                head[src] = newNode;
        }
        Node* getAdjListNode(int value, int weight, Node *head) {
            Node* newNode = new Node;
            newNode->val = value;
            newNode->cost = weight;
            newNode->next = head;
            return newNode;
        }
        ~Graph(){
            for(int i = 0; i < N; i++){
                    delete[] head[i];
                }
            delete[] head;
        }
};



int main() {
    Edge edges[] ={{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    int n = sizeof(edges)/sizeof(edges[0]);
    Graph g(edges, n, 4);
}
