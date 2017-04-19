#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool is_alphanumeric(char ch) {
        return ('0' <= ch && ch <= '9') ||
               ('a' <= tolower(ch) && tolower(ch) <= 'z');
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        for (char & ch : s) {
            if ('A' <= ch && ch <= 'Z') {
                ch = tolower(ch);
            }
        }

        while (left < right) {
            if (!is_alphanumeric(s[left])) {
                ++left;
                continue;
            }
            if (!is_alphanumeric(s[right])) {
                --right;
                continue;
            }
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(solution.isPalindrome("race a car") == false);

    return 0;
}
