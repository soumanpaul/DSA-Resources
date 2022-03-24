#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node* next;
    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void printlist(Node *head){
    if(head== NULL) return
    Node* temp = head;
    do{
        temp = temp->next;
    }while(temp!=head);
}

Node insertAtHead(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->prev = head->prev;
    head->prev->next = temp;
    temp->next = head;
    return temp;    
}

