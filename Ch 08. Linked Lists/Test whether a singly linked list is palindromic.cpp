#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) { return true; }
        if (head->next == nullptr) { return true; }
        
        stack<int> st;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast != nullptr) {
            slow = slow->next;
        }
        
        while(!st.empty() && slow != nullptr) {
            if (slow->val != st.top()) {
                return false;
            }
            slow = slow->next;
            st.pop();
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
