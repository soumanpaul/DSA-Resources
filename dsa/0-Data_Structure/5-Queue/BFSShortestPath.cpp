#include <bits/stdc++.h>
using namespace std;

struct Node {
};

int BFS(Node root, Node target) {
    queue<Node> queue; // store all nodes which are waiting to be processed
    set<Node> visited; // store all the nodes that we've visited
    int step = 0;      // number of steps neeeded from root to current node // initialize
    queue.push_back(root);
    visited.push_back(root);

    // BFS
    while (!queue.isEmpty()) {
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = queue.font();
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                if (next is not in visited) {
                    add next to queue;
                    add next to visited;
                }
            }
            queue.pop();
        }
        step = step + 1;
    }
    return -1; // there is no path from root to target
}