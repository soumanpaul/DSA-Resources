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
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> answer;
        stack<TreeNode *> s;
        if (root) {
            s.push(root);
        }
        TreeNode *cur;
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            answer.push_back(cur->val); // visit the root
            if (cur->right) {
                s.push(cur->right); // push right child to stack if it is not null
            }
            if (cur->left) {
                s.push(cur->left); // push left child to stack if it is not null
            }
        }
        return answer;
    }
};