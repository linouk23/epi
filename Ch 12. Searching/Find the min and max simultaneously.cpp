#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct MinMax {
        int smallest, largest;
    };
    MinMax FindMinMax(const vector<int>& A) {
        if ((int)A.size() <= 1) {
            return {A.front(), A.front()};
        }
        
        pair<int, int> global_min_max = minmax(A[0], A[1]);
        for (int i = 2; i + 1 < A.size(); i += 2) {
            pair<int, int> local_min_max = minmax(A[i], A[i + 1]);
            global_min_max = {min(global_min_max.first, local_min_max.first),
                max(global_min_max.second, local_min_max.second)};
        }
        if ((int)A.size() % 2) {
            global_min_max = {min(global_min_max.first, A.back()),
                max(global_min_max.second, A.back())};
        }
        return {global_min_max.first, global_min_max.second};
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
