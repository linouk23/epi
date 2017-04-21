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
    ListNode* CyclicallyRightShiftList(ListNode* head, int k) {
        if (head == nullptr) { return head; }
        
        auto tail = head;
        int len = 1;
        while (tail->next) {
            ++len;
            tail = tail->next;
        }
        k %= len;
        if (k == 0) { return head; }
        
        // Makes a cycle by connecting the tail to the head.
        tail->next = head;
        int steps_to_new_head = len - k;
        auto new_tail = tail;
        while (steps_to_new_head--) {
            new_tail = new_tail->next;
        }
        auto new_head = new_tail->next;
        new_tail->next = nullptr;
        return new_head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
