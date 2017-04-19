#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> prefix_function (const string &s) {
        int n = (int) s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; ++i) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])  ++j;
            pi[i] = j;
        }
        return pi;
    }
    
    int kmp(const string &text, const string &str) {
        string test_string = str + "#" + text;
        vector<int> pi = prefix_function(test_string);
        for (int index = 0; index < test_string.length(); ++index) {
            if (pi[index] == str.length()) {
                return index - 2 * (int) str.length();
            }
        }
        return -1;
    }
};

void SimpleTest() {
    Solution solution;
    assert(solution.kmp("GACGCCA", "CGC") == 2);
    assert(solution.kmp("GATACCCATCGAGTCGGATCGAGT", "GAG") == 10);
    assert(solution.kmp("FOOBARWIDGET", "WIDGETS") == -1);
    assert(solution.kmp("A", "A") == 0);
    assert(solution.kmp("A", "B") == -1);
    assert(solution.kmp("A", "") == 0);
    assert(solution.kmp("ADSADA", "") == 0);
    assert(solution.kmp("", "A") == -1);
    assert(solution.kmp("", "AAA") == -1);
    assert(solution.kmp("A", "AAA") == -1);
    assert(solution.kmp("AA", "AAA") == -1);
    assert(solution.kmp("AAA", "AAA") == 0);
    assert(solution.kmp("BAAAA", "AAA") == 1);
    assert(solution.kmp("BAAABAAAA", "AAA") == 1);
    assert(solution.kmp("BAABBAABAAABS", "AAA") == 8);
    assert(solution.kmp("BAABBAABAAABS", "AAAA") == -1);
    assert(solution.kmp("FOOBAR", "BAR") > 0);
}

int main() {
    ios::sync_with_stdio(false);
    
    SimpleTest();
    
    return 0;
}
