#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    uint32_t mult(uint32_t x, uint32_t y) {
        uint32_t result = 0;
        while(x > 0) {
            if (x & 1) {
                result = add(result, y);
            }
            x >>= 1;
            y <<= 1;
        }
        return result;
    }
    
    uint32_t add(uint32_t a, uint32_t b) {
        uint32_t sum = 0, carryin = 0, k = 1, temp_a = a, temp_b = b;
        while(temp_a || temp_b) {
            unsigned ak = a & k, bk = b & k;
            unsigned carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
            sum |= (ak ^ bk ^ carryin);
            carryin = carryout << 1, k <<= 1, temp_a >>= 1, temp_b >>= 1;
        }
        return sum | carryin;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.mult(5, 6) == 30);
    assert(solution.mult(1, 0) == 0);
    
    return 0;
}
