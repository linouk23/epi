#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long swap_bits(long long num, int i, int j) {
        if ((num & (1LL << i)) != (num & (1LL << j))) {
            num ^= (1LL << i) | (1LL << j);
        }
        return num;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.swap_bits(8LL, 0, 3) == 1LL);
    
    return 0;
}
