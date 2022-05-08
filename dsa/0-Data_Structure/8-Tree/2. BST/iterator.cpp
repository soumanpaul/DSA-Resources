class BSTIterator {
    int n;
    int pointer;
    vector<int> nodes;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
        n = nodes.size();
        pointer = -1;
    }
    
    int next() {
        ++pointer;
        return  nodes[pointer];
    }
    
    bool hasNext() {
        return pointer < n-1;
    }
    
    bool hasPrev() {
        return pointer > 0;
    }
    
    int prev() {
        --pointer;
        return nodes[pointer];
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */