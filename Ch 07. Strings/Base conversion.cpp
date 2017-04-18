#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        bool is_negative = (num < 0);
        num = abs(num);
        string result;
        
        while(num > 0) {
            result += to_string(num % 7);
            num /= 7;
        }

        if (is_negative) {
            result += '-';
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.convertToBase7(100) == "202");
    assert(solution.convertToBase7(-7) == "-10");
    assert(solution.convertToBase7(0) == "0");

    return 0;
}