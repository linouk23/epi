#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ((int)nums.size() == 0) {
            return 0;
        }

        int index_to_write = 1;
        int n = (int)nums.size();
        for (int index = 1; index < n; ++index) {
            if (nums[index] != nums[index_to_write - 1]) {
                nums[index_to_write++] = nums[index];
            }
        }
        return index_to_write;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 1, 2};
    vector<int> expected_ans = {1, 2};
    assert(solution.removeDuplicates(input) == 2);

    input = {};
    assert(solution.removeDuplicates(input) == 0);

    input = {1, 1, 2, 2};
    assert(solution.removeDuplicates(input) == 2);

    input = {1};
    assert(solution.removeDuplicates(input) == 1);

    input = {1, 1, 1, 1, 1};
    assert(solution.removeDuplicates(input) == 1);

    return 0;
}
