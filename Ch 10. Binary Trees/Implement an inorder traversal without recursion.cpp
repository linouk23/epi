// 94. Binary Tree Inorder Traversal - https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() || cur) {
            if (cur) {
                st.emplace(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                result.emplace_back(cur->val);
                st.pop();
                cur = cur->right;
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
