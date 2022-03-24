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
    vector<vector<int>> levelOrder(TreeNode *root) {

        vector<vector<int>> nodes;
        queue<TreeNode *> qu;
        if (root != NULL)
            qu.push(root);
        while (!qu.empty()) {
            int nodeCount = qu.size();
            vector<int> v;
            while (nodeCount > 0) {
                TreeNode *temp = qu.front();
                qu.pop();
                if (temp->left != NULL)
                    qu.push(temp->left);
                if (temp->right != NULL)
                    qu.push(temp->right);
                v.push_back(temp->val);
                nodeCount--;
            }
            nodes.push_back(v);
        }
        return nodes;
    }
};