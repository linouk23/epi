#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> KLargestInBinaryHeap(const vector<int>& A, int k) {
        if (k <= 0) {
            return {};
        }
        
        struct HeapEntry {
            int index, value;
        };
        
        priority_queue<HeapEntry, vector<HeapEntry>,
        function<bool(HeapEntry, HeapEntry)>>
        max_heap([](const HeapEntry& a, const HeapEntry& b) {
            return a.value < b.value;
        });
        
        max_heap.emplace(0, A[0]);
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            int cur_index = max_heap.top().index;
            result.emplace_back(max_heap.top().value);
            max_heap.pop();
            
            int left_child = 2 * cur_index + 1;
            if (left_child < A.size()) {
                max_heap.emplace(left_child, A[left_child]);
            }
            int right_child = 2 * cur_index + 2;
            if (right_child < A.size()) {
                max_heap.emplace(right_child, A[right_child]);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
