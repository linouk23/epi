#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void get_coef(int num_of_rows) {
        vector<vector<long long>> arr;
        for (int row = 0; row < num_of_rows; ++row) {
            vector<long long> new_row(row + 1);
            new_row[0] = 1;
            for (int column = 1; column < row; ++column) {
                new_row[column] = arr[row - 1][column] + arr[row - 1][column - 1];
            }
            new_row[row] = 1;
            arr.emplace_back(new_row);
        }
        for (const auto & row : arr) {
            for (const auto & el : row) {
                cout << el << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    Solution solution;
    solution.get_coef(n);

    return 0;
}
