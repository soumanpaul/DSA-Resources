#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
}

struct Node *addEnd(struct Node *last, int data){
    struct Node *temp = new Node(data);
    if(last == NULL){
        temp-> data = data;
        return temp;
    } 
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}
Node *delHead(Node *head){
    if(head==NULL)return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}

void travers(struct Node *last){
    struct Node *p;
    if(last == NULL) return;
    p = last -> next;
    while(p != last->next){
        p = p->next;
    }
}

Node* insertBenin(Node* head, int x){
    Node* temp = new Node(x);
    if(head==NULL){
        temp = temp->next;
        return temp;
    }
    else{
         temp->next=head->next;
         head->next = temp;
         int t = head->data;
         head->data = temp->data;
         temp->data = t;
         return head;
        }
}

void deleteKth(Node* head, int kth){
    Node* temp = head;
    int count =0;
    if(head==NULL) return NULL;
    if(k==1){
        delete head;
        return NULL
    } 
    while(temp != NULL && count < kth){
        count++;
        temp = temp->next;
    }
    temp->next = temp->next->next;
   delete temp;
   return head;
}

int main(){
    struct Node *last = NULL;
    last = addEnd(last,6);

    travers(last);
    return 0;
}