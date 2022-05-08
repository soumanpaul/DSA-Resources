#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

struct Edge {
    int src, dest;
};

class Graph {
    Node **head;        // An array of pointers to Node to represent the adjacency list
    int numberOfNodes; // Number of nodes in the graph
    public:
        Graph(Edge edges[], int n, int N){
            head = new  Node*[N]();
            this->numberOfNodes = N;
            for(int i = 0; i < N; i++){
                head[i] = NULL;
            }
            for(int i = 0; i < n; i++){
                int src = edges[i].src;
                int dest = edges[i].dest;

                Node* newNode = getAdjListNode(dest, head[src]);
                head[src] = newNode;
            }
        }
        Node* getAdjListNode(int dest, Node *head) {
            Node* newNode = new Node;
            newNode->val = dest;
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

void printList(Node* ptr){
    while(ptr != NULL){
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main(){
    Edge edges[] = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}, {3, 3}};
    int n = sizeof(edges)/sizeof(edges[0]);
    Graph g(edges, n, 4);
    for(int i = 0; i < 4; i++){
        cout << "Adjacency list of vertex " << i << ": ";
        printList(g.head[i]);
    }
    return 0;
}