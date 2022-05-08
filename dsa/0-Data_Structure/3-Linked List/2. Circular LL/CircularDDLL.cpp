#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
    Node(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

Node *insertAtHead(Node *head, int x) {
    Node *temp = new Node(x);
    if (head == NULL) {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->prev = head->prev;
    head->prev->next = temp;
    temp->next = head;
    return temp;
}

Node *addEnd(struct Node *last, int data) {
    if (last == NULL) {
        struct Node *temp = new Node(data);
        last = temp;
        last->next = last;
        return last;
    }
    struct Node *temp = new Node(data);
    temp->next = last->next;
    last = temp;
    last->next = last;
    return last;
}

// Node *sorted
void printlist(Node *head) {
    if (head == NULL)
        return;
    struct Node *temp = head->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head->next);
}

int main() {
    struct Node *last = NULL;

    last = insertAtHead(last, 6);
    last = insertAtHead(last, 4);
    last = insertAtHead(last, 2);
    last = insertAtHead(last, 8);
    last = insertAtHead(last, 12);
    last = insertAtHead(last, 10);
    printlist(last);

    return 0;
}
