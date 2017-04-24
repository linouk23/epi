#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Status {
    int num_of_found_target_nodes;
    TreeNode* answer;
};

class Solution {
public:
    Status LCA_helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return {0, nullptr};
        }
        auto left_result = LCA_helper(root->left, p, q);
        if (left_result.num_of_found_target_nodes == 2) {
            return left_result;
        }
        auto right_result = LCA_helper(root->right, p, q);
        if (right_result.num_of_found_target_nodes == 2) {
            return right_result;
        }
        
        int num_of_nodes = left_result.num_of_found_target_nodes +
                           right_result.num_of_found_target_nodes +
                           (root == p) + (root == q);
        if (num_of_nodes == 2) {
            return {2, root};
        }
        return {num_of_nodes, nullptr};
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA_helper(root, p, q).answer;
    }
};
int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
