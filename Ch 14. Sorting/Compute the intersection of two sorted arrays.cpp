#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> IntersectTwoSortedArrays(const vector<int>& arr1,
                                         const vector<int>& arr2) {
        vector<int> result;
        int L1 = 0, L2 = 0;
        while (L1 < arr1.size() && L2 < arr2.size()) {
            if (arr1[L1] == arr2[L2] && (L1 == 0 || arr1[L1] != arr1[L1 - 1])) {
                result.emplace_back(arr1[L1]);
                ++L1, ++L2;
            } else if (arr1[L1] < arr2[L2]) {
                ++L1;
            } else {  // arr1[L1] > arr2[L2].
                ++L2;
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
