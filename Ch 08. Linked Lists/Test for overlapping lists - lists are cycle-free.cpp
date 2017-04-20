#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) { return nullptr; }
        int lengthA = 0, lengthB = 0;
        
        ListNode* curA = headA;
        ListNode* curB = headB;
        
        while(curA->next != nullptr) {
            curA = curA->next;
            ++lengthA;
        }
        
        while(curB->next != nullptr) {
            curB = curB->next;
            ++lengthB;
        }
        
        if (curA != curB) {
            return nullptr;
        }
        
        if (lengthA > lengthB) {
            while (lengthA > lengthB) {
                headA = headA->next;
                --lengthA;
            }
        } else if (lengthB > lengthA) {
            while (lengthB > lengthA) {
                headB = headB->next;
                --lengthB;
            }
        }
        
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
