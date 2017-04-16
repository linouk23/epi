#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
        
        for (long long num = 2; num * num <= (long long)n; ++num) {
            if (sieve[num]) {
                for (long long sq_num = num * num; sq_num <= (long long)n; sq_num += num) {
                    sieve[sq_num] = false;
                }
            }
        }
        
        int answer = 0;
        for (int num = 0; num < n; ++num) {
            if (sieve[num]) {
                ++answer;
            }
        }
        
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.countPrimes(2) == 0);
    assert(solution.countPrimes(255) == 54);
    
    return 0;
}