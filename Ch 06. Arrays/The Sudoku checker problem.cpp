#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > row(9, vector<bool> (9, false)), col, box;
        box = col = row;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if (row[i][num] || col[j][num] || box[k][num]) return false;
                    row[i][num] = col[j][num] = box[k][num] = true;
                }
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
