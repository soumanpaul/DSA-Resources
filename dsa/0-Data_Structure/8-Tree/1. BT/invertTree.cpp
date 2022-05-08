#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL)
            return NULL;
        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        root->left = right;
        root->right = left;
        return root;
    }
    TreeNode *invertTreeIterative(TreeNode *root) {
        if (root == NULL)
            return NULL;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode *current = queue.front();
            TreeNode *temp = current->left;
            current->left = current->right;
            current->right = temp;
            if (current->left != NULL)
                queue.push(current->left);
            if (current->right != NULL)
                queue.push(current->right);
        }
        return root;
    }
};