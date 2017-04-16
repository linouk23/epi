#include "bits/stdc++.h"

using namespace std;

// The key to reducing space complexity to O(K) is using a hashtable
// to mimic 'Sample offline data'.
class Solution {
private:
    unordered_map<int, int> hashtable;
    vector<int> nums;
    default_random_engine generator;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    vector<int> pick(int k) {
        int n = (int)nums.size();
        for (int index = 0; index < k; ++index) {
            uniform_int_distribution<int> distribution(index, n - 1);
            int rand_num = distribution(generator);
            bool has_swapped_index = hashtable.count(index);
            bool has_swapped_rand = hashtable.count(rand_num);
            
            if (has_swapped_rand && has_swapped_index) {
                int temp = hashtable[rand_num];
                hashtable[rand_num] = hashtable[index];
                hashtable[index] = temp;
            } else if (!has_swapped_rand && has_swapped_index) {
                hashtable[rand_num] = hashtable[index];
                hashtable[index] = rand_num;
            } else if (has_swapped_rand && !has_swapped_index) {
                hashtable[index] = hashtable[rand_num];
                hashtable[rand_num] = index;
            } else {
                hashtable[index] = rand_num;
                hashtable[rand_num] = index;
            }
        }
        
        vector<int> result;
        for (int index = 0; index < k; ++index) {
            if (hashtable.count(index)) {
                result.emplace_back(hashtable[index]);
            } else {
                result.emplace_back(index);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
