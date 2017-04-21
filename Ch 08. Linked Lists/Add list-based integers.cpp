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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        auto cur = l1;
        while(cur) {
            st1.push(cur->val);
            cur = cur->next;
        }
        cur = l2;
        while(cur) {
            st2.push(cur->val);
            cur = cur->next;
        }
        auto tail = new ListNode(0);
        auto dummy = tail;
        int carry_left = 0;
        while(!st1.empty() || !st2.empty() || carry_left) {
            int val1 = 0, val2 = 0;
            if (!st1.empty()) {
                val1 = st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                val2 = st2.top();
                st2.pop();
            }
            auto sum = val1 + val2 + carry_left;
            carry_left = sum / 10;
            auto node = new ListNode(sum % 10);
            tail = tail->next = node;
        }
        ListNode* prev = nullptr;
        cur = dummy->next;
        while(cur) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
