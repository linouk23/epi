#include "bits/stdc++.h"

using namespace std;

struct Partition_result {
    vector<int> low, high;
    int pivot;
};

class Solution {
public:
    int get_pivot(vector<int>& nums) {
        int n = (int)nums.size() - 1;
        vector<int> pivots = {nums[0], nums[n / 2], nums[n]};
        sort(pivots.begin(), pivots.end());
        return pivots[1];
    }
    
    Partition_result partition(vector<int>& nums) {
        int pivot = get_pivot(nums);
        vector<int> low, high;
        for (int& num : nums) {
            if (num < pivot) {
                low.emplace_back(num);
            } else if (num > pivot) {
                high.emplace_back(num);
            }
        }
        return {low, high, pivot};
    }
    
    int quickSelect(vector<int>& nums, int k) {
        auto result = partition(nums);
        int n = (int)nums.size();
        int low_size = (int)result.low.size();
        int high_size = (int)result.high.size();
        if (k <= low_size) {
            return quickSelect(result.low, k);
        } else if (k > n - high_size) {
            return quickSelect(result.high,
                               k - (n - high_size));
        } else {
            return result.pivot;
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k = (int)nums.size() - k + 1;
        return quickSelect(nums, k);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
