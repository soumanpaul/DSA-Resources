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
    void preorderTraversal(TreeNode *root, vector<int> &answer) {
        if (!root) {
            return;
        }
        answer.push_back(root->val);            // visit the root
        preorderTraversal(root->left, answer);  // traverse left subtree
        preorderTraversal(root->right, answer); // traverse right subtree
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> answer;
        preorderTraversal(root, answer);
        return answer;
    }
};