#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int row = 0; row < (int)matrix.size(); ++row) {
            for (int column = row + 1; column < (int)matrix[row].size(); ++column) {
                swap(matrix[row][column], matrix[column][row]);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
