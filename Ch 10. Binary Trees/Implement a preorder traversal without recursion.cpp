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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) { return result; }
        stack<TreeNode*> st;
        TreeNode* cur;
        st.emplace(root);
        while(!st.empty()) {
            cur = st.top(); st.pop();
            result.emplace_back(cur->val);
            if (cur->right) {
                st.emplace(cur->right);
            }
            if (cur->left) {
                st.emplace(cur->left);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
