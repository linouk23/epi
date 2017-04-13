#include "bits/stdc++.h"

using namespace std;

// 0 means equal, -1 means smaller, and 1 means larger.
int Compare(double a, double b) {
    // Uses normalization for precision problem.
    double diff = (a - b) / b;
    return diff < -1.0e-9 ? -1 : diff > 1.0e-9;
}

class Solution {
public:
    double power(double x, int n) {
        double result = 1.0;
        long long power = 1LL * n;
        if (power < 0) {
            power = -power; x = 1 / x;
        }
        
        while(power > 0) {
            if (power & 1) {
                result *= x;
            }
            power >>= 1, x *= x;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(!Compare(solution.power(2, 10), pow(2, 10)));
    
    return 0;
}
