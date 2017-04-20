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
    ListNode* next(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        return head->next;
    }

    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast && fast != nullptr);

        return fast != nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.hasCycle(nullptr) == false);

    return 0;
}
