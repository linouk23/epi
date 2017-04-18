#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int NonuniformRandomNumberGeneration(const vector<int>& values,
                                         const vector<double>& probabilities) {
        vector<double> prefix_sums_of_probabilities;
        prefix_sums_of_probabilities.emplace_back(0.0);
        // Creating the endpoints for the intervals corresponding to the
        // probabilities.
        partial_sum(probabilities.cbegin(), probabilities.cend(),
                    back_inserter(prefix_sums_of_probabilities));
        
        default_random_engine generator;
        uniform_real_distribution<double> distribution(0.0, 1.0);
        double rand_num = distribution(generator);
        int id = (int)distance(prefix_sums_of_probabilities.cbegin(),
                               upper_bound(prefix_sums_of_probabilities.cbegin(),
                                           prefix_sums_of_probabilities.cend(), rand_num)) - 1;
        return values[id];
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
