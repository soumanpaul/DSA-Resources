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

struct Stack {
    Node *head;
    int size;
    Stack() {
        head = NULL;
        size = 0;
    }
    void push(int x) {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }
    int pop() {
        if (head == NULL)
            return INT_MAX;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete (temp);
        size--;
        return res;
    }
    int peek() {
        if (head == NULL)
            return INT_MAX;
        return head->data;
    }
    int sizeofArr() {
        return size;
    }
    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    Stack s;
    s.push(20);
    s.push(10);
    s.pop();
    s.sizeofArr();
    s.peek();
    s.isEmpty();

    return 0;
}
