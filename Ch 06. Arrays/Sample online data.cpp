#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<int> nums;
    default_random_engine generator;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    vector<int> pick(int k) {
        uniform_real_distribution<double> distribution(0.0, 1.0);
        uniform_int_distribution<int> replace_distribution(0, k - 1);
        double break_point, rand_num;
        vector<int> result(nums.begin(), nums.begin() + k);
        int n = (int)nums.size(), replace_index;
        for (int index = k; index < n; ++index) {
            break_point = 1.0 * k / ((double) n);
            rand_num = distribution(generator);
            if (rand_num <= break_point) {
                replace_index = replace_distribution(generator);
                result[replace_index] = nums[index];
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
