#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void SortApproximatelySortedData(int k) {
        vector<int> result = {};
        priority_queue<int, vector<int>, greater<>> min_heap;
        int x;
        for (int i = 0; i < k; ++i) {
            min_heap.push(getNextNum());
        }
        
        while (hasNextNum()) {
            min_heap.push(getNextNum());
            result.push_back(min_heap.top());
            min_heap.pop();
        }
        
        while (!min_heap.empty()) {
            result.emplace_back(min_heap.top());
            min_heap.pop();
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
