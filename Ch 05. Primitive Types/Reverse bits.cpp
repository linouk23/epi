#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    unsigned int reverse_bits(unsigned int num) {
        const int num_of_bits = 32;
        unsigned int reverse_num = 0;
        
        for (int index = 0; index < num_of_bits; ++index) {
            if (num & (1 << index)) {
                reverse_num |= (1 << (num_of_bits - index - 1));
            }
        }
        
        return reverse_num;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.reverse_bits((unsigned int)43261596) == 964176192);
    
    return 0;
}
