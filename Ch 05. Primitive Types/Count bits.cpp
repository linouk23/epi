#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int count_bits(int n) {
        int result = 0;
        while (n) {
            n = n & (n - 1);
            ++result;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.count_bits(0) == 0);
    assert(solution.count_bits(8) == 1);
    assert(solution.count_bits(3) == 2);
    
    return 0;
}
