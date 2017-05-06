#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long num = (long long)x;
        long long L = -1LL;
        long long R = num + 1;
        while (R - L > 1) {
            long long M = L + (R - L) / 2;
            if (M * M <= num) {
                L = M;
            } else {
                R = M;
            }
        }
        return L;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.mySqrt(17) == 4);
    assert(solution.mySqrt(16) == 4);
    assert(solution.mySqrt(1) == 1);

    return 0;
}
