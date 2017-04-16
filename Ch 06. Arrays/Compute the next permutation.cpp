#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        // {6, 2, 1, 5, 4, 3, 0} -> {0, 3, 4, 5, 1, 2, 6} -> 1
        auto break_point = is_sorted_until(nums.rbegin(), nums.rend());
        
        bool has_next_one = !(break_point == nums.rend());
        if (!has_next_one) {
            reverse(nums.begin(), nums.end());
            return nums;
        }
        
        // {0, 3, 4, 5}, x > 1 -> 3
        auto least_upper_bound = upper_bound(nums.rbegin(), break_point, *break_point);
        
        // {6, 2, 1, 5, 4, 3, 0} -> {6, 2, 3, 5, 4, 1, 0}
        iter_swap(break_point, least_upper_bound);
        
        // Since the suffix is sorted, reverse == sort:
        // {6, 2, 3, 5, 4, 1, 0} -> {6, 2, 3, 0, 1, 4, 5}
        reverse(nums.rbegin(), break_point);
        return nums;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    vector<int> input = {1, 2, 3};
    vector<int> answer = {1, 3, 2};
    assert(solution.nextPermutation(input) == answer);
    
    
    input = {3, 2, 1};
    answer = {1, 2, 3};
    assert(solution.nextPermutation(input) == answer);
    
    input = {1, 1, 5};
    answer = {1, 5, 1};
    assert(solution.nextPermutation(input) == answer);
    return 0;
}
