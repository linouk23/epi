#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    uint32_t divide(uint32_t x, uint32_t y) {
        uint32_t result = 0;
        int power = 32;
        unsigned long long y_power = static_cast<unsigned long long>(y) << power;
        
//        Find the largest k : 2^k y <= x.
        while (x >= y) {
            while (y_power > x) {
                y_power >>= 1;
                --power;
            }
            
            result += 1 << power;
            x -= y_power;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.divide(30, 6) == 5);
    assert(solution.divide(1, 1) == 1);
    assert(solution.divide(64, 2) == 32);
    assert(solution.divide(64, 3) == 21);
    assert(solution.divide(64, 4) == 16);
    assert(solution.divide(64, 5) == 12);
    assert(solution.divide(65, 2) == 32);
    
    return 0;
}
