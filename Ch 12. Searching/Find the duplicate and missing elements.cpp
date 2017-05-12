#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct DuplicateAndMissing {
        int duplicate, missing;
    };
    
    DuplicateAndMissing FindDuplicateMissing(vector<int>& arr) {
        int miss_XOR_dup = 0;
        for (int i = 0; i < arr.size(); ++i) {
            // Eliminate each other
            miss_XOR_dup ^= i ^ arr[i];
        }
        
        int differ_bit = miss_XOR_dup & (~(miss_XOR_dup - 1));
        int miss_or_dup = 0;
        for (int i = 0; i < (int)arr.size(); ++i) {
            if (i & differ_bit) {
                miss_or_dup ^= i;
            }
            if (arr[i] & differ_bit) {
                miss_or_dup ^= arr[i];
            }
        }
        
        for (int a : arr) {
            if (a == miss_or_dup) {
                return {miss_or_dup, miss_or_dup ^ miss_XOR_dup};
            }
        }
        
        return {miss_or_dup ^ miss_XOR_dup, miss_or_dup};
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
