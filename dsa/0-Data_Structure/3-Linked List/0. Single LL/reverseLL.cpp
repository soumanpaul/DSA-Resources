#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *next;
};

Node *reverseIterative(Node *head) {
    Node *curr = head;
    Node *prev = NULL, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

Node *ReverseRecursive(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest_head = ReverseRecursive(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}
//   Tail recursive

Node *recRevL(Node *curr, Node *prev) {
    if (curr == NULL)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    return recRevL(next, curr);
}