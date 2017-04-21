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
    ListNode* pivotList(ListNode* head, int target) {
        ListNode* dummy_less = new ListNode(0);
        ListNode* dummy_eq  = new ListNode(0);
        ListNode* dummy_greater  = new ListNode(0);
        ListNode* linker1 = dummy_eq;
        ListNode* linker2 = dummy_greater;
        ListNode* answer = dummy_less;
        while (head != nullptr) {
            if (head->val < target) {
                dummy_less = dummy_less->next = head;
            } else if (head->val == target) {
                dummy_eq = dummy_eq->next = head;
            } else {
                dummy_greater = dummy_greater->next = head;
            }
            head = head->next;
        }
        dummy_less->next = linker1->next;
        dummy_eq->next = linker2->next;
        return answer->next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
