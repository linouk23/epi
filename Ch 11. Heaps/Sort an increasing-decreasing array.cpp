#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> SortKIncreasingDecreasingArray(const vector<int>& A) {
        vector<vector<int>> sorted_subarrays;
        typedef enum { INCREASING, DECREASING } SubarrayType;
        SubarrayType subarray_type = INCREASING;
        int start_idx = 0;
        for (int i = 1; i <= A.size(); ++i) {
            if (i == A.size() ||
                (A[i - 1] < A[i] && subarray_type == DECREASING) ||
                (A[i - 1] >= A[i] && subarray_type == INCREASING)) {
                if (subarray_type == INCREASING) {
                    sorted_subarrays.emplace_back(A.cbegin() + start_idx, A.cbegin() + i);
                } else {
                    sorted_subarrays.emplace_back(A.crbegin() + A.size() - i,
                                                  A.crbegin() + A.size() - start_idx);
                }
                start_idx = i;
                subarray_type = (subarray_type == INCREASING ? DECREASING : INCREASING);
            }
        }
        
        return MergeSortedArrays(sorted_subarrays);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
