#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void ReverseWords(string& s) {
        reverse(s.begin(), s.end());
        
        size_t start = 0, end;
        while ((end = s.find(" ", start)) != string::npos) {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        reverse(s.begin() + start, s.end());
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}