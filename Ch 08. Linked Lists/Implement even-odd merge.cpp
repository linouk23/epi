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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy_even = new ListNode(0);
        ListNode* dummy_odd  = new ListNode(0);
        ListNode* linker = dummy_even;
        ListNode* answer = dummy_odd;
        int index = 1;
        while (head != nullptr) {
            if (index++ % 2) {
                dummy_odd = dummy_odd->next = head;
            } else {
                dummy_even = dummy_even->next = head;
            }
            head = head->next;
        }
        dummy_even->next = nullptr;
        dummy_odd->next = linker->next;
        return answer->next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
