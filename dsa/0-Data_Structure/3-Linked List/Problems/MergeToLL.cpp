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

void printlist(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *mergeTwoLists(Node *l1, Node *l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->data < l2->data) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
Node *sortedMerge(Node *a, Node *b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *head = NULL, *tail = NULL;
    if (a->data <= b->data) {
        head = tail = a;
        a = a->next;
    } else {
        head = tail = b;
        b = b->next;
    }
    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            tail = a;
            a = a->next;
        } else {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if (a == NULL) {
        tail->next = b;
    } else {
        tail->next = a;
    }
    return head;
}

int main() {
    Node *a = new Node(10);
    a->next = new Node(20);
    a->next->next = new Node(30);
    Node *b = new Node(5);
    b->next = new Node(35);
    printlist(sortedMerge(a, b));
    return 0;
}
