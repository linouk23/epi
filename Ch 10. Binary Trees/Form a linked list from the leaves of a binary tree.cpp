#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    vector<int> result;
public:
    void preorder(TreeNode* node) {
        if (node == nullptr) { return; }
        if (is_leaf(node)) {
            result.emplace_back(node->val);
            return;
        }
        preorder(node->left);
        preorder(node->right);
    }
    
    bool is_leaf(TreeNode* node) {
        return (!node->left && !node->right);
    }
    
    vector<int> collect_leaves(TreeNode* root) {
        preorder(root);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
