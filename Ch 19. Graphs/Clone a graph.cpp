#include "bits/stdc++.h"

using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hashtable;
    unordered_set<UndirectedGraphNode*> visited;
public:
    void cloneNodeIf404(UndirectedGraphNode* node) {
        if (!hashtable.count(node)) {
            hashtable[node] = new UndirectedGraphNode(node->label);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) { return nullptr; }
        queue<UndirectedGraphNode*> q;
        q.push(node);
        visited.insert(node);
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            cloneNodeIf404(cur);
            for (auto neighbour : cur->neighbors) {
                cloneNodeIf404(neighbour);
                hashtable[cur]->neighbors.emplace_back(hashtable[neighbour]);
                if (visited.count(neighbour)) { continue; }
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }
        return hashtable[node];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
