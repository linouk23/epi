#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)matrix.size();
        if (n == 0) { return false; };
        int m = (int)matrix[0].size();
        int row = n - 1, column = 0;
        auto is_valid_pair = [&n, &m](int row, int column) -> bool {
            return row >= 0 && column >= 0 &&
                   row < n && column < m;
        };
        while (is_valid_pair(row, column)) {
            if (matrix[row][column] > target) {
                --row;
            } else if (matrix[row][column] < target) {
                ++column;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
