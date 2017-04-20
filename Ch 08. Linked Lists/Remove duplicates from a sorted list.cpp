#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* get_next_element(ListNode* node) {
        if (node == nullptr) { return nullptr; }
        int value = node->val;
        while (node != nullptr && node->val == value) {
            node = node->next;
        }
        return node;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* answer = head;
        while(head != nullptr) {
            head->next = get_next_element(head);
            head = head->next;
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
