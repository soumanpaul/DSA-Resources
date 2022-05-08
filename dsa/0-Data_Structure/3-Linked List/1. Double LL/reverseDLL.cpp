#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

Node *reverseDLLIterative(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL, *curr = head;
    while (curr != NULL) {
    }
}

Node *reverseDLL(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest_head = reverseDLL(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}