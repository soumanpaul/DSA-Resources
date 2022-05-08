#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative
class Solution {
    TreeNode *searchBST(TreeNode *root, int target) {
        TreeNode* cur = root;
        while (cur != NULL && cur->val != target) {
            if (target < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return cur;
    }
    TreeNode* searchBSTIterative(TreeNode* root, int val) {
        while (root != null && root->val != val) {
            root = (root->val > val) ? root->left : root->right;
        }
        return root;
    }
};

class SolutionRecursive {
public:
    
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == NULL || root->val == val)
            return root;
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};