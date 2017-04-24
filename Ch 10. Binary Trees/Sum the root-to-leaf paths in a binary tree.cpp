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
    int total;
public:
    int sumNumbers(TreeNode* root) {
        total = 0;
        pre_order(root, 0);
        return total;
    }
    
    void pre_order(TreeNode* node, int cur_sum) {
        if (node == nullptr) { return; }
        cur_sum = 10 * cur_sum + node->val;
        if (is_leaf(node)) {
            total += cur_sum;
            return;
        }
        pre_order(node->left, cur_sum);
        pre_order(node->right, cur_sum);
    }
    
    bool is_leaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
