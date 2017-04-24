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
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return pre_order(root, 0, sum);
    }
    
    bool pre_order(TreeNode* node, int cur_sum, int target_sum) {
        if (node == nullptr) { return false; }
        cur_sum += node->val;
        
        if (is_leaf(node) && cur_sum == target_sum) {
            return true;
        }
        return pre_order(node->left, cur_sum, target_sum) ||
               pre_order(node->right, cur_sum, target_sum);
    }
    
    bool is_leaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
