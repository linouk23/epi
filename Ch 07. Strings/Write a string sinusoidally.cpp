#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string SnakeString(const string& s) {
        string result;
        for (int i = 1; i < s.size(); i += 4) {
            result += s[i];
        }
        for (int i = 0; i < s.size(); i += 2) {
            result += s[i];
        }
        for (int i = 3; i < s.size(); i += 4) {
            result += s[i];
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
