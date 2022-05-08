#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

bool DFS(Node *cur, Node *target, set<Node *> visited) {
    if (cur == target)
        return true;
    for (auto next : cur) {
        if (next is not in visited) {
            add next to visted;
            return true if DFS (next, target, visited) == true;
        }
    }
    return false;
}

/*
 * Return true if there is a path from cur to target.
 */
boolean DFS(int root, int target) {
    Set<Node> visited;
    Stack<Node> stack;
    add root to stack;
    while (stack is not empty) {
        Node cur = the top element in stack;
        remove the cur from the stack;
        return true if cur is target;
        for (Node next : the neighbors of cur) {
            if (next is not in visited) {
                add next to visited;
                add next to stack;
            }
        }
    }
    return false;
}