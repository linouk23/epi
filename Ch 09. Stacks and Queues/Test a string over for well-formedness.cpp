#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string open_parentheses = "{[(";
        unordered_map<char, char> get_open_parenthesis_for {
            {'}', '{'},
            {']', '['},
            {')', '('},
        };

        stack<char> st;
        for (char ch : s) {
            if (open_parentheses.find(ch) != string::npos) {
                st.push(ch);
            } else {
                if (!st.empty() && st.top() == get_open_parenthesis_for[ch]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isValid("()") == true);
    assert(solution.isValid("()[]{}") == true);
    assert(solution.isValid("()[)]{}") == false);
    assert(solution.isValid("([)]") == false);

    return 0;
}
