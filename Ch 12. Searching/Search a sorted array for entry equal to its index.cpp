#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int SearchEntryEqualToItsIndex(const vector<int>& A) {
        int L = -1, R = (int)A.size();
        while (R - L > 1) {
            int M = L + ((R - L) / 2);
            int difference = A[M] - M;
            if (difference >= 0) {
                R = M;
            } else {
                L = M;
            }
        }
        return (A[R] == R) ? R : -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
