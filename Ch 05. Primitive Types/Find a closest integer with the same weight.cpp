#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    uint32_t closest_int(uint32_t num) {
        const int num_of_bits = 32;
        
        for (int index = 0; index < num_of_bits; ++index) {
            if ((num & (1 << index)) != (num & (1 << (index + 1)))) {
                uint32_t mask = 0;
                mask |= (1 << index);
                mask |= (1 << (index + 1));
                num ^= mask;
                return num;
            }
        }
        throw invalid_argument("All bits are 0 or 1");
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.closest_int(5) == 6);
    
    return 0;
}
