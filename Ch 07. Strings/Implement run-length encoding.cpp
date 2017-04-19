#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string Decoding(const string &s) {
        int count = 0;
        string result;
        for (const char &c : s) {
            if (isdigit(c)) {
                count = count * 10 + c - '0';
            } else {
                result.append(count, c);
                count = 0;
            }
        }
        return result;
    }
    string Encoding(const string &s) {
        string result;
        for (int i = 1, count = 1; i <= s.size(); ++i) {
            if (i == s.size() || s[i] != s[i - 1]) {
                result += to_string(count) + s[i - 1];
                count = 1;
            } else {
                ++count;
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert("4a1b3c2a" == solution.Encoding("aaaabcccaa"));
    assert("eeeffffee" == solution.Decoding("3e4f2e"));
    assert("aaaaaaaaaaffffee" == solution.Decoding("10a4f2e"));
    
    return 0;
}
