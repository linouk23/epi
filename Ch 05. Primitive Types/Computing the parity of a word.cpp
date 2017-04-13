#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int parity1(unsigned long long num) {
        int result = 0;
        while(num > 0) {
            result ^= num & 1;
            num >>= 1;
        }
        return result;
    }
    
    int parity2(unsigned long long num) {
        int result = 0;
        while(num > 0) {
            num &= (num - 1);
            result ^= 1;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.parity1(1LL) == 1);
    assert(solution.parity2(1LL) == 1);
    assert(solution.parity1(7LL) == 1);
    assert(solution.parity2(7LL) == 1);
    assert(solution.parity1(3LL) == 0);
    assert(solution.parity2(3LL) == 0);
    
    return 0;
}
