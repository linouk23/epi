#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        
        int reversed_snd_half = 0;
        while(x > reversed_snd_half) {
            reversed_snd_half = 10 * reversed_snd_half + x % 10;
            x /= 10;
        }
        
        return (x == reversed_snd_half ||
                x == reversed_snd_half / 10);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.isPalindrome(1111) == true);
    assert(solution.isPalindrome(1121) == false);
    assert(solution.isPalindrome(11211) == true);
    assert(solution.isPalindrome(3) == true);
    
    return 0;
}
