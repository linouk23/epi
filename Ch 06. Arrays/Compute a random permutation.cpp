#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> RandomSampling(int n, int k) {
        vector<int> indexes(n);
        iota(indexes.begin(), indexes.end(), 0);
        
        unsigned int seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator(seed);
        
        for (int index = 0; index < k; ++index) {
            uniform_int_distribution<int> distribution(index, n - 1);
            int chosen_index = distribution(generator);
            swap(indexes[chosen_index], indexes[index]);
        }
        
        vector<int> result(indexes.begin(), indexes.begin() + k);
        return result;
    }
    
    vector<int> RandomPermutation(vector<int> & num) {
        int n = (int)num.size();
        vector<int> indexes = RandomSampling(n, n);
        return indexes;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
