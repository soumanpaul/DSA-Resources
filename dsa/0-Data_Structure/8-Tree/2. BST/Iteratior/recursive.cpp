/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
    stack<TreeNode*> path;
    vector<int> vals;
    int pos = -1;
    public:
   
        void traverseLeft(TreeNode *root) {
            for (; root != nullptr; root = root->left)
	            path.push(root);
        }
        
        BSTIterator(TreeNode* root) { traverseLeft(root); }
        
        bool hasNext() { return pos + 1 < vals.size() || !path.empty(); }
        
        int next() {
            if (++pos == vals.size()) {
                auto cur = path.top();
                path.pop();
                traverseLeft(cur->right);
                vals.push_back(cur->val);
        }
    return vals[pos];
}
bool hasPrev() { return pos > 0; }
int prev() { return vals[--pos]; }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */