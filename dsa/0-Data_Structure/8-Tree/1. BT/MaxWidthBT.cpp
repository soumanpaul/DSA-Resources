// Maximum Width of Binary tree is the maximum number of nodes present in a level of the Tree.
#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k) {
        key = k;
        left=right=NULL;
    }
}

int maxWidth(Node *root) {
    if(root==NULL) return 0;
    queue<Node *>q;
    q.push(root);
    int res = 0;
    while(q.empty()==false){
        int count=q.size();
        res=max(res,count);
        for(int i =0; i <count; i++){
            Node *curr=q.fornt();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);    
        }
    }
    return res;
}