#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int uniform_random(int L, int R) {
        int num_of_outcomes = R - L + 1, result;
        do {
            result = 0;
            for (int index = 0; (1 << index) < num_of_outcomes; ++index) {
                result = ((result << 1) | (rand() % 2));
            }
        } while (result >= num_of_outcomes);
        return result + L;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
