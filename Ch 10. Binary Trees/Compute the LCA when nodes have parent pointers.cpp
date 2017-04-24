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
    TreeNode* LCA(TreeNode* p, TreeNode* q) {
        int depth_p = GetDepth(p), depth_q = GetDepth(q);
        
        if (depth_p > depth_q) {
            swap(p, q);
        }
        
        int depth_diff = abs(depth_p - depth_q);
        while (depth_diff--) {
            p = p->parent;
        }
        
        while (p != q) {
            p = p->parent, q = q->parent;
        }
        return p;
    }
    
    int GetDepth(TreeNode* node) {
        TreeNode* cur = node;
        int depth = 0;
        while (cur->parent) {
            ++depth, cur = cur->parent;
        }
        return depth;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
