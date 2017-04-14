#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> sortColors(vector<int>& nums) {
        int L = 0, M = 0;
        int R = (int)nums.size() - 1;
        
        while (M <= R) {
            if (nums[M] == 0) { swap(nums[L++], nums[M++]); }
            else if (nums[M] == 2) { swap(nums[M], nums[R--]); }
            else { ++M; }
        }
        
        return nums;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    vector<int> input =  {1, 1, 2, 2, 0, 1, 0};
    vector<int> answer = {0, 0, 1, 1, 1, 2, 2};
    assert(solution.sortColors(input) == answer);
    
    return 0;
}
