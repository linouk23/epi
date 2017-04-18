#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int answer = 0;
        for (char ch : s) {
            int num = ch - 'A' + 1;
            answer = 26 * answer + num;
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.titleToNumber("A") == 1);
    assert(solution.titleToNumber("Z") == 26);
    assert(solution.titleToNumber("AA") == 27);
    assert(solution.titleToNumber("AB") == 28);

    return 0;
}
