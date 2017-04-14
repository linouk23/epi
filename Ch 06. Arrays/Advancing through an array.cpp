#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool can_reach_finish(const vector<int>& steps) {
        int furthest_index_so_far = 0, n = (int)steps.size() - 1;
        for (int index = 0; index <= furthest_index_so_far && furthest_index_so_far < n; ++index) {
            furthest_index_so_far = max(furthest_index_so_far, steps[index] + index);
        }
        return furthest_index_so_far >= n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
