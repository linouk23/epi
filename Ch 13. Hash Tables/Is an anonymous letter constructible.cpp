#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hashtable;
        for (int i = 0; i < magazine.size(); ++i)
            ++hashtable[magazine[i]];
        for (int j = 0; j < ransomNote.size(); ++j)
            if (--hashtable[ransomNote[j]] < 0)
                return false;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}