#include <iostream>
#include <vector>

template <typename T>
struct GraphNode {
    T data;
    std::vector<int> adjIndices;
};

struct Edge {
    int src, dest;
};

template <typename T>
class Graph {
public:
    std::vector<GraphNode<T>> nodes_;

    Graph(const std::vector<Edge> &edges, const std::vector<T> &data,
          int num_nodes, bool undirected = false) {
        nodes_.resize(num_nodes);

        for (int i = 0; i < num_nodes; ++i) {
            nodes_[i].data = data[i];
        }

        for (auto edge : edges) {
            nodes_[edge.src].adjIndices.push_back(edge.dest);
            if (undirected) {
                nodes_[edge.dest].adjIndices.push_back(edge.src);
            }
        }
    }

    void printGraph() {
        for (int j = 0; j < nodes_.size(); ++j) {
            std::cout << "Node " << j << " (value: " << nodes_[j].data << ") --> ";
            for (int idx : nodes_[j].adjIndices) {
                std::cout << idx << "  ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::vector<Edge> edges{
        {0, 1}, {0, 4}, {0, 5}, {1, 3}, {1, 4}, {2, 1}, {3, 2}, {3, 4}};
    std::vector<char> data{{'a', 'b', 'c', 'd', 'e', 'f'}};

    int N = 6;

    Graph<char> graph(edges, data, N, true);
    graph.printGraph();
}