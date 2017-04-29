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
    int index;
    vector<int> preorder_;
public:
    TreeNode* ReconstructPreorder(vector<int>& preorder) {
        preorder_ = preorder;
        index = 0;
        return ReconstructPreorderHelper();
    }
    
    TreeNode* ReconstructPreorderHelper() {
        int node_value = preorder_[index];
        ++index;
        // -1 means "null"
        if (node_value == -1) {
            return nullptr;
        }
        
        auto left_subtree = ReconstructPreorderHelper();
        auto right_subtree = ReconstructPreorderHelper();
        
        TreeNode* node = new TreeNode(node_value);
        node->left = left_subtree;
        node->right = right_subtree;
        return node;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
