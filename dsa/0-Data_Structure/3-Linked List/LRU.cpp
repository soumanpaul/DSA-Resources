#include<bits/stdc++.h>
using naamespace std;

class Node {
    public: 
    int key;
    int value;
    Node *pre;
    Node *next;


    Node(int k, int v){
        key = k;
        value = v;
        pre=NULL; next=NULL;
    }
};

class LRUCache {
    public:
        unordered_map<int, Node*> map;
        int capacity, count;
        Node *head, *tail;

        LRUCache(int c){
            capacity = c;
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            head->pre = head;
            tail->next = head;
            tail->pre = NULL;
            coount = 0;
        }

        void deleteNode(Node *node){
            node->pre->next = node->next;
            node->next-pre = node->pre;           
        }
        void addToHead(Node *node){
            node->next = head->next;
            node->next->pre = node;
            node->pre = head;
            head->next = node;
        }
        int get(int key){
            if(map[key] != NULL) {

            }
            return -1;
        }
        void set(int key ,int value){

        }
}


int main() {

    LRUCache cache(2);

    // store key 1 with value 10 in the
    cache.set(1,10);
    cache.set(2,20);

    cout << cache.get(1);

    cache.set(3,30);

    cache.get(2);

    cache.set(4,40);
    cache.get(1);
    cache.get(3);
    cache.get(4);

    return 0;
}