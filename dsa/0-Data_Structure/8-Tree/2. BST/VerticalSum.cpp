// Inorder
void vSumR(Node *root,int hd,map<int,int> &mp){
    if(root==NULL)return;
    vSumR(root->left,hd-1,mp);
    mp[hd]+=root->key;
    vSumR(root->right,hd+1,mp);
}    

void vSum(Node *root){
    map<int,int> mp;
    vSumR(root,0,mp);
    for(auto sum: mp)
        cout<<sum.second<<" ";
}
