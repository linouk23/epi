#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void SetJumpOrder_iter(PostingListNode* L) {
        stack<PostingListNode*> s;
        int order = 0;
        s.emplace(L);
        while (!s.empty()) {
            auto curr = s.top();
            s.pop();
            if (curr && curr->order == -1) {
                curr->order = order++;
                s.emplace(curr->next);
                s.emplace(curr->jump);
            }
        }
    }
    
    void SetJumpOrder(PostingListNode* L) {
        SetJumpOrderHelper(L, new int(0));
    }
    
    void SetJumpOrderHelper(PostingListNode* L, int* order) {
        if (L && L->order == -1) {
            L->order = (*order)++;
            SetJumpOrderHelper(L->jump, order);
            SetJumpOrderHelper(L->next, order);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
