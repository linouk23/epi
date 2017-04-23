#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<vector<int> > answer;
    unordered_map<TreeNode*, int> dist;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) { return answer; }
        
        queue<TreeNode*> q;
        q.push(root);
        dist[root] = 0;
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            
            if ((int)answer.size() <= dist[node]) {
                answer.push_back({});
            }
            answer[dist[node]].emplace_back(node->val);
            
            if (node->left != nullptr) {
                dist[node->left] = dist[node] + 1;
                q.push(node->left);
            }
            if (node->right != nullptr) {
                dist[node->right] = dist[node] + 1;
                q.push(node->right);
            }
        }
        
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
