#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> multiply(vector<int> num1, vector<int> num2) {
        const int sign = num1.front() < 0 ^ num2.front() < 0 ? -1 : 1;
        num1.front() = abs(num1.front());
        num2.front() = abs(num2.front());
        
        int n = (int)num1.size(); int m = (int)num2.size();
        vector<int> result(n + m, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                result[i + j + 1] += num1[i] * num2[j];
                result[i + j] += result[i + j + 1] / 10;
                result[i + j + 1] %= 10;
            }
        }
        
        result = {
            find_if_not(begin(result), end(result), [](int a) { return a == 0; }),
            end(result)
        };
        
        if (result.empty()) {
            return {0};
        }
        result.front() *= sign;
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    vector<int> answer = {-1, 3, 9, 2, 6, 2, 3, 6, 1};
    assert(solution.multiply({1, 1, 2, 3, 9, 9,}, {-1, 2, 3, 9}) == answer);
    
    return 0;
}
