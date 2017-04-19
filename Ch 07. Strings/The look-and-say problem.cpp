#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        int cur_index = 1;
        string last_result = "1";
        string cur_result;
        while(cur_index < n) {
            int num_of_conseq = 1;
            for (int index = 1; index < last_result.length(); ++index) {
                if (last_result[index] != last_result[index - 1]) {
                    cur_result += to_string(num_of_conseq);
                    cur_result += last_result[index - 1];
                    num_of_conseq = 1;
                } else {
                    ++num_of_conseq;
                }
            }
            cur_result += to_string(num_of_conseq);
            cur_result += last_result[last_result.length() - 1];
            last_result = cur_result;
            cur_result.clear();
            ++cur_index;
        }
        return last_result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.countAndSay(1) == "1");
    assert(solution.countAndSay(2) == "11");
    assert(solution.countAndSay(3) == "21");
    assert(solution.countAndSay(4) == "1211");
    assert(solution.countAndSay(5) == "111221");

    return 0;
}
