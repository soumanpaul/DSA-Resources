#include<bits/stdc++.cpp>
using namespace std;

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k) {
        key = k;
        left = right = NULL;
    }
}

void printList(Node *head){
    Node *curr = head;
}


Node *BTToDLL(Node *root){
    if(root==NULL) return root;
    struct Node *prev = NULL;
    Node *head = BTToDLL(root->left);
    if(prev==NULL) {head=root;}
    else {
        root->left = prev;
        prev->right = root;
    }
    prev=root;
    BTToDLL(root->right);
    return head;
}