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

class Solution {
private:
    stack<TreeNode *> stk, lower_limits, upper_limits;

public:
    void update(TreeNode *root, TreeNode *low, TreeNode *high) {
        stk.push(root);
        lower_limits.push(low);
        upper_limits.push(high);
    }
    bool isValidBST(TreeNode *root) {
        TreeNode *low = nullptr;
        TreeNode *high = nullptr;
        update(root, low, high);

        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            low = lower_limits.top();
            lower_limits.pop();
            high = upper_limits.top();
            upper_limits.pop();

            if (root == nullptr) {
                continue;
            }

            TreeNode *val_node = root;
            if (low != nullptr and val_node->val <= low->val) {
                return false;
            }
            if (high != nullptr and val_node->val >= high->val) {
                return false;
            }
            update(root->right, val_node, high);
            update(root->left, low, val_node);
        }
        return true;
    }
};

class SolutionInorderRecursive {
private:
    TreeNode *prev = nullptr;

public:
    bool isValidBST(TreeNode *root) {
        return inorder(root);
    }

    bool inorder(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        if (!inorder(root->left)) {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root;
        return inorder(root->right);
    }
};

class SolutionIterativeInorderTraversal {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;

        while (!stk.empty() or root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();

            // If next element in inorder traversal
            // is smaller than the previous one
            // that's not BST.
            if (prev != nullptr and root->val <= prev->val) {
                return false;
            }
            prev = root;
            root = root->right;
        }
        return true;
    }
};