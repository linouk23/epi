#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (char c : s)
            b.flip(c);
        return b.count() < 2;
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}
