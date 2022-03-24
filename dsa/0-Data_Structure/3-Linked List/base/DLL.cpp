#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}


void printLinkList(struct Node* node) {
    struct Node* last;

    while(node != NULL){
        cout << node->data << " ";
        last = node;
        node = node->next;
    }
    while (last != NULL) { 
        cout<<last->data<<" "; 
        last = last->prev; 
    } 
}

void append(struct Node** head_ref, int new_data){
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = NULL;

    struct Node* last = *head_ref;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last=last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    return;
}

Node *insertBegin(Node *head,int data){
    Node *temp=new Node(data);
    temp->next=head;
    if(head!=NULL)head->prev=temp;
    return temp;
}


Node *insertEnd(Node *head,int data){
    Node* new_node = new Node(data);
    if(head == NULL) return new_node;
    
    Node* temp = head;
    while(temp->next !== NULL){
        temp = temp->next;
    } 
    temp->next = new_node;
    new_node->prev = temp;
    return head
}   
// Node* reverseList(Node *head){
   
   
//     return head;
// } 

Node *recRevL(Node *head){
    if(head==NULL||head->next==NULL)return head;
    Node *rest_head=recRevL(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

Node *delHead(Node *head){
    if(head == NULL) return;
    if(head->next == NULL){
        delete(head);
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete(temp);
    return head;
}
Node *delLast(Node *head){ 
    if(head==NULL) return;
    if(head->next == NULL){
        delete(head);
        return NULL;
    }
    Node* temp = head;
    while(temp->next !== NULL){
        temp=temp->next;
    }
    temp->prev->next = NULL;
    delete(temp);
    return head;
}

int main() {
    struct Node* head = NULL;

    append(&head, 6);

    append(&head, 7);

    printLinkList(head);
    return 0;
}