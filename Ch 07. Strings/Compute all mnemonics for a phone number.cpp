#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<string> result, numbers = {
        "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
public:
    void helper(int index, string cur_answer, string digits) {
        if (index == digits.length()) {
            result.emplace_back(cur_answer);
            cout << cur_answer << endl;
            return;
        }
        for (char digit : numbers[digits[index] - '0']) {
            cur_answer.push_back(digit);
            helper(index + 1, cur_answer, digits);
            cur_answer.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) { return result; }
        helper(0, "", digits);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
