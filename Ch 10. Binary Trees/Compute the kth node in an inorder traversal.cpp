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
    int k_;
public:
    int inorder(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> st;
        
        while(!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top(); st.pop();
                --k_;
                if (k_ == 0) {
                    return cur->val;
                }
                cur = cur->right;
            }
        }
        
        return -1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        return inorder(root);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
