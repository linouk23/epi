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
    unordered_map<int, int> hashmap;
    vector<int> preorder_, inorder_;
public:
    TreeNode* helper(int pre_start, int in_start, int in_finish) {
        if (in_finish < in_start) { return nullptr; }
        
        TreeNode* node = new TreeNode(preorder_[pre_start]);
        
        int pre_start_inorder = hashmap[preorder_[pre_start]];
        
        int left_subtree_size = pre_start_inorder - in_start;
        node->left = helper(pre_start + 1, in_start, pre_start_inorder - 1);
        node->right = helper(pre_start + left_subtree_size + 1, pre_start_inorder + 1, in_finish);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = (int)preorder.size();
        if (n == 0) {
            return nullptr;
        }
        
        preorder_ = preorder;
        inorder_ = inorder;
        
        for (int index = 0; index < n; ++index) {
            int key = inorder[index];
            hashmap[key] = index;
        }
        int root_in_pre = 0;
        return helper(root_in_pre, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
