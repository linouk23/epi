#include "bits/stdc++.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>> min_heap;
        for (const auto & head : lists) {
            if (head == nullptr) { continue; }
            min_heap.emplace(head->val, head);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(!min_heap.empty()) {
            auto node = min_heap.top(); min_heap.pop();
            cur = cur->next = node.second;
            if (node.second->next) {
                min_heap.emplace(node.second->next->val, node.second->next);
            }
        }
        return dummy->next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
