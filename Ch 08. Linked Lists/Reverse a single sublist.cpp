#include "bits/stdc++.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n == m) { return head; }
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto cur = dummy;
        int len = 0;
        auto mth_minus_1 = cur;
        auto prev = cur;
        for (; len < m; ++len) {
            prev = cur;
            cur = cur->next;
        }
        mth_minus_1 = prev;
        auto mth = cur;
        prev = cur;
        cur = cur->next;
        auto next = cur->next;
        for (int i = 0; i < n - m; ++i) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        mth->next = cur;
        mth_minus_1->next = prev;
        return dummy->next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
