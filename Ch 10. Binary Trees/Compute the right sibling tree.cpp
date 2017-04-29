#include "bits/stdc++.h"

using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        auto left_start = root;
        while (left_start && left_start->left) {
            helper(left_start);
            left_start = left_start->left;
        }
    }
    
    void helper(TreeLinkNode* start_node) {
        auto cur = start_node;
        while (cur) {
            cur->left->next = cur->right;
            if (cur->next) {
                cur->right->next = cur->next->left;
            }
            cur = cur->next;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
