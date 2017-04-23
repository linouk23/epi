#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result, tmp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            if (tmp == "." || tmp.empty()) {
                continue;
            }

            if (tmp == ".." && !stk.empty()) {
                stk.pop_back();
            } else if (tmp != "..") {
                stk.emplace_back(tmp);
            }
        }
        for (const auto &str : stk) {
            result += "/";
            result += str;
        }

        return result.empty() ? "/" : result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.simplifyPath("/home/") == "/home");
    assert(solution.simplifyPath("/a/./b/../../c/") == "/c");

    return 0;
}
