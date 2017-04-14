#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> even_odd(vector<int>& nums) {
        int L = 0;
        int R = (int)nums.size() - 1;
        
        while (L <= R) {
            if (nums[L] % 2 == 0) {
                ++L;
            } else {
                swap(nums[L], nums[R--]);
            }
        }
        
        return nums;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    vector<int> input =  {3, 4, 6, 7, 1, 8, 8};
    vector<int> answer = {8, 4, 6, 8, 1, 7, 3};
    assert(solution.even_odd(input) == answer);
    
    return 0;
}
