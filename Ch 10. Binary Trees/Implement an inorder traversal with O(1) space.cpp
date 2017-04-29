#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class Solution {
public:
    vector<int> InorderTraversal(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        vector<int> result;
        
        while (cur != nullptr) {
            TreeNode* next;
            if (cur->parent == prev) {
                // We came down to cur from prev.
                if (cur->left != nullptr) {  // Keep going left.
                    next = cur->left;
                } else {
                    result.emplace_back(cur->val);
                    // Done with left, so go right if right is not empty.
                    // Otherwise, go up.
                    next = (cur->right != nullptr) ? cur->right : cur->parent;
                }
            } else if (cur->left == prev) {
                // We came up to cur from its left child.
                result.emplace_back(cur->val);
                // Done with left, so go right if right is not empty. Otherwise, go up.
                next = (cur->right != nullptr) ? cur->right : cur->parent;
            } else {  // Done with both children, so move up.
                next = cur->parent;
            }
            
            prev = cur;
            cur = next;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
