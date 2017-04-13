#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool is_negative = (x < 0);
        if (is_negative) {
            x = abs(x);
        }
        
        int reversed_num = 0;
        while(x) {
            if (reversed_num > INT_MAX / 10) {
                return 0;
            }
            
            reversed_num = 10 * reversed_num;
            if (reversed_num > INT_MAX - x % 10) {
                return 0;
            }
            
            reversed_num += x % 10;
            x /= 10;
        }
        
        return (is_negative) ? -reversed_num : reversed_num;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
