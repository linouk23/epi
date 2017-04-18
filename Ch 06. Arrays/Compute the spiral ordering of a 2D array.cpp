#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        if (matrix.empty()) {
            return result;
        }
        
        int row_start = 0;
        int row_finish = (int)matrix.size() - 1;
        int col_start = 0;
        int col_finish = (int)matrix[0].size() - 1;
        
        while (row_start <= row_finish && col_start <= col_finish) {
            // Right
            for (int col = col_start; col <= col_finish; ++col) {
                result.emplace_back(matrix[row_start][col]);
            }
            ++row_start;
            
            // Down
            for (int row = row_start; row <= row_finish; ++row) {
                result.emplace_back(matrix[row][col_finish]);
            }
            --col_finish;
            
            if (row_start <= row_finish) {
                // Left
                for (int col = col_finish; col >= col_start; --col) {
                    result.emplace_back(matrix[row_finish][col]);
                }
            }
            --row_finish;
            
            if (col_start <= col_finish) {
                // Up
                for (int row = row_finish; row >= row_start; --row) {
                    result.emplace_back(matrix[row][col_start]);
                }
            }
            ++col_start;
        }
        
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
