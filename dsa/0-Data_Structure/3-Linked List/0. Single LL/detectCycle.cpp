#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next;
};

bool isLoop(Node *head) {
    unordered_set<Node *> s;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        if (s.find(curr) != s.end())
            return true;
        s.insert(curr);
    }
    return false;
}

bool isLoopUsingFloydCycle(Node *head) {
    Node *slow_p = head, *fast_p = head;

    while (fast_p != NULL && fast_p->next != NULL) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return true;
        }
    }
    return false;
}
