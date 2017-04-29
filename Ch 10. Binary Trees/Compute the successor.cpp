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
    TreeNode* FindSuccessor(TreeNode* node) {
        TreeNode* cur = node;
        if (cur->right != nullptr) {
            // Successor is the leftmost element in node's right subtree.
            cur = cur->right;
            while (cur->left) {
                cur = cur->left;
            }
            return cur;
        }
        
        // Find the closest ancestor whose left subtree contains node.
        while (cur->parent != nullptr && cur->parent->right == cur) {
            cur = cur->parent;
        }
        // A return value of nullptr means node does not have successor, i.e., it is
        // the rightmost node in the tree.
        return cur->parent;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
