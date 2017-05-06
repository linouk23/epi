#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int SearchFirstOfK(const vector<int>& A, int target) {
        int L = -1, R = (int)A.size();
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (A[M] >= target) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
