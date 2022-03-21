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
bool isSymmetric(TreeNode root) {
    queue<TreeNode> q;
    q.push(root);
    q.push(root);
    while (!q.empty()) {
        TreeNode *t1 = q.pop();
        TreeNode *t2 = q.pop();
        if (t1 == NULL && t2 == NULL)
            continue;
        if (t1 == NULL || t2 == NULL)
            return false;
        if (t1.val != t2.val)
            return false;
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
    }
    return true;
}

class Solution {
public:
    bool check(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL & T2 == NULL)
            return true;
        if (T1 == NULL || T2 == NULL)
            return false;
        return (T1->val == T2->val) && check(T1->left, T2->right) && check(T1->right, T2->left);
    }

    bool isSymmetric(TreeNode *root) {
        return check(root, root);
    }
};