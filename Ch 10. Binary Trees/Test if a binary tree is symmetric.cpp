#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q) {
        if (p && q) {
            return p->val == q->val && helper(p->right, q->left) && helper(p->left, q->right);
        } else if (!p && !q) {
            return true;
        } else {
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (root) {
            return helper(root->left, root->right);
        } else {
            return true;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}
